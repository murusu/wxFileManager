#ifndef WXFILEMANAGERUI_H_INCLUDED
#define WXFILEMANAGERUI_H_INCLUDED

#include "wxFileManagerUIBase.h"

class wxFileManagerUI : public wxFileManagerUIBase
{
	protected:
		void ShowSearchDialog( wxCommandEvent& event );
		void ShowAboutDialog( wxCommandEvent& event );

        inline void ExitProgram( wxCommandEvent& event ) { Close(); };


	public:
		wxFileManagerUI(wxFrame *frame):wxFileManagerUIBase(frame) {};
		~wxFileManagerUI() {};
};

class SearchDialog : public SearchDialogBase
{
    protected:
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
