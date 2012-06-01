#include "wxFileManager_Main.h"
#include "wxFileManager_Core.h"

DECLARE_APP(wxFileManagerApp)
DEFINE_EVENT_TYPE(wxEVT_FILEPROCESS_SEARCH)
DEFINE_EVENT_TYPE(wxEVT_FILEPROCESS_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_FILEPROCESS_ERROR)
DEFINE_EVENT_TYPE(wxEVT_FILEPROCESS_UPDATE)
IMPLEMENT_DYNAMIC_CLASS(wxFileProcessEvent, wxNotifyEvent)

WX_DEFINE_OBJARRAY(FileInfoArray);

int CompareData(FileInfo **first, FileInfo **second)
{
    size_t sort_type = wxGetApp().GetFileManager()->m_sorttype;
    size_t result = 0;

    switch(sort_type)
    {
        case SORT_FILENAME_ASC:
            result = (**first).m_filename.Cmp((**second).m_filename);
            break;

        case SORT_FILENAME_DEC:
            result = (**second).m_filename.Cmp((**first).m_filename);
            break;

        case SORT_FILESIZE_ASC:
            if ((**first).m_filesize == (**second).m_filesize) result = 0;
            if ((**first).m_filesize > (**second).m_filesize) result = 1;
            if ((**first).m_filesize < (**second).m_filesize) result = -1;
            break;

        case SORT_FILESIZE_DEC:
            if ((**second).m_filesize == (**first).m_filesize) result = 0;
            if ((**second).m_filesize > (**first).m_filesize) result = 1;
            if ((**second).m_filesize < (**first).m_filesize) result = -1;
            break;

        case SORT_FILEPATH_ASC:
            result = (**first).m_filepath.Cmp((**second).m_filepath);
            break;

        case SORT_FILEPATH_DEC:
            result = (**second).m_filepath.Cmp((**first).m_filepath);
            break;

        case SORT_FILEMODIFYDATE_ASC:
            result = (**first).m_modifytime - (**second).m_modifytime;
            break;

        case SORT_FILEMODIFYDATE_DEC:
            result = (**second).m_modifytime - (**first).m_modifytime;
            break;

        case SORT_FILECREATEDATE_ASC:
            result = (**first).m_createtime - (**second).m_createtime;
            break;

        case SORT_FILECREATEDATE_DEC:
            result = (**second).m_createtime - (**first).m_createtime;
            break;
    }

    return result;
}


FileInfo::FileInfo(const wxString& filename, const wxString& filepath, wxULongLong filesize, time_t modifytime, time_t createtime)
{
    m_filename      = filename;
    m_filepath      = filepath;
    m_filesize      = filesize;
    m_modifytime    = modifytime;
    m_createtime    = createtime;
}

FileInfo::~FileInfo()
{
}

SearchInfo::SearchInfo()
{
    ResetSearchInfo();
}

SearchInfo::~SearchInfo()
{
}

void SearchInfo::ResetSearchInfo()
{
    m_filename = wxEmptyString;
    m_modifytime_first = 0;
    m_modifytime_last = 0;
    m_modifytime_type = DATE_BEFORE;
    m_createtime_first = 0;
    m_createtime_last = 0;
    m_createtime_type = DATE_BEFORE;
    m_includesub = false;
    m_includehide = false;
}

ActionInfo::ActionInfo()
{
    ResetActionInfo();
}

ActionInfo::~ActionInfo()
{
}

void ActionInfo::ResetActionInfo()
{
    m_actiontype    = ACTION_NONE;
    m_actionmode    = KEEP_ONEDIR;
    m_duplicatemode = ACTION_ASK;
    m_dialog        = NULL;
}

FileDirTraverser::FileDirTraverser(FileManager *file_manager) : wxDirTraverser()
{
    m_fileinfoarray = file_manager->GetFileInfoArray();
    m_searchinfo    = file_manager->GetSearchInfo();

    m_route = 0;
}

FileDirTraverser::~FileDirTraverser()
{

}

