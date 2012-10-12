#ifndef WXFILEMANAGER_CORE_H_INCLUDED
#define WXFILEMANAGER_CORE_H_INCLUDED

#include <wx/string.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>

#include <wx/listctrl.h>
#include <wx/filename.h>
#include <wx/dir.h>
#include <wx/filefn.h>
#include <wx/textfile.h>

#include <wx/event.h>

#include "global_value.h"
#include "wxFileManagerUI.h"


class FileInfo;
class SearchInfo;
class FileManager;
class CopyMoveDialog;

WX_DECLARE_OBJARRAY(FileInfo, FileInfoArray);

class wxFileProcessEvent : public wxNotifyEvent
{
    public:
        wxFileProcessEvent(wxEventType commandType = wxEVT_NULL, int id = 0):
            wxNotifyEvent(commandType, id) {}
        wxFileProcessEvent(const wxFileProcessEvent& event):
            wxNotifyEvent(event) {}
        virtual wxEvent *Clone() const {
            return new wxFileProcessEvent(*this);
        }

    DECLARE_DYNAMIC_CLASS(wxFileProcessEvent);
};

typedef void (wxEvtHandler::*wxFileProcessEventFunction) (wxFileProcessEvent&);

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE(wxEVT_FILEPROCESS_SEARCH, 101)
    DECLARE_EVENT_TYPE(wxEVT_FILEPROCESS_SUCCESS, 102)
    DECLARE_EVENT_TYPE(wxEVT_FILEPROCESS_ERROR, 103)
    DECLARE_EVENT_TYPE(wxEVT_FILEPROCESS_UPDATE, 104)
END_DECLARE_EVENT_TYPES()

#define EVT_FILEPROCESS_SEARCH(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_FILEPROCESS_SEARCH, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxFileProcessEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_FILEPROCESS_SUCCESS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_FILEPROCESS_SUCCESS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxFileProcessEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_FILEPROCESS_ERROR(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_FILEPROCESS_ERROR, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxFileProcessEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_FILEPROCESS_UPDATE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_FILEPROCESS_UPDATE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxFileProcessEventFunction) & fn, \
    (wxObject *) NULL ),

#define wxFileProcessEventHandler(func) \
    (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(wxFileProcessEventFunction, &func)

class FileInfo
{
    public:
        wxString        m_filename;
        wxString        m_filepath;
        wxULongLong     m_filesize;
        time_t          m_modifytime;
        time_t          m_createtime;

        FileInfo(const wxString& filename, const wxString& filepath, wxULongLong filesize, time_t modifytime, time_t  m_createtime);
        ~FileInfo();
};

class SearchInfo
{
    public:
        wxString m_filename;
        time_t   m_modifytime_first;
        time_t   m_modifytime_last;
        size_t   m_modifytime_type;
        time_t   m_createtime_first;
        time_t   m_createtime_last;
        size_t   m_createtime_type;
        size_t   m_search_depth;
        bool     m_includesub;
        bool     m_includehide;
        bool     m_dirbase_search;

        SearchInfo();
        ~SearchInfo();

        void ResetSearchInfo();
};

class ActionInfo
{
    public:
        size_t   m_actiontype;
        size_t   m_actionmode;
        size_t   m_duplicatemode;
        wxString m_targetpath;
        wxString m_originaltext;
        wxString m_replacetext;

        wxDialog* m_dialog;

        ActionInfo();
        ~ActionInfo();

        void ResetActionInfo();
};

class FileDirTraverser : public wxDirTraverser
{
    public:
        FileDirTraverser(FileManager *file_manager);
        ~FileDirTraverser();

        size_t m_route;

        wxDirTraverseResult OnFile(const wxString& filename);
        wxDirTraverseResult OnDir(const wxString& WXUNUSED(dirname));
        wxDirTraverseResult OnOpenError(const wxString& WXUNUSED(dirname));

    private:
        FileInfoArray* m_fileinfoarray;
        SearchInfo*    m_searchinfo;
        wxFileName     m_filename;

        bool MatchModifyDate();
        bool MatchCreateDate();
};

class FileManager
{
    public:
        FileInfoArray  *m_filelist;
        SearchInfo     *m_searchinfo;
        ActionInfo     *m_actioninfo;
        size_t          m_sorttype;

        FileManager();
        ~FileManager();

        void SortFileList(size_t index);
        void DoSearch();
        void DoAction();
        void ClearFileList();

        SearchInfo* GetSearchInfo();
        ActionInfo* GetActionInfo();
        FileInfoArray* GetFileInfoArray();

        size_t getFileNumber();
        wxString getFileName(size_t index);
        wxString getFileSize(size_t index);
        wxString getFilePath(size_t index);
        wxString getFileModifyDate(size_t index);
        wxString getFileCreateDate(size_t index);
};

class FileSearchThread : public wxThread
{
    protected:
        FileManager *m_filemanager;

    public:
        FileSearchThread(FileManager *file_manager);

        void *Entry();
        void OnExit();
};

class FileCopyMoveThread : public wxThread
{
    protected:
        FileManager *m_filemanager;

    public:
        FileCopyMoveThread(FileManager *file_manager);

        void *Entry();
        void OnExit();
};

class FileContentReplaceThread : public wxThread
{
    protected:
        FileManager *m_filemanager;

    public:
        FileContentReplaceThread(FileManager *file_manager);

        void *Entry();
        void OnExit();
};

#endif // WXFILEMANAGER_CORE_H_INCLUDED
