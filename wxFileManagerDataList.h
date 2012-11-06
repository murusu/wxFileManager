#ifndef WXFILEMANAGERDATALIST_H_INCLUDED
#define WXFILEMANAGERDATALIST_H_INCLUDED

#include "wxFileManagerMain.h"

class FileInfo;

WX_DECLARE_OBJARRAY(FileInfo, FileInfoArray);

class FileInfo
{
    public:
        wxString        m_name;
        wxString        m_path;
        wxULongLong     m_size;
        time_t          m_modifytime;
        time_t          m_createtime;
        size_t          m_type;
        wxString        m_tag;
        size_t          m_result;

        FileInfo(const wxString& name, const wxString& path, size_t type = FILETYPE_UNKNOWN, wxULongLong size = 0, time_t modifytime = 0, time_t createtime = 0, const wxString& tag = wxT(""), size_t result = FILERESULT_UNPROCESS);
        ~FileInfo(){};
};

class FileManager
{
    protected:
        FileInfoArray  *m_filelist;

    public:
        FileManager();
        ~FileManager();

        FileInfoArray* GetFileInfoArray() {return m_filelist;};
};


#endif // WXFILEMANAGERDATALIST_H_INCLUDED
