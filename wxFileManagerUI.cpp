#include "wxFileManagerUI.h"

DECLARE_APP(wxFileManagerApp)

/////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////
wxFileManagerUI::wxFileManagerUI(wxFrame *frame):wxFileManagerUIBase(frame)
{
    m_listCtrl_file->InsertColumn(0,_("File Name"),wxLIST_FORMAT_LEFT,80);
    m_listCtrl_file->InsertColumn(1,_("File Path"),wxLIST_FORMAT_LEFT,240);
    m_listCtrl_file->InsertColumn(2,_("File Type"),wxLIST_FORMAT_RIGHT,80);

    wxSizeEvent event;
    m_listCtrl_file->AddPendingEvent(event);
}

void wxFileManagerUI::ShowSearchDialog(wxCommandEvent& event)
{
    SearchDialog search_dialog(this);
    search_dialog.ShowModal();
}

void wxFileManagerUI::BrowserFilesToAddList( wxCommandEvent& event )
{
    wxFileDialog file_dialog(this, _("Choose a file"), wxEmptyString, wxEmptyString, wxT("*.*"), wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE );

    if(file_dialog.ShowModal() == wxID_OK)
    {
        wxArrayString files_array;
        file_dialog.GetFilenames(files_array);

        size_t files_num = files_array.GetCount();
        FileInfoArray *file_list = wxGetApp().GetFileManager()->GetFileInfoArray();

        for(size_t index = 0; index < files_num; index++)
        {
            wxFileName file_name(files_array.Item(index));
            file_list->Add(FileInfo(file_name.GetFullName(), file_name.GetPath(), FILETYPE_FILE));
        }

        m_listCtrl_file->SetItemCount(file_list->GetCount());
        m_listCtrl_file->Refresh();
    }
}

void wxFileManagerUI::ShowAboutDialog(wxCommandEvent& event)
{
    AboutDialog about_dialog(this);
    about_dialog.ShowModal();
}

void wxFileManagerUI::OnFileListSizeChange( wxSizeEvent& event )
{
    wxSize size = GetClientSize();
    m_listCtrl_file->SetSize(0, 0, size.x, size.y);
}


/////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////
void SearchDialog::BrowserSearchPath( wxCommandEvent& event )
{
    wxDirDialog dir_dialog(this, _("Choose a directory"));

    if(dir_dialog.ShowModal() == wxID_OK) m_textCtrl_path->ChangeValue(dir_dialog.GetPath());
}

void SearchDialog::ChangeFileNameInclude( wxCommandEvent& event )
{
    if(m_checkBox_filenameinclude->IsChecked())
    {
        m_textCtrl_filenameinclude->Enable(true);
    }
    else
    {
        m_textCtrl_filenameinclude->Enable(false);
    }
}

void SearchDialog::ChangeModifyDateStatus( wxCommandEvent& event )
{
    if(m_checkBox_modifydate->IsChecked())
    {
        m_choice_modifydate->Enable(true);

        wxCommandEvent event(wxEVT_COMMAND_CHOICE_SELECTED);
        m_choice_modifydate->AddPendingEvent(event);
    }
    else
    {
        m_choice_modifydate->Enable(false);
        m_datePicker_md_first->Enable(false);
        m_datePicker_md_last->Enable(false);
    }
}

void SearchDialog::ChangeModifyDateType( wxCommandEvent& event )
{
    switch(m_choice_modifydate->GetCurrentSelection())
    {
        case SEARCHDATE_BEFORE:
        case SEARCHDATE_AFTER:
            m_datePicker_md_first->Enable(true);
            m_datePicker_md_last->Enable(false);
            break;

        case SEARCHDATE_BETWEEN:
            m_datePicker_md_first->Enable(true);
            m_datePicker_md_last->Enable(true);
            break;
    }
}

void SearchDialog::ChangeCreateDateStatus( wxCommandEvent& event )
{
    if(m_checkBox_createdate->IsChecked())
    {
        m_choice_createdate->Enable(true);

        wxCommandEvent event(wxEVT_COMMAND_CHOICE_SELECTED);
        m_choice_createdate->AddPendingEvent(event);
    }
    else
    {
        m_choice_createdate->Enable(false);
        m_datePicker_cd_first->Enable(false);
        m_datePicker_cd_last->Enable(false);
    }
}

void SearchDialog::ChangeCreateDateType( wxCommandEvent& event )
{
    switch(m_choice_createdate->GetCurrentSelection())
    {
        case SEARCHDATE_BEFORE:
        case SEARCHDATE_AFTER:
            m_datePicker_cd_first->Enable(true);
            m_datePicker_cd_last->Enable(false);
            break;

        case SEARCHDATE_BETWEEN:
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

void SearchDialog::ChangeSearchTextStatus( wxCommandEvent& event )
{
    if(m_checkBox_searchtext->IsChecked())
    {
        m_textCtrl_searchtext->Enable(true);
    }
    else
    {
        m_textCtrl_searchtext->Enable(false);
    }
}

void SearchDialog::ChangeOptionType( wxCommandEvent& event )
{
    if(!m_panel_more->IsShown())
    {
        m_panel_more->Show(true);
        m_button_advbutton->SetLabel(_("Hide Advanced Option"));
    }
    else
    {
        m_panel_more->Show(false);
        m_button_advbutton->SetLabel(_("Show Advanced Option"));
    }

    this->SetSize(wxDefaultCoord, wxDefaultCoord, wxDefaultCoord, wxDefaultCoord, wxSIZE_AUTO);
}
