#include "wxFileManager_Main.h"
#include "wxFileManager_Core.h"
#include "wxFileManagerUI.h"

DECLARE_APP(wxFileManagerApp)

FileListCtrl::FileListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style): wxListCtrl(parent, id, pos, size, style)
{
}

FileListCtrl::~FileListCtrl()
{
}

wxString FileListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText;

    switch(column)
    {
        case FILE_NAME:
            ItemText = wxGetApp().GetFileManager()->getFileName(item);
            break;

        case FILE_SIZE:
            ItemText = wxGetApp().GetFileManager()->getFileSize(item);
            break;

        case FILE_PATH:
            ItemText = wxGetApp().GetFileManager()->getFilePath(item);
            break;

        case FILE_MODIFYDATE:
            ItemText = wxGetApp().GetFileManager()->getFileModifyDate(item);
            break;

        case FILE_CREATEDATE:
            ItemText = wxGetApp().GetFileManager()->getFileCreateDate(item);
            break;
    }

    return ItemText;
}

wxFileManagerUI::wxFileManagerUI(wxFrame *frame) : wxFileManagerUI_Base(frame)
{
    m_popupmenu = NULL;

    m_listCtrl_filelist->InsertColumn(0,_("File Name"),wxLIST_FORMAT_LEFT,80);
    m_listCtrl_filelist->InsertColumn(1,_("File Size"),wxLIST_FORMAT_RIGHT,80);
    m_listCtrl_filelist->InsertColumn(2,_("File Path"),wxLIST_FORMAT_LEFT,240);
    m_listCtrl_filelist->InsertColumn(3,_("Modify Date"),wxLIST_FORMAT_LEFT,100);
    m_listCtrl_filelist->InsertColumn(4,_("Create Date"),wxLIST_FORMAT_LEFT,100);

    this->Connect(wxEVT_FILEPROCESS_SEARCH, wxFileProcessEventHandler(wxFileManagerUI::OnFileProcessSearch));
    this->Connect(wxEVT_FILEPROCESS_SUCCESS, wxFileProcessEventHandler(wxFileManagerUI::OnFileProcessSuccess));
    this->Connect(wxEVT_FILEPROCESS_UPDATE, wxFileProcessEventHandler(wxFileManagerUI::OnFileProcessUpdate));

    DoListSize();
}

wxFileManagerUI::~wxFileManagerUI()
{
}

void wxFileManagerUI::OnListSizeChange( wxSizeEvent& event )
{
    DoListSize();
    event.Skip();
}

void wxFileManagerUI::DoListSize()
{
    wxSize size = GetClientSize();
    m_listCtrl_filelist->SetSize(0, 0, size.x, size.y);
}

void wxFileManagerUI::ClearFileList( wxCommandEvent& event )
{
    wxGetApp().GetFileManager()->ClearFileList();
}

void wxFileManagerUI::OnFileProcessSearch( wxFileProcessEvent& event )
{
    m_listCtrl_filelist->SetItemCount(0);
    m_listCtrl_filelist->Refresh();

    m_statusBar->SetStatusText(_("Total 0 Files"), 2);
    m_statusBar->SetStatusText(_("Searching files ......"), 1);

    wxGetApp().GetFileManager()->DoSearch();
}

void wxFileManagerUI::OnFileProcessSuccess( wxFileProcessEvent& event )
{
    m_listCtrl_filelist->SetItemCount(wxGetApp().GetFileManager()->getFileNumber());
    m_listCtrl_filelist->Refresh();

    m_statusBar->SetStatusText(wxString::Format(_("Total %d Files"), wxGetApp().GetFileManager()->getFileNumber()), 2);
    m_statusBar->SetStatusText(_(" "), 1);
}

void wxFileManagerUI::OnFileProcessUpdate( wxFileProcessEvent& event )
{
    m_listCtrl_filelist->SetItemCount(wxGetApp().GetFileManager()->getFileNumber());
    m_listCtrl_filelist->Refresh();

    m_statusBar->SetStatusText(wxString::Format(_("Total %d Files"), wxGetApp().GetFileManager()->getFileNumber()), 2);
    m_statusBar->SetStatusText(_("Searching files ......"), 1);
}

void wxFileManagerUI::ExitProgram(wxCommandEvent& WXUNUSED(event))
{
    Close();
}

void wxFileManagerUI::ShowSearchDialog(wxCommandEvent& WXUNUSED(event))
{
    SearchDialog *search_dialog = new SearchDialog(this);
    search_dialog->ShowModal();
}

void wxFileManagerUI::ShowCopyMoveDialog( wxCommandEvent& event )
{
    CopyMoveDialog *copymove_dialog = new CopyMoveDialog(this);

    switch(event.GetId())
    {
        case wxID_Menu_Copy:
            copymove_dialog->SetActionType(ACTION_COPY);
            break;

        case wxID_Menu_Move:
            copymove_dialog->SetActionType(ACTION_MOVE);
            break;
    }

    copymove_dialog->ShowModal();
}

