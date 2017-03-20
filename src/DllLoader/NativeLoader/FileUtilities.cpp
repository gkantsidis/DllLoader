#include "stdafx.h"
#include "FileUtilities.h"

#define MAX_PATH_AND_FILENAME 8192

namespace Loader
{

using namespace std;
using namespace std::experimental;

bool FileUtilities::IsValidFile(const string& filename)
{
    return filesystem::exists(filename)
        && filesystem::is_regular_file(filename);
}

std::wstring      ToStringW(const std::string& strText)
{
    std::wstring      wstrResult;
    wstrResult.resize(strText.length());
    typedef std::codecvt<wchar_t, char, mbstate_t> widecvt;
    std::locale     locGlob;
    std::locale::global(locGlob);
    const widecvt& cvt(std::use_facet<widecvt>(locGlob));
    mbstate_t   State;
    const char*       cTemp;
    wchar_t*    wTemp;
    cvt.in(State,
        &strText[0], &strText[0] + strText.length(), cTemp,
        (wchar_t*)&wstrResult[0], &wstrResult[0] + wstrResult.length(), wTemp);

    return wstrResult;
}

static FileUtilities::Path GetPathInternal(const LPCWCHAR filename)
{
    FileUtilities::Path empty = "";

    DWORD retval = 0;
    TCHAR buffer[MAX_PATH_AND_FILENAME] = TEXT("");
    TCHAR** lppPart = { nullptr };

    retval = GetFullPathName(
        filename,
        MAX_PATH_AND_FILENAME,
        buffer,
        lppPart
    );

    if (retval == 0)
    {
        throw InvalidFileException(filename);
    }
    else
    {
        FileUtilities::Path result = buffer;
        return result;
    }
}

static std::unique_ptr<TCHAR> GetPathInternalAsTChar(const LPCWCHAR filename)
{
    FileUtilities::Path empty = "";

    DWORD retval = 0;
    auto buffer = make_unique<TCHAR>(MAX_PATH_AND_FILENAME);
    memset(buffer.get(), 0x00, MAX_PATH_AND_FILENAME * sizeof(TCHAR));
    TCHAR** lppPart = { nullptr };

    retval = GetFullPathName(
        filename,
        MAX_PATH_AND_FILENAME,
        buffer.get(),
        lppPart
    );

    if (retval == 0)
    {
        throw InvalidFileException(filename);
    }
    else
    {
        return buffer;
    }
}

FileUtilities::Path FileUtilities::GetFullName(const std::string& filename)
{
    FileUtilities::Path fn = filename;
    return GetPathInternal(fn.wstring().c_str());
}

std::unique_ptr<WCHAR> FileUtilities::GetFullNameAsTChar(const std::string & filename)
{
    FileUtilities::Path fn = filename;
    return GetPathInternalAsTChar(fn.wstring().c_str());
}

FileUtilities::Path FileUtilities::GetParentDirectory(const string& filename)
{

    FileUtilities::Path fn = filename;
    auto path = GetPathInternal(fn.wstring().c_str());
    return path.parent_path();
}

FileUtilities::Path FileUtilities::GetDirectory(const std::string& filename)
{
    FileUtilities::Path fn = filename;
    WIN32_FILE_ATTRIBUTE_DATA attributes;
    auto status = GetFileAttributesEx(fn.wstring().c_str(), GET_FILEEX_INFO_LEVELS::GetFileExInfoStandard, &attributes);

    if (attributes.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
    {
        return GetPathInternal(fn.wstring().c_str());;
    }
    else
    {
        auto path = GetPathInternal(fn.wstring().c_str());
        return path.parent_path();
    }
}
}