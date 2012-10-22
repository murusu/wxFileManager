///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxFileManagerUIBase__
#define __wxFileManagerUIBase__

#include <wx/intl.h>

class FileListCtrl;

#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/spinctrl.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_Menu_Search 1000
#define wxID_Menu_StopSearch 1001
#define wxID_Menu_AddToList 1002
#define wxID_Menu_RemoveFromList 1003
#define wxID_Menu_ClearList 1004
#define wxID_Menu_Exit 1005
#define wxID_Menu_About 1006

///////////////////////////////////////////////////////////////////////////////
/// Class wxFileManagerUIBase
///////////////////////////////////////////////////////////////////////////////
class wxFileManagerUIBase : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar;
		wxMenu* m_menu3;
		wxMenu* m_menu4;
		wxMenu* m_menu6;
		wxMenu* m_menu2;
		wxMenu* m_menu5;
		FileListCtrl* m_listCtrl_file;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ShowSearchDialog( wxCommandEvent& event ) { event.Skip(); }
		virtual void BrowserFilesToAddList( wxCommandEvent& event ) { event.Skip(); }
		virtual void RemoveFilesFromList( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClearList( wxCommandEvent& event ) { event.Skip(); }
		virtual void ExitProgram( wxCommandEvent& event ) { event.Skip(); }
		virtual void ShowAboutDialog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxFileManagerUIBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxFileManager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 637,464 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~wxFileManagerUIBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDialogBase
///////////////////////////////////////////////////////////////////////////////
class AboutDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText14;
		
		wxButton* m_button5;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CloseDialog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AboutDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 287,220 ), long style = wxDEFAULT_DIALOG_STYLE );
		~AboutDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SearchDialogBase
///////////////////////////////////////////////////////////////////////////////
class SearchDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel_base;
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_path;
		wxButton* m_button10;
		wxCheckBox* m_checkBox_filenameinclude;
		wxTextCtrl* m_textCtrl_filenameinclude;
		wxPanel* m_panel_more;
		wxCheckBox* m_checkBox_modifydate;
		wxChoice* m_choice_modifydate;
		wxDatePickerCtrl* m_datePicker_md_first;
		wxDatePickerCtrl* m_datePicker_md_last;
		wxCheckBox* m_checkBox_createdate;
		wxChoice* m_choice_createdate;
		wxDatePickerCtrl* m_datePicker_cd_first;
		wxDatePickerCtrl* m_datePicker_cd_last;
		wxCheckBox* m_checkBox_includesub;
		wxStaticText* m_staticText5;
		wxSpinCtrl* m_spinCtrl_depth;
		wxCheckBox* m_checkBox_includehide;
		wxCheckBox* m_checkBox29;
		wxCheckBox* m_checkBox30;
		wxCheckBox* m_checkBox28;
		wxTextCtrl* m_textCtrl6;
		wxPanel* m_panel_button;
		
		wxButton* m_button11;
		wxButton* m_button12;
		wxButton* m_button13;
		
		// Virtual event handlers, overide them in your derived class
		virtual void BrowserSearchPath( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileNameIncludeChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeModifyDateStatus( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeModifyDateType( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeCreateDateStatus( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeCreateDateType( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeSubDirStatus( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeOptionType( wxCommandEvent& event ) { event.Skip(); }
		virtual void CloseDialog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SearchDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Search Setting"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~SearchDialogBase();
	
};

#endif //__wxFileManagerUIBase__
