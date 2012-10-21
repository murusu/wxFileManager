///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxFileManagerUIExtend.h"

#include "wxFileManagerUIBase.h"

///////////////////////////////////////////////////////////////////////////

wxFileManagerUIBase::wxFileManagerUIBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_menubar = new wxMenuBar( 0 );
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem_search;
	m_menuItem_search = new wxMenuItem( m_menu3, wxID_Menu_Search, wxString( _("Search") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem_search );
	
	wxMenuItem* m_menuItem_stopsearch;
	m_menuItem_stopsearch = new wxMenuItem( m_menu3, wxID_Menu_StopSearch, wxString( _("Stop Searching") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem_stopsearch );
	m_menuItem_stopsearch->Enable( false );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem_addtolist;
	m_menuItem_addtolist = new wxMenuItem( m_menu3, wxID_Menu_AddToList, wxString( _("Add Files To List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem_addtolist );
	
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Remove Files From List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem9 );
	m_menuItem9->Enable( false );
	
	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Clear List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem10 );
	m_menuItem10->Enable( false );
	
	wxMenuItem* m_separator3;
	m_separator3 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Save List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem11 );
	m_menuItem11->Enable( false );
	
	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Load LIst") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem12 );
	
	wxMenuItem* m_separator4;
	m_separator4 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem_exit;
	m_menuItem_exit = new wxMenuItem( m_menu3, wxID_Menu_Exit, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem_exit );
	
	m_menubar->Append( m_menu3, _("File") ); 
	
	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem14;
	m_menuItem14 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Copy Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem14 );
	m_menuItem14->Enable( false );
	
	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Move Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem15 );
	m_menuItem15->Enable( false );
	
	wxMenuItem* m_menuItem16;
	m_menuItem16 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Delete Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem16 );
	m_menuItem16->Enable( false );
	
	wxMenuItem* m_separator5;
	m_separator5 = m_menu4->AppendSeparator();
	
	wxMenuItem* m_menuItem17;
	m_menuItem17 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Rename Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem17 );
	m_menuItem17->Enable( false );
	
	wxMenuItem* m_separator6;
	m_separator6 = m_menu4->AppendSeparator();
	
	wxMenuItem* m_menuItem18;
	m_menuItem18 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Modify Text File Content") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem18 );
	m_menuItem18->Enable( false );
	
	wxMenuItem* m_menuItem19;
	m_menuItem19 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Modify Audio FIle Tags") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem19 );
	m_menuItem19->Enable( false );
	
	m_menubar->Append( m_menu4, _("Operation") ); 
	
	m_menu6 = new wxMenu();
	wxMenuItem* m_menuItem20;
	m_menuItem20 = new wxMenuItem( m_menu6, wxID_ANY, wxString( _("Setting") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu6->Append( m_menuItem20 );
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem22;
	m_menuItem22 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("English") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem22 );
	m_menuItem22->Check( true );
	
	m_menu6->Append( -1, _("Lanague"), m_menu2 );
	
	m_menubar->Append( m_menu6, _("Option") ); 
	
	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItem_about;
	m_menuItem_about = new wxMenuItem( m_menu5, wxID_Menu_About, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem_about );
	
	m_menubar->Append( m_menu5, _("Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl2 = new FileListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	bSizer78->Add( m_listCtrl2, 0, wxALL|wxEXPAND, 0 );
	
	this->SetSizer( bSizer78 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxID_Menu_Search, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUIBase::ShowSearchDialog ) );
	this->Connect( wxID_Menu_Exit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUIBase::ExitProgram ) );
	this->Connect( wxID_Menu_About, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUIBase::ShowAboutDialog ) );
}

wxFileManagerUIBase::~wxFileManagerUIBase()
{
	// Disconnect Events
	this->Disconnect( wxID_Menu_Search, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUIBase::ShowSearchDialog ) );
	this->Disconnect( wxID_Menu_Exit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUIBase::ExitProgram ) );
	this->Disconnect( wxID_Menu_About, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUIBase::ShowAboutDialog ) );
	
}

