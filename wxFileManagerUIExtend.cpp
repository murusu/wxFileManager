#include "wxFileManagerUIExtend.h"

wxString FileListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("test");
/*
    switch(column)
    {
        case FILE_NAME:
            ItemText = wxGetApp().GetFileManager()->getFileName(item);
            break;

        case FILE_PATH:
            ItemText = wxGetApp().GetFileManager()->getFilePath(item);
            break;

        case FILE_TYPE:
            ItemText = wxGetApp().GetFileManager()->getFileModifyDate(item);
            break;
    }
*/
    return ItemText;
}
