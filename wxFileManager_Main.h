#ifndef WXFILEMANAGER_MAIN_H_INCLUDED
#define WXFILEMANAGER_MAIN_H_INCLUDED

#include <wx/wx.h>
#include "wxFileManagerUI.h"
#include "wxFileManager_Core.h"

class wxFileManagerUI;

class wxFileManagerApp: public wxApp
{
    private:
        wxLocale                *m_locale;
        wxFileManagerUI         *m_appui;
        FileManager             *m_filemanager;

    public:
        bool    OnInit(void);
        int     OnExit(void);
        void    SetupLocale();
        FileManager* GetFileManager();
        wxFileManagerUI* GetAppUI();
};

#endif // WXFILEMANAGER_MAIN_H_INCLUDED
