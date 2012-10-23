#include "wxFileManagerDataList.h"

WX_DEFINE_OBJARRAY(FileInfoArray);

FileInfo::FileInfo(const wxString& name, const wxString& path, wxULongLong size = 0, time_t modifytime = 0, time_t createtime = 0, size_t type = FILETYPE_UNKNOWN, const wxString& tag = wxT(""), size_t result = FILERESULT_UNPROCESS)
{
    m_name          = name;
    m_path          = path;
    m_size          = size;
    m_modifytime    = modifytime;
    m_createtime    = createtime;
    m_type          = type;
    m_tag           = tag;
    m_result        = result;
}




/////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////
FileManager::FileManager()
{
    m_filelist = new FileInfoArray();
}

FileManager::~FileManager()
{
    if(m_filelist)    delete m_filelist;
}
