#include "wxFileManagerUI.h"

void wxFileManagerUI::ShowSearchDialog(wxCommandEvent& event)
{
    SearchDialog search_dialog(this);
    search_dialog.ShowModal();
}

void wxFileManagerUI::ShowAboutDialog(wxCommandEvent& event)
{
    AboutDialog about_dialog(this);
    about_dialog.ShowModal();
}


/////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////
void SearchDialog::ChangeOptionType( wxCommandEvent& event )
{
    if(!m_panel_more->IsShown())
    {
        m_panel_more->Show(true);
    }
    else
    {
        m_panel_more->Show(false);
    }

    this->SetSize(wxDefaultCoord, wxDefaultCoord, wxDefaultCoord, wxDefaultCoord, wxSIZE_AUTO);
}
