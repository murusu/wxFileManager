///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxFileManagerUI.h"

#include "wxFileManagerUI_Base.h"

///////////////////////////////////////////////////////////////////////////

wxFileManagerUI_Base::wxFileManagerUI_Base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_statusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem_savelist;
	m_menuItem_savelist = new wxMenuItem( m_menu1, wxID_Menu_SaveList, wxString( _("Save List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_savelist );
	m_menuItem_savelist->Enable( false );
	
	wxMenuItem* m_menuItem_loadlist;
	m_menuItem_loadlist = new wxMenuItem( m_menu1, wxID_Menu_LoadList, wxString( _("Load List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_loadlist );
	m_menuItem_loadlist->Enable( false );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_menu1->AppendSeparator();
	
	wxMenuItem* m_menuItem_Exit;
	m_menuItem_Exit = new wxMenuItem( m_menu1, wxID_Menu_Exit, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_Exit );
	
	m_menubar1->Append( m_menu1, _("File") ); 
	
	m_menu_search = new wxMenu();
	wxMenuItem* m_menuItem_searchall;
	m_menuItem_searchall = new wxMenuItem( m_menu_search, wxID_Menu_SearchAll, wxString( _("Search All Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_search->Append( m_menuItem_searchall );
	m_menuItem_searchall->Enable( false );
	
	wxMenuItem* m_menuItem_condsearch;
	m_menuItem_condsearch = new wxMenuItem( m_menu_search, wxID_Menu_CondSearch, wxString( _("Conditional Search") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_search->Append( m_menuItem_condsearch );
	
	m_menubar1->Append( m_menu_search, _("Search") ); 
	
	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem_removefiles;
	m_menuItem_removefiles = new wxMenuItem( m_menu4, wxID_Menu_RemoveFile, wxString( _("Remove Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_removefiles );
	m_menuItem_removefiles->Enable( false );
	
	wxMenuItem* m_menuItem_filterfile;
	m_menuItem_filterfile = new wxMenuItem( m_menu4, wxID_Menu_FilterFile, wxString( _("Filter Files") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_filterfile );
	m_menuItem_filterfile->Enable( false );
	
	wxMenuItem* m_menuItem_clearlist;
	m_menuItem_clearlist = new wxMenuItem( m_menu4, wxID_Menu_ClearList, wxString( _("Clear List") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_clearlist );
	
	wxMenuItem* m_separator1;
	m_separator1 = m_menu4->AppendSeparator();
	
	wxMenuItem* m_menuItem_copy;
	m_menuItem_copy = new wxMenuItem( m_menu4, wxID_Menu_Copy, wxString( _("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_copy );
	
	wxMenuItem* m_menuItem_move;
	m_menuItem_move = new wxMenuItem( m_menu4, wxID_Menu_Move, wxString( _("Move") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_move );
	
	wxMenuItem* m_menuItem_delete;
	m_menuItem_delete = new wxMenuItem( m_menu4, wxID_Menu_Delete, wxString( _("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_delete );
	
	wxMenuItem* m_separator5;
	m_separator5 = m_menu4->AppendSeparator();
	
	wxMenuItem* m_menuItem_rename;
	m_menuItem_rename = new wxMenuItem( m_menu4, wxID_Menu_Rename, wxString( _("Rename") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_rename );
	m_menuItem_rename->Enable( false );
	
	wxMenuItem* m_menuItem_replacecontent;
	m_menuItem_replacecontent = new wxMenuItem( m_menu4, wxID_Menu_Replace, wxString( _("Content Replace") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_replacecontent );
	
	wxMenuItem* m_separator6;
	m_separator6 = m_menu4->AppendSeparator();
	
	wxMenuItem* m_menuItem_openfile;
	m_menuItem_openfile = new wxMenuItem( m_menu4, wxID_Menu_OpenFile, wxString( _("Open File") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_openfile );
	m_menuItem_openfile->Enable( false );
	
	wxMenuItem* m_menuItem_openfolder;
	m_menuItem_openfolder = new wxMenuItem( m_menu4, wxID_Menu_OpenFolder, wxString( _("Open Folder") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem_openfolder );
	m_menuItem_openfolder->Enable( false );
	
	m_menubar1->Append( m_menu4, _("Actions") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_filelist = new FileListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_VIRTUAL );
	m_listCtrl_filelist->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer1->Add( m_listCtrl_filelist, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxID_Menu_Exit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ExitProgram ) );
	this->Connect( wxID_Menu_CondSearch, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowSearchDialog ) );
	this->Connect( wxID_Menu_ClearList, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ClearFileList ) );
	this->Connect( wxID_Menu_Copy, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowCopyMoveDialog ) );
	this->Connect( wxID_Menu_Move, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowCopyMoveDialog ) );
	this->Connect( wxID_Menu_Delete, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::DeleteFiles ) );
	this->Connect( wxID_Menu_Replace, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowContentReplaceDialog ) );
	m_listCtrl_filelist->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxFileManagerUI_Base::OnListKeyDown ), NULL, this );
	m_listCtrl_filelist->Connect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( wxFileManagerUI_Base::SortFileList ), NULL, this );
	m_listCtrl_filelist->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( wxFileManagerUI_Base::ShowPopupMenu ), NULL, this );
	m_listCtrl_filelist->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( wxFileManagerUI_Base::OpenFileByMimeType ), NULL, this );
	m_listCtrl_filelist->Connect( wxEVT_SIZE, wxSizeEventHandler( wxFileManagerUI_Base::OnListSizeChange ), NULL, this );
}

wxFileManagerUI_Base::~wxFileManagerUI_Base()
{
	// Disconnect Events
	this->Disconnect( wxID_Menu_Exit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ExitProgram ) );
	this->Disconnect( wxID_Menu_CondSearch, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowSearchDialog ) );
	this->Disconnect( wxID_Menu_ClearList, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ClearFileList ) );
	this->Disconnect( wxID_Menu_Copy, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowCopyMoveDialog ) );
	this->Disconnect( wxID_Menu_Move, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowCopyMoveDialog ) );
	this->Disconnect( wxID_Menu_Delete, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::DeleteFiles ) );
	this->Disconnect( wxID_Menu_Replace, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxFileManagerUI_Base::ShowContentReplaceDialog ) );
	m_listCtrl_filelist->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxFileManagerUI_Base::OnListKeyDown ), NULL, this );
	m_listCtrl_filelist->Disconnect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( wxFileManagerUI_Base::SortFileList ), NULL, this );
	m_listCtrl_filelist->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( wxFileManagerUI_Base::ShowPopupMenu ), NULL, this );
	m_listCtrl_filelist->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( wxFileManagerUI_Base::OpenFileByMimeType ), NULL, this );
	m_listCtrl_filelist->Disconnect( wxEVT_SIZE, wxSizeEventHandler( wxFileManagerUI_Base::OnListSizeChange ), NULL, this );
	
}

SearchDialog_Base::SearchDialog_Base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Search Path:"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText3->Wrap( -1 );
	bSizer9->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_dirPicker = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxSize( -1,-1 ), wxDIRP_CHANGE_DIR|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	bSizer9->Add( m_dirPicker, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_filename = new wxCheckBox( this, wxID_ANY, _("File Name Include"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer5->Add( m_checkBox_filename, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_filename = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_textCtrl_filename->Enable( false );
	
	bSizer5->Add( m_textCtrl_filename, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_modifydate = new wxCheckBox( this, wxID_ANY, _("Modify Date"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer6->Add( m_checkBox_modifydate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_modifydateChoices[] = { _("Before"), _("After"), _("Between") };
	int m_choice_modifydateNChoices = sizeof( m_choice_modifydateChoices ) / sizeof( wxString );
	m_choice_modifydate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_modifydateNChoices, m_choice_modifydateChoices, 0 );
	m_choice_modifydate->SetSelection( 0 );
	m_choice_modifydate->Enable( false );
	
	bSizer6->Add( m_choice_modifydate, 0, wxALL, 5 );
	
	m_datePicker_md_first = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_md_first->Enable( false );
	
	bSizer6->Add( m_datePicker_md_first, 0, wxALL, 5 );
	
	m_datePicker_md_last = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_md_last->Enable( false );
	
	bSizer6->Add( m_datePicker_md_last, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_createdate = new wxCheckBox( this, wxID_ANY, _("Create Date"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer16->Add( m_checkBox_createdate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_createdateChoices[] = { _("Before"), _("After"), _("Between") };
	int m_choice_createdateNChoices = sizeof( m_choice_createdateChoices ) / sizeof( wxString );
	m_choice_createdate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_createdateNChoices, m_choice_createdateChoices, 0 );
	m_choice_createdate->SetSelection( 0 );
	m_choice_createdate->Enable( false );
	
	bSizer16->Add( m_choice_createdate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_datePicker_cd_first = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_cd_first->Enable( false );
	
	bSizer16->Add( m_datePicker_cd_first, 0, wxALL, 5 );
	
	m_datePicker_cd_last = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	m_datePicker_cd_last->Enable( false );
	
	bSizer16->Add( m_datePicker_cd_last, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer16, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_includesub = new wxCheckBox( this, wxID_ANY, _("Include Sub Directory"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer18->Add( m_checkBox_includesub, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Search Depth:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText5->Wrap( -1 );
	bSizer18->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_spinCtrl_depth = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 255, 1 );
	m_spinCtrl_depth->Enable( false );
	
	bSizer18->Add( m_spinCtrl_depth, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_checkBox_dirbase = new wxCheckBox( this, wxID_ANY, _("Regard Leaf Directory Node as File When Date Check"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_dirbase->Enable( false );
	
	bSizer17->Add( m_checkBox_dirbase, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer17, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_checkBox_includehide = new wxCheckBox( this, wxID_ANY, _("Include Hidden"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_checkBox_includehide, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer8, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button2 = new wxButton( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button2, 0, wxALL, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button3, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_checkBox_filename->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeFileNameStatus ), NULL, this );
	m_checkBox_modifydate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeModifyDateStatus ), NULL, this );
	m_choice_modifydate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialog_Base::ChangeModifyDateType ), NULL, this );
	m_checkBox_createdate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeCreateDateStatus ), NULL, this );
	m_choice_createdate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialog_Base::ChangeCreateDateType ), NULL, this );
	m_checkBox_includesub->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeSubDirStatus ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialog_Base::DoSearch ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialog_Base::CloseSearchDialog ), NULL, this );
}

SearchDialog_Base::~SearchDialog_Base()
{
	// Disconnect Events
	m_checkBox_filename->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeFileNameStatus ), NULL, this );
	m_checkBox_modifydate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeModifyDateStatus ), NULL, this );
	m_choice_modifydate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialog_Base::ChangeModifyDateType ), NULL, this );
	m_checkBox_createdate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeCreateDateStatus ), NULL, this );
	m_choice_createdate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SearchDialog_Base::ChangeCreateDateType ), NULL, this );
	m_checkBox_includesub->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SearchDialog_Base::ChangeSubDirStatus ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialog_Base::DoSearch ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDialog_Base::CloseSearchDialog ), NULL, this );
	
}

