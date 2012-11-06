#include "wxFileManagerMain.h"

IMPLEMENT_APP(wxFileManagerApp)

bool wxFileManagerApp::OnInit(void)
{
    m_locale = NULL;
    m_appui  = NULL;
    SetupLocale();

    m_filemanager = new FileManager();

    m_appui = new wxFileManagerUI(NULL);
    m_appui->Show(true);

    return true;
}

int wxFileManagerApp::OnExit()
{
    if(m_locale)    delete m_locale;
    if(m_filemanager) delete m_filemanager;
    return 0;
}

void wxFileManagerApp::SetupLocale()
{
    m_locale = new wxLocale();
    m_locale->Init();

    m_locale->AddCatalogLookupPathPrefix(wxT("./lng"));
    m_locale->AddCatalog(m_locale->GetCanonicalName());
}