void wxFileManagerUI::ShowPopupMenu( wxListEvent& event )
{
    PopupMenu(GetPopupMenu(), event.GetPoint());
}

wxMenu* wxFileManagerUI::GetPopupMenu()
{
    if(m_popupmenu) return m_popupmenu;

    m_popupmenu = new wxMenu();

    wxMenuItem* m_menuItem_copy;
	m_menuItem_copy = new wxMenuItem( m_popupmenu, wxID_Menu_Copy, wxString( _("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_popupmenu->Append( m_menuItem_copy );

	wxMenuItem* m_menuItem_move;
	m_menuItem_move = new wxMenuItem( m_popupmenu, wxID_Menu_Move, wxString( _("Move") ) , wxEmptyString, wxITEM_NORMAL );
	m_popupmenu->Append( m_menuItem_move );

	wxMenuItem* m_menuItem_delete;
	m_menuItem_delete = new wxMenuItem( m_popupmenu, wxID_Menu_Delete, wxString( _("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	m_popupmenu->Append( m_menuItem_delete );

    this->Connect( wxID_Menu_Copy, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI::ShowCopyMoveDialog ));
    this->Connect( wxID_Menu_Move, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI::ShowCopyMoveDialog ));
    this->Connect( wxID_Menu_Delete, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI::DeleteFiles ));

    return m_popupmenu;
}

FileListCtrl* wxFileManagerUI::GetListCtrl()
{
    return m_listCtrl_filelist;
}

void wxFileManagerUI::OnListKeyDown( wxKeyEvent& event )
{
    switch ( event.GetKeyCode() )
    {
        case 'a':
        case 'A':
            if(event.CmdDown()) SelectAllFile();
            break;

        default:
            event.Skip();
            break;
    }
}

void wxFileManagerUI::SelectAllFile()
{
    int file_number = wxGetApp().GetFileManager()->getFileNumber();
    for (int i = 0; i < file_number; i++)
        m_listCtrl_filelist->SetItemState(i,wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
}

void wxFileManagerUI::SortFileList( wxListEvent& event )
{
    int col = event.GetColumn();
    wxGetApp().GetFileManager()->SortFileList(col);
}

void wxFileManagerUI::OpenFileByMimeType( wxListEvent& event )
{
}

SearchDialog::SearchDialog(wxFrame *frame) : SearchDialog_Base(frame)
{
    m_dirPicker->SetPath(wxGetCwd());
}

SearchDialog::~SearchDialog()
{
}

void SearchDialog::ChangeFileNameStatus( wxCommandEvent& event )
{
    if(m_checkBox_filename->IsChecked())
    {
        m_textCtrl_filename->Enable(true);
    }
    else
    {
        m_textCtrl_filename->Enable(false);
    }
}

void SearchDialog::ChangeModifyDateStatus( wxCommandEvent& event )
{
    m_checkBox_dirbase->Enable(false);

    if(m_checkBox_modifydate->IsChecked())
    {
        m_choice_modifydate->Enable(true);

        wxCommandEvent event(wxEVT_COMMAND_CHOICE_SELECTED);
        m_choice_modifydate->AddPendingEvent(event);

        m_checkBox_dirbase->Enable(true);
    }
    else
    {
        m_choice_modifydate->Enable(false);
        m_datePicker_md_first->Enable(false);
        m_datePicker_md_last->Enable(false);

        if(m_checkBox_createdate->IsChecked()) m_checkBox_dirbase->Enable(true);
    }
}

void SearchDialog::ChangeModifyDateType( wxCommandEvent& event )
{
    switch(m_choice_modifydate->GetCurrentSelection())
    {
        case DATE_BEFORE:
        case DATE_AFTER:
            m_datePicker_md_first->Enable(true);
            m_datePicker_md_last->Enable(false);
            break;

        case DATE_BETWEEN:
            m_datePicker_md_first->Enable(true);
            m_datePicker_md_last->Enable(true);
            break;
    }
}

void SearchDialog::ChangeCreateDateStatus( wxCommandEvent& event )
{
    m_checkBox_dirbase->Enable(false);

    if(m_checkBox_createdate->IsChecked())
    {
        m_choice_createdate->Enable(true);

        wxCommandEvent event(wxEVT_COMMAND_CHOICE_SELECTED);
        m_choice_createdate->AddPendingEvent(event);

        m_checkBox_dirbase->Enable(true);
    }
    else
    {
        m_choice_createdate->Enable(false);
        m_datePicker_cd_first->Enable(false);
        m_datePicker_cd_last->Enable(false);

        if(m_checkBox_modifydate->IsChecked()) m_checkBox_dirbase->Enable(true);
    }
}

void SearchDialog::ChangeCreateDateType( wxCommandEvent& event )
{
    switch(m_choice_createdate->GetCurrentSelection())
    {
        case DATE_BEFORE:
        case DATE_AFTER:
            m_datePicker_cd_first->Enable(true);
            m_datePicker_cd_last->Enable(false);
            break;

        case DATE_BETWEEN:
            m_datePicker_cd_first->Enable(true);
            m_datePicker_cd_last->Enable(true);
            break;
    }
}

void SearchDialog::ChangeSubDirStatus( wxCommandEvent& event )
{
    if(m_checkBox_includesub->IsChecked())
    {
        m_spinCtrl_depth->Enable(true);
    }
    else
    {
        m_spinCtrl_depth->Enable(false);
    }
}

void SearchDialog::DoSearch( wxCommandEvent& event )
{
    SearchInfo *search_info = wxGetApp().GetFileManager()->GetSearchInfo();
    search_info->ResetSearchInfo();

    if(m_checkBox_filename->IsChecked()) search_info->m_filename = m_textCtrl_filename->GetValue();
    if(m_checkBox_includesub->IsChecked())  {search_info->m_includesub = true; search_info->m_search_depth = m_spinCtrl_depth->GetValue();}
    if(m_checkBox_includehide->IsChecked()) search_info->m_includehide = true;
    if(m_checkBox_dirbase->IsChecked() && (m_checkBox_modifydate->IsChecked() || m_checkBox_createdate->IsChecked())) search_info->m_dirbase_search = true;

    if(m_checkBox_modifydate->IsChecked())
    {
        search_info->m_modifytime_type = m_choice_modifydate->GetCurrentSelection();
        search_info->m_modifytime_first = m_datePicker_md_first->GetValue().GetTicks();
        if(m_choice_modifydate->GetCurrentSelection() == DATE_BETWEEN) search_info->m_modifytime_last = m_datePicker_md_last->GetValue().GetTicks();
    }

    if(m_checkBox_createdate->IsChecked())
    {
        search_info->m_createtime_type = m_choice_createdate->GetCurrentSelection();
        search_info->m_createtime_first = m_datePicker_cd_first->GetValue().GetTicks();
        if(m_choice_createdate->GetCurrentSelection() == DATE_BETWEEN) search_info->m_createtime_last = m_datePicker_cd_last->GetValue().GetTicks();
    }

    wxFileProcessEvent file_event(wxEVT_FILEPROCESS_SEARCH);
    wxGetApp().GetTopWindow()->AddPendingEvent(file_event);

    Close();
}

void SearchDialog::CloseSearchDialog( wxCommandEvent& event )
{
    Close();
}

CopyMoveDialog::CopyMoveDialog(wxFrame *frame) : CopyMoveDialog_Base(frame)
{
    m_actiontype = ACTION_COPY;

    this->Connect(wxEVT_FILEPROCESS_SUCCESS, wxFileProcessEventHandler(CopyMoveDialog::OnFileProcessSuccess));
}

CopyMoveDialog::~CopyMoveDialog()
{
}

void CopyMoveDialog::SetActionType(const size_t action_type)
{
    m_actiontype = action_type;

    switch(m_actiontype)
    {
        case ACTION_COPY:
            SetTitle(_("Copy Files"));
            break;

        case ACTION_MOVE:
            SetTitle(_("Move Files"));
            break;
    }
}

wxGauge* CopyMoveDialog::GetGauge()
{
    return m_gauge;
}

void CopyMoveDialog::DoAction( wxCommandEvent& event )
{
    ActionInfo *action_info = wxGetApp().GetFileManager()->GetActionInfo();
    action_info->ResetActionInfo();

    if(m_dirPicker->GetPath().Len())
    {
        action_info->m_targetpath       = m_dirPicker->GetPath();
        action_info->m_actiontype       = m_actiontype;
        action_info->m_duplicatemode    = m_choice_duplicate->GetCurrentSelection();
        if(m_checkBox_keepdir->IsChecked()) action_info->m_actionmode = KEEP_STRUCTURE;
        action_info->m_dialog = this;

        m_dirPicker->Enable(false);
        m_choice_duplicate->Enable(false);
        m_checkBox_keepdir->Enable(false);
        m_button_run->Enable(false);
        m_button_cancel->Enable(false);

        m_staticText_info->SetLabel(_("processing......"));

        wxGetApp().GetFileManager()->DoAction();
    }
    else
    {
        wxMessageBox(_("Target path invaild!!"), _("Error"), wxOK | wxICON_ERROR );

        m_dirPicker->Enable(true);
        m_choice_duplicate->Enable(true);
        m_checkBox_keepdir->Enable(true);
        m_button_run->Enable(true);
        m_button_cancel->Enable(true);
    }
}

void CopyMoveDialog::OnFileProcessSuccess( wxFileProcessEvent& event )
{
    m_dirPicker->Enable(true);
    m_choice_duplicate->Enable(true);
    m_checkBox_keepdir->Enable(true);
    m_button_run->Enable(true);
    m_button_cancel->Enable(true);

    m_staticText_info->SetLabel(_("File process done"));
}

void CopyMoveDialog::CloseCopyMoveDialog( wxCommandEvent& event )
{
    Close();
}