CopyMoveDialog_Base::CopyMoveDialog_Base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Target Path:"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText3->Wrap( -1 );
	bSizer10->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_dirPicker = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	bSizer10->Add( m_dirPicker, 0, wxALL, 5 );
	
	bSizer9->Add( bSizer10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, _("When Duplicate Name:"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText6->Wrap( -1 );
	bSizer171->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_duplicateChoices[] = { _("Ask"), _("Skip"), _("Override"), _("Override When Newer"), _("Auto Rename") };
	int m_choice_duplicateNChoices = sizeof( m_choice_duplicateChoices ) / sizeof( wxString );
	m_choice_duplicate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_duplicateNChoices, m_choice_duplicateChoices, 0 );
	m_choice_duplicate->SetSelection( 0 );
	bSizer171->Add( m_choice_duplicate, 0, wxALL, 5 );
	
	bSizer9->Add( bSizer171, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_checkBox_keepdir = new wxCheckBox( this, wxID_ANY, _("Keep Directory Structure"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_checkBox_keepdir, 0, wxALL, 5 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	m_gauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,10 ), wxGA_HORIZONTAL|wxGA_SMOOTH );
	m_gauge->SetValue( 0 ); 
	bSizer13->Add( m_gauge, 0, wxALL|wxEXPAND, 5 );
	
	bSizer9->Add( bSizer13, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_info->Wrap( -1 );
	bSizer15->Add( m_staticText_info, 1, wxALL, 5 );
	
	bSizer12->Add( bSizer15, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_run = new wxButton( this, wxID_ANY, _("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button_run, 0, wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button_cancel, 0, wxALL|wxRIGHT, 5 );
	
	bSizer12->Add( bSizer16, 0, 0, 5 );
	
	bSizer9->Add( bSizer12, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer9 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_run->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyMoveDialog_Base::DoAction ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyMoveDialog_Base::CloseCopyMoveDialog ), NULL, this );
}

CopyMoveDialog_Base::~CopyMoveDialog_Base()
{
	// Disconnect Events
	m_button_run->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyMoveDialog_Base::DoAction ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyMoveDialog_Base::CloseCopyMoveDialog ), NULL, this );
	
}

ContentReplaceDialog_Base::ContentReplaceDialog_Base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, _("Original Text:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText7->Wrap( -1 );
	bSizer20->Add( m_staticText7, 0, wxALL, 5 );
	
	m_textCtrl_original = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,70 ), wxTE_MULTILINE );
	bSizer20->Add( m_textCtrl_original, 0, wxALL, 5 );
	
	bSizer19->Add( bSizer20, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, _("Replace Text:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText6->Wrap( -1 );
	bSizer21->Add( m_staticText6, 0, wxALL, 5 );
	
	m_textCtrl_replace = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,70 ), wxTE_MULTILINE );
	bSizer21->Add( m_textCtrl_replace, 0, wxALL, 5 );
	
	bSizer19->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	m_gauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,10 ), wxGA_HORIZONTAL );
	bSizer23->Add( m_gauge, 0, wxALL|wxEXPAND, 5 );
	
	bSizer19->Add( bSizer23, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_info = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_info->Wrap( -1 );
	bSizer15->Add( m_staticText_info, 1, wxALL, 5 );
	
	bSizer12->Add( bSizer15, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_run = new wxButton( this, wxID_ANY, _("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button_run, 0, wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button_cancel, 0, wxALL|wxRIGHT, 5 );
	
	bSizer12->Add( bSizer16, 0, 0, 5 );
	
	bSizer19->Add( bSizer12, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_run->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ContentReplaceDialog_Base::DoAction ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ContentReplaceDialog_Base::CloseContentReplaceDialog ), NULL, this );
}

ContentReplaceDialog_Base::~ContentReplaceDialog_Base()
{
	// Disconnect Events
	m_button_run->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ContentReplaceDialog_Base::DoAction ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ContentReplaceDialog_Base::CloseContentReplaceDialog ), NULL, this );
	
}