wxDirTraverseResult FileDirTraverser::OnFile(const wxString& filename)
{
    m_filename.Assign(filename);

    if(m_filename.IsFileReadable())
    {
        if(MatchModifyDate() && MatchCreateDate())
        {
            wxDateTime modify_date;
            wxDateTime create_date;

            m_filename.GetTimes(NULL, &modify_date, &create_date);
            m_fileinfoarray->Add(FileInfo(m_filename.GetFullName(), m_filename.GetPath(), m_filename.GetSize(), modify_date.GetTicks(), create_date.GetTicks()));
        }
    }
    else
    {
    }

    if(m_route > 500)
    {
        wxFileProcessEvent event(wxEVT_FILEPROCESS_UPDATE);
        wxGetApp().GetTopWindow()->AddPendingEvent(event);

        m_route = 0;
    }
    else
    {
        m_route++;
    }

    return wxDIR_CONTINUE;
}

wxDirTraverseResult FileDirTraverser::OnDir(const wxString& dirname)
{
    m_filename.Assign(dirname);

    if(m_filename.IsDirReadable())
    {
        if(MatchModifyDate() && MatchCreateDate())
        {
            wxFileName cwd_filename(wxGetCwd());

            if((m_filename.GetDirCount() - cwd_filename.GetDirCount()) > 0)
        }
    }
    else
    {
    }

    if(m_route > 500)
    {
        wxFileProcessEvent event(wxEVT_FILEPROCESS_UPDATE);
        wxGetApp().GetTopWindow()->AddPendingEvent(event);

        m_route = 0;
    }
    else
    {
        m_route++;
    }

    return wxDIR_CONTINUE;
}

wxDirTraverseResult FileDirTraverser::OnOpenError(const wxString& WXUNUSED(dirname))
{
    return wxDIR_IGNORE;
}

bool FileDirTraverser::MatchModifyDate()
{
    if(!m_searchinfo->m_modifytime_first) return true;

    time_t  file_md = m_filename.GetModificationTime().GetTicks();
    bool    result  = false;

    switch(m_searchinfo->m_modifytime_type)
    {
        case DATE_BEFORE:
            if(file_md <= m_searchinfo->m_modifytime_first) result = true;
            break;

        case DATE_AFTER:
            if(file_md >= m_searchinfo->m_modifytime_first) result = true;
            break;

        case DATE_BETWEEN:
            if((file_md >= m_searchinfo->m_modifytime_first) && (file_md <= m_searchinfo->m_modifytime_last)) result = true;
            break;
    }

    return result;
}

bool FileDirTraverser::MatchCreateDate()
{
    if(!m_searchinfo->m_createtime_first) return true;

    wxDateTime create_date;

    m_filename.GetTimes(NULL, NULL, &create_date);

    time_t  file_cd = create_date.GetTicks();
    bool    result  = false;

    switch(m_searchinfo->m_createtime_type)
    {
        case DATE_BEFORE:
            if(file_cd <= m_searchinfo->m_createtime_first) result = true;
            break;

        case DATE_AFTER:
            if(file_cd >= m_searchinfo->m_createtime_first) result = true;
            break;

        case DATE_BETWEEN:
            if((file_cd >= m_searchinfo->m_createtime_first) && (file_cd <= m_searchinfo->m_createtime_last)) result = true;
            break;
    }

    return result;
}


FileSearchThread::FileSearchThread(FileManager *file_manager) : wxThread()
{
    m_filemanager = file_manager;
}


void FileSearchThread::OnExit()
{
}

void *FileSearchThread::Entry()
{
    wxArrayString files;
    FileDirTraverser traverser(m_filemanager);

    m_filemanager->m_filelist->Clear();

    wxDir dir(wxGetCwd());
    wxString filespec = wxEmptyString;
    size_t flags = wxDIR_FILES;
    SearchInfo* search_info = m_filemanager->GetSearchInfo();

    if(m_filemanager->GetSearchInfo())
    {
        if(search_info->m_filename) filespec = wxT("*") + search_info->m_filename + wxT("*");
        if(search_info->m_includesub) flags = flags|wxDIR_DIRS;
        if(search_info->m_includehide) flags = flags|wxDIR_HIDDEN;
    }

    dir.Traverse(traverser, filespec, flags);

    wxFileProcessEvent event(wxEVT_FILEPROCESS_SUCCESS);
    wxGetApp().GetTopWindow()->AddPendingEvent(event);

    return NULL;
}