AboutDialogBase::AboutDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, _("wxFileManager"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( 14, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer20->Add( m_staticText6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizer19->Add( bSizer20, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, _("Version 0.15"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer21->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizer19->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("This program is licensed under the terms\nof the GNU General Public License version 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer22->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizer19->Add( bSizer22, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Author:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText11->Wrap( -1 );
	bSizer31->Add( m_staticText11, 0, wxALL, 5 );
	
	bSizer29->Add( bSizer31, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("murusu"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText13->Wrap( -1 );
	bSizer32->Add( m_staticText13, 0, wxALL, 5 );
	
	bSizer29->Add( bSizer32, 0, wxEXPAND, 5 );
	
	bSizer23->Add( bSizer29, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("E-mail:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText12->Wrap( -1 );
	bSizer33->Add( m_staticText12, 0, wxALL, 5 );
	
	bSizer30->Add( bSizer33, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("mururu0.0@gmail.com"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText14->Wrap( -1 );
	bSizer34->Add( m_staticText14, 0, wxALL, 5 );
	
	bSizer30->Add( bSizer34, 0, wxEXPAND, 5 );
	
	bSizer23->Add( bSizer30, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer19->Add( bSizer23, 0, wxEXPAND, 5 );
	
	
	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	m_button5 = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_button5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizer19->Add( bSizer24, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AboutDialogBase::CloseDialog ), NULL, this );
}

AboutDialogBase::~AboutDialogBase()
{
	// Disconnect Events
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AboutDialogBase::CloseDialog ), NULL, this );
	
}

SearchDialogBase::SearchDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );
	
	m_panel_base = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( m_panel_base, wxID_ANY, _("Search Path:"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer54->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl4 = new wxTextCtrl( m_panel_base, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer54->Add( m_textCtrl4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button10 = new wxButton( m_panel_base, wxID_ANY, _("Browser"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	bSizer54->Add( m_button10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer59->Add( bSizer54, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox31 = new wxCheckBox( m_panel_base, wxID_ANY, _("File Name Include"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer55->Add( m_checkBox31, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl5 = new wxTextCtrl( m_panel_base, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer55->Add( m_textCtrl5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer59->Add( bSizer55, 0, wxEXPAND, 5 );
	
	m_panel_base->SetSizer( bSizer59 );
	m_panel_base->Layout();
	bSizer59->Fit( m_panel_base );
	bSizer53->Add( m_panel_base, 0, wxEXPAND | wxALL, 5 );
	
	m_panel_more = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_more->Hide();
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_modifydate = new wxCheckBox( m_panel_more, wxID_ANY, _("Modify Date"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer6->Add( m_checkBox_modifydate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_modifydateChoices[] = { _("Before"), _("After"), _("Between") };
	int m_choice_modifydateNChoices = sizeof( m_choice_modifydateChoices ) / sizeof( wxString );
	m_choice_modifydate = new wxChoice( m_panel_more, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_modifydateNChoices, m_choice_modifydateChoices, 0 );
	m_choice_modifydate->SetSelection( 0 );
	m_choice_modifydate->Enable( false );
	
	bSizer6->Add( m_choice_modifydate, 0, wxALL, 5 );
	
	m_datePicker_md_first = new wxDatePickerCtrl( m_panel_more, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_md_first->Enable( false );
	
	bSizer6->Add( m_datePicker_md_first, 0, wxALL, 5 );
	
	m_datePicker_md_last = new wxDatePickerCtrl( m_panel_more, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_md_last->Enable( false );
	
	bSizer6->Add( m_datePicker_md_last, 0, wxALL, 5 );
	
	bSizer63->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_createdate = new wxCheckBox( m_panel_more, wxID_ANY, _("Create Date"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer16->Add( m_checkBox_createdate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_createdateChoices[] = { _("Before"), _("After"), _("Between") };
	int m_choice_createdateNChoices = sizeof( m_choice_createdateChoices ) / sizeof( wxString );
	m_choice_createdate = new wxChoice( m_panel_more, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_createdateNChoices, m_choice_createdateChoices, 0 );
	m_choice_createdate->SetSelection( 0 );
	m_choice_createdate->Enable( false );
	
	bSizer16->Add( m_choice_createdate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_datePicker_cd_first = new wxDatePickerCtrl( m_panel_more, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_cd_first->Enable( false );
	
	bSizer16->Add( m_datePicker_cd_first, 0, wxALL, 5 );
	
	m_datePicker_cd_last = new wxDatePickerCtrl( m_panel_more, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_cd_last->Enable( false );
	
	bSizer16->Add( m_datePicker_cd_last, 0, wxALL, 5 );
	
	bSizer63->Add( bSizer16, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_includesub = new wxCheckBox( m_panel_more, wxID_ANY, _("Include Sub Directory"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer18->Add( m_checkBox_includesub, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText5 = new wxStaticText( m_panel_more, wxID_ANY, _("Search Depth:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText5->Wrap( -1 );
	bSizer18->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_spinCtrl_depth = new wxSpinCtrl( m_panel_more, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 255, 1 );
	m_spinCtrl_depth->Enable( false );
	
	bSizer18->Add( m_spinCtrl_depth, 0, wxALL, 5 );
	
	bSizer63->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_checkBox_includehide = new wxCheckBox( m_panel_more, wxID_ANY, _("Include Hidden"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_checkBox_includehide, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer63->Add( bSizer8, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox29 = new wxCheckBox( m_panel_more, wxID_ANY, _("Search Files"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox29->SetValue(true); 
	bSizer77->Add( m_checkBox29, 0, wxALL, 5 );
	
	m_checkBox30 = new wxCheckBox( m_panel_more, wxID_ANY, _("Search Diretory"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer77->Add( m_checkBox30, 0, wxALL, 5 );
	
	bSizer63->Add( bSizer77, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox28 = new wxCheckBox( m_panel_more, wxID_ANY, _("Search File Text"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer76->Add( m_checkBox28, 0, wxALL, 5 );
	
	m_textCtrl6 = new wxTextCtrl( m_panel_more, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,50 ), wxTE_MULTILINE );
	bSizer76->Add( m_textCtrl6, 0, wxALL, 5 );
	
	bSizer63->Add( bSizer76, 0, wxEXPAND, 5 );
	
	m_panel_more->SetSizer( bSizer63 );
	m_panel_more->Layout();
	bSizer63->Fit( m_panel_more );
	bSizer53->Add( m_panel_more, 0, wxEXPAND | wxALL, 5 );
	
	m_panel_button = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer56->Add( 170, 0, 0, 0, 5 );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button11 = new wxButton( m_panel_button, wxID_ANY, _("More Option"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	bSizer57->Add( m_button11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button12 = new wxButton( m_panel_button, wxID_ANY, _("Search"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	bSizer57->Add( m_button12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button13 = new wxButton( m_panel_button, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	bSizer57->Add( m_button13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer56->Add( bSizer57, 0, 0, 5 );
	
	m_panel_button->SetSizer( bSizer56 );
	m_panel_button->Layout();
	bSizer56->Fit( m_panel_button );
	bSizer53->Add( m_panel_button, 0, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer53 );
	this->Layout();
	bSizer53->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_checkBox_modifydate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeModifyDateStatus ), NULL, this );
	m_choice_modifydate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialogBase::ChangeModifyDateType ), NULL, this );
	m_checkBox_createdate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeCreateDateStatus ), NULL, this );
	m_choice_createdate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialogBase::ChangeCreateDateType ), NULL, this );
	m_checkBox_includesub->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeSubDirStatus ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeOptionType ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialogBase::CloseDialog ), NULL, this );
}

SearchDialogBase::~SearchDialogBase()
{
	// Disconnect Events
	m_checkBox_modifydate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeModifyDateStatus ), NULL, this );
	m_choice_modifydate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialogBase::ChangeModifyDateType ), NULL, this );
	m_checkBox_createdate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeCreateDateStatus ), NULL, this );
	m_choice_createdate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialogBase::ChangeCreateDateType ), NULL, this );
	m_checkBox_includesub->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeSubDirStatus ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialogBase::ChangeOptionType ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialogBase::CloseDialog ), NULL, this );
	
}
