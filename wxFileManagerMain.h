#ifndef WXFILEMANAGERMAIN_H_INCLUDED
#define WXFILEMANAGERMAIN_H_INCLUDED

#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>

#include "GlobalValue.h"
#include "wxFileManagerUI.h"
#include "wxFileManagerUIExtend.h"

class wxFileManagerUI;

class wxFileManagerApp: public wxApp
{
    private:
        wxLocale                *m_locale;
        wxFileManagerUI         *m_appui;
        //FileManager             *m_filemanager;

    public:
        bool    OnInit(void);
        int     OnExit(void);
        void    SetupLocale();
        //FileManager* GetFileManager();
        inline wxFileManagerUI* GetAppUI() {return m_appui;};
};

#endif // WXFILEMANAGERMAIN_H_INCLUDED
