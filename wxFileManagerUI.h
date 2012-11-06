#ifndef WXFILEMANAGERUI_H_INCLUDED
#define WXFILEMANAGERUI_H_INCLUDED

#include "wxFileManagerUIBase.h"
#include "wxFileManagerMain.h"

class wxFileManagerUI : public wxFileManagerUIBase
{
	protected:
		void ShowSearchDialog( wxCommandEvent& event );
		void BrowserFilesToAddList( wxCommandEvent& event );
		void ShowAboutDialog( wxCommandEvent& event );

		void OnFileListSizeChange( wxSizeEvent& event );

        inline void ExitProgram( wxCommandEvent& event ) { Close(); };

	public:
		wxFileManagerUI(wxFrame *frame);
		~wxFileManagerUI() {};
};

class SearchDialog : public SearchDialogBase
{
    protected:
        void BrowserSearchPath( wxCommandEvent& event );
		void ChangeFileNameInclude( wxCommandEvent& event );
		void ChangeModifyDateStatus( wxCommandEvent& event );
		void ChangeModifyDateType( wxCommandEvent& event );
		void ChangeCreateDateStatus( wxCommandEvent& event );
		void ChangeCreateDateType( wxCommandEvent& event );
		void ChangeSubDirStatus( wxCommandEvent& event );
		void ChangeSearchTextStatus( wxCommandEvent& event );
		void ChangeOptionType( wxCommandEvent& event );

        inline void CloseDialog( wxCommandEvent& event ) { Close(); }

    public:
        SearchDialog(wxFrame *frame):SearchDialogBase(frame) {};
		~SearchDialog() {};
};

class AboutDialog : public AboutDialogBase
{
    protected:
        inline void CloseDialog( wxCommandEvent& event ) { Close(); }

    public:
        AboutDialog(wxFrame *frame):AboutDialogBase(frame) {};
		~AboutDialog() {};
};

#endif // WXFILEMANAGERUI_H_INCLUDED