FileCopyMoveThread::FileCopyMoveThread(FileManager *file_manager) : wxThread()
{
    m_filemanager = file_manager;
}

void FileCopyMoveThread::OnExit()
{
}

void *FileCopyMoveThread::Entry()
{
    ActionInfo* action_info = m_filemanager->GetActionInfo();

    FileInfoArray* filelist = m_filemanager->m_filelist;
    FileListCtrl* listctrl = wxGetApp().GetAppUI()->GetListCtrl();

    size_t total_num = listctrl->GetSelectedItemCount();

    if(total_num < 1)
    {
        wxFileProcessEvent event(wxEVT_FILEPROCESS_SUCCESS);
        action_info->m_dialog->AddPendingEvent(event);

        wxMessageBox(_("No item selected!"), _("Error"), wxOK | wxICON_ERROR );
        return NULL;
    }

    wxString sourefile_name;
    wxString targetfile_name;
    size_t contin_flag;

    long item_index = -1;
    for (size_t i = 0; i < total_num; i++)
    {
        item_index = listctrl->GetNextItem(item_index, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

        FileInfo file_info(filelist->Item(item_index));

        sourefile_name = file_info.m_filepath + wxT("/") + file_info.m_filename;
        targetfile_name = action_info->m_targetpath + wxT("/") + file_info.m_filename;

        if(action_info->m_actionmode == KEEP_STRUCTURE)
        {
            wxString newpath = action_info->m_targetpath + wxT("/") + file_info.m_filepath.Mid(0, 1) + file_info.m_filepath.Mid(2);
            if (!wxDirExists(newpath)) wxFileName::Mkdir(newpath, 0777, wxPATH_MKDIR_FULL);

            targetfile_name = newpath + wxT("/") + file_info.m_filename;
        }

        contin_flag = true;

        if(wxFileExists(targetfile_name))
        {
            switch(action_info->m_duplicatemode)
            {
                case ACTION_ASK:
                {
                    wxFileName source(sourefile_name);
                    wxFileName target(targetfile_name);

                    wxString message;
                    message = _("Replace ")+ source.GetFullName() + wxT("(") + source.GetHumanReadableSize(source.GetSize(), _("Empty File")) + wxT(")") + _(" with ") + target.GetFullName() + wxT("(") + target.GetHumanReadableSize(target.GetSize(), _("Empty File")) + wxT(") ?");

                    if(wxMessageBox(message, _("Confirm"), wxYES_NO) == wxNO) contin_flag = false;
                    break;
                }

                case ACTION_SKIP:
                    contin_flag = false;
                    break;

                case ACTION_OVERRIDENEW:
                {
                    wxFileName source(sourefile_name);
                    wxFileName target(targetfile_name);
                    if(target.GetModificationTime().GetTicks() >= source.GetModificationTime().GetTicks()) contin_flag = false;
                    break;
                }


                case ACTION_AUTORENAME:
                {
                    size_t index = 1;
                    wxFileName target(targetfile_name);
                    wxString orgin = target.GetPath() + wxT("/") + target.GetName();
                    wxString exten = target.GetExt();

                    while(wxFileExists(targetfile_name))
                    {
                        targetfile_name = orgin + wxT("(") + wxString::Format(wxT("%d"), index) + wxT(").") + exten;
                        index++;
                    }
                    break;
                }
            }
        }

        if(contin_flag)
        {
            switch(action_info->m_actiontype)
            {
                case ACTION_COPY:
                    wxCopyFile(sourefile_name, targetfile_name);
                    break;

                case ACTION_MOVE:
                    wxRenameFile(sourefile_name, targetfile_name);
                    break;
            }
        }

        action_info->m_dialog->GetGauge()->SetValue(int(((i + 1)*100)/total_num));
    }

    wxFileProcessEvent event(wxEVT_FILEPROCESS_SUCCESS);
    action_info->m_dialog->AddPendingEvent(event);

    return NULL;
}


FileManager::FileManager()
{
    m_sorttype      = SORT_NONE;
    m_searchinfo    = new SearchInfo();
    m_actioninfo    = new ActionInfo();
    m_filelist      = new FileInfoArray();
}

FileManager::~FileManager()
{
}

void FileManager::ClearFileList()
{
    m_filelist->Clear();

    wxFileProcessEvent event(wxEVT_FILEPROCESS_SUCCESS);
    wxGetApp().GetTopWindow()->AddPendingEvent(event);
}

size_t FileManager::getFileNumber()
{
    return m_filelist->GetCount();
}

wxString FileManager::getFileName(size_t index)
{
    return m_filelist->Item(index).m_filename;
}

wxString FileManager::getFileSize(size_t index)
{
    return wxFileName::GetHumanReadableSize(m_filelist->Item(index).m_filesize, _("Empty File"));
}

wxString FileManager::getFilePath(size_t index)
{
    return m_filelist->Item(index).m_filepath;
}

wxString FileManager::getFileModifyDate(size_t index)
{
    return wxDateTime(m_filelist->Item(index).m_modifytime).Format(wxT("%Y-%m-%d %H:%M:%S"));
}

wxString FileManager::getFileCreateDate(size_t index)
{
    return wxDateTime(m_filelist->Item(index).m_createtime).Format(wxT("%Y-%m-%d %H:%M:%S"));
}

void FileManager::SortFileList(size_t index)
{
    switch(index)
    {
        case SORT_FILENAME:
            if(m_sorttype == SORT_FILENAME_ASC)
            {
                m_sorttype = SORT_FILENAME_DEC;
            }
            else
            {
                m_sorttype = SORT_FILENAME_ASC;
            }
            break;

        case SORT_FILEPATH:
            if(m_sorttype == SORT_FILEPATH_ASC)
            {
                m_sorttype = SORT_FILEPATH_DEC;
            }
            else
            {
                m_sorttype = SORT_FILEPATH_ASC;
            }
            break;

        case SORT_FILESIZE:
            if(m_sorttype == SORT_FILESIZE_ASC)
            {
                m_sorttype = SORT_FILESIZE_DEC;
            }
            else
            {
                m_sorttype = SORT_FILESIZE_ASC;
            }
            break;

        case SORT_FILEMODIFYDATE:
            if(m_sorttype == SORT_FILEMODIFYDATE_ASC)
            {
                m_sorttype = SORT_FILEMODIFYDATE_DEC;
            }
            else
            {
                m_sorttype = SORT_FILEMODIFYDATE_ASC;
            }
            break;

        case SORT_FILECREATEDATE:
            if(m_sorttype == SORT_FILECREATEDATE_ASC)
            {
                m_sorttype = SORT_FILECREATEDATE_DEC;
            }
            else
            {
                m_sorttype = SORT_FILECREATEDATE_ASC;
            }
            break;
    }

    m_filelist->Sort(CompareData);

    wxFileProcessEvent event(wxEVT_FILEPROCESS_SUCCESS);
    wxGetApp().GetTopWindow()->AddPendingEvent(event);
}

SearchInfo* FileManager::GetSearchInfo()
{
    return m_searchinfo;
}

ActionInfo* FileManager::GetActionInfo()
{
    return m_actioninfo;
}

FileInfoArray* FileManager::GetFileInfoArray()
{
    return m_filelist;
}

void FileManager::DoSearch()
{
    FileSearchThread *worker_thread = new FileSearchThread(this);

    if ( worker_thread->Create() != wxTHREAD_NO_ERROR )
    {
    }
    else
    {
        worker_thread->Run();
    }

    return;
}

void FileManager::DoAction()
{
    switch(m_actioninfo->m_actiontype)
    {
        case ACTION_COPY:
        case ACTION_MOVE:
            FileCopyMoveThread *worker_thread = new FileCopyMoveThread(this);
            if ( worker_thread->Create() != wxTHREAD_NO_ERROR )
            {
            }
            else
            {
                worker_thread->Run();
            }
            break;
    }

}


