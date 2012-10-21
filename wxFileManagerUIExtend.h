#ifndef WXFILEMANAGERUIEXTEND_H_INCLUDED
#define WXFILEMANAGERUIEXTEND_H_INCLUDED

#include "wxFileManagerMain.h"

class FileListCtrl : public wxListCtrl
{
    public:
        FileListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style) {};
        ~FileListCtrl() {};

        wxString OnGetItemText(long item, long column) const;
};

#endif // WXFILEMANAGERUIEXTEND_H_INCLUDED
