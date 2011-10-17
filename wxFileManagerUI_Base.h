///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxFileManagerUI_Base__
#define __wxFileManagerUI_Base__

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
#include <wx/filepicker.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_Menu_Exit 1000
#define wxID_Menu_Search 1001
#define wxID_Menu_Clear 1002
#define wxID_Menu_Copy 1003
#define wxID_Menu_Move 1004
#define wxID_Menu_Delete 1005

///////////////////////////////////////////////////////////////////////////////
/// Class wxFileManagerUI_Base
///////////////////////////////////////////////////////////////////////////////
class wxFileManagerUI_Base : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu4;
		FileListCtrl* m_listCtrl_filelist;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ExitProgram( wxCommandEvent& event ) { event.Skip(); }
		virtual void ShowSearchDialog( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClearFileList( wxCommandEvent& event ) { event.Skip(); }
		virtual void ShowCopyMoveDialog( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void SortFileList( wxListEvent& event ) { event.Skip(); }
		virtual void ShowPopupMenu( wxListEvent& event ) { event.Skip(); }
		virtual void OpenFileByMimeType( wxListEvent& event ) { event.Skip(); }
		virtual void OnListSizeChange( wxSizeEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxFileManagerUI_Base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxFileManager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~wxFileManagerUI_Base();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SearchDialog_Base
///////////////////////////////////////////////////////////////////////////////
class SearchDialog_Base : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxDirPickerCtrl* m_dirPicker;
		wxCheckBox* m_checkBox_filename;
		wxTextCtrl* m_textCtrl_filename;
		wxCheckBox* m_checkBox_modifydate;
		wxChoice* m_choice_modifydate;
		wxDatePickerCtrl* m_datePicker_md_first;
		wxDatePickerCtrl* m_datePicker_md_last;
		wxCheckBox* m_checkBox_createdate;
		wxChoice* m_choice_createdate;
		wxDatePickerCtrl* m_datePicker_cd_first;
		wxDatePickerCtrl* m_datePicker_cd_last;
		wxCheckBox* m_checkBox_includesub;
		wxCheckBox* m_checkBox_includehide;
		wxButton* m_button2;
		wxButton* m_button3;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ChangeFileNameStatus( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeModifyDateStatus( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeModifyDateType( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeCreateDateStatus( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChangeCreateDateType( wxCommandEvent& event ) { event.Skip(); }
		virtual void DoSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void CloseSearchDialog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SearchDialog_Base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Search Setting"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,250 ), long style = wxDEFAULT_DIALOG_STYLE );
		~SearchDialog_Base();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CopyMoveDialog_Base
///////////////////////////////////////////////////////////////////////////////
class CopyMoveDialog_Base : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText3;
		wxDirPickerCtrl* m_dirPicker;
		wxStaticText* m_staticText6;
		wxChoice* m_choice_duplicate;
		wxCheckBox* m_checkBox_keepdir;
		wxGauge* m_gauge;
		wxStaticText* m_staticText_info;
		wxButton* m_button_run;
		wxButton* m_button_cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void DoAction( wxCommandEvent& event ) { event.Skip(); }
		virtual void CloseCopyMoveDialog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CopyMoveDialog_Base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Copy & Move Files"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,175 ), long style = wxCAPTION );
		~CopyMoveDialog_Base();
	
};

#endif //__wxFileManagerUI_Base__
