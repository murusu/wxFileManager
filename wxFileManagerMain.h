#ifndef WXFILEMANAGERMAIN_H_INCLUDED
#define WXFILEMANAGERMAIN_H_INCLUDED

#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/event.h>
#include <wx/filename.h>

#include "GlobalValue.h"
#include "wxFileManagerDataList.h"
#include "wxFileManagerUI.h"
#include "wxFileManagerUIExtend.h"

class wxFileManagerUI;
class FileManager;

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

        inline FileManager* GetFileManager() {return m_filemanager;};
        inline wxFileManagerUI* GetAppUI() {return m_appui;};
};

#endif // WXFILEMANAGERMAIN_H_INCLUDED
