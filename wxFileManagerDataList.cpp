#include "wxFileManagerDataList.h"

WX_DEFINE_OBJARRAY(FileInfoArray);

FileInfo::FileInfo(const wxString& name, const wxString& path, size_t type, wxULongLong size, time_t modifytime, time_t createtime, const wxString& tag, size_t result)
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
