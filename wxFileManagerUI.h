#ifndef WXFILEMANAGERUI_H_INCLUDED
#define WXFILEMANAGERUI_H_INCLUDED

#include "wxFileManagerUI_Base.h"
#include "wxFileManager_Core.h"
#include "global_value.h"

class FileListCtrl : public wxListCtrl
{
    public:
        FileListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
        ~FileListCtrl();

        wxString OnGetItemText(long item, long column) const;
};

class wxFileManagerUI : public wxFileManagerUI_Base
{
    private:
        wxMenu* m_popupmenu;

	public:
		wxFileManagerUI(wxFrame *frame);
		~wxFileManagerUI();


		//void OnChangeDir( wxFileDirPickerEvent& event );
		void OnFileProcessSearch( wxFileProcessEvent& event );
		void OnFileProcessSuccess( wxFileProcessEvent& event );
		void OnFileProcessUpdate( wxFileProcessEvent& event );

		void GetDirFileList();
		void SelectAllFile();
		void DoListSize();

		wxMenu* GetPopupMenu();
		FileListCtrl* GetListCtrl();

        void OnListSizeChange( wxSizeEvent& event );
        void ClearFileList( wxCommandEvent& event );
		void ExitProgram( wxCommandEvent& event );
		void ShowSearchDialog( wxCommandEvent& event );
		void ShowCopyMoveDialog( wxCommandEvent& event );
		void ShowPopupMenu( wxListEvent& event );
		void OnListKeyDown( wxKeyEvent& event );
		void SortFileList( wxListEvent& event );
		void OpenFileByMimeType( wxListEvent& event );
};

class SearchDialog: public SearchDialog_Base
{
	public:
		SearchDialog(wxFrame *frame);
		~SearchDialog();

		void ChangeFileNameStatus( wxCommandEvent& event );
		void ChangeModifyDateStatus( wxCommandEvent& event );
		void ChangeModifyDateType( wxCommandEvent& event );
		void ChangeCreateDateStatus( wxCommandEvent& event );
		void ChangeCreateDateType( wxCommandEvent& event );
		void ChangeSubDirStatus( wxCommandEvent& event );

		void DoSearch( wxCommandEvent& event );
		void CloseSearchDialog( wxCommandEvent& event );
};

class CopyMoveDialog: public CopyMoveDialog_Base
{
    private:
        size_t m_actiontype;

	public:
		CopyMoveDialog(wxFrame *frame);
		~CopyMoveDialog();

		void OnFileProcessSuccess( wxFileProcessEvent& event );

		void SetActionType(const size_t action_type);

		void DoAction( wxCommandEvent& event );
		void CloseCopyMoveDialog( wxCommandEvent& event );

		wxGauge* GetGauge();
};

#endif // WXFILEMANAGERUI_H_INCLUDED
