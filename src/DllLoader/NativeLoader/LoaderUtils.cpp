#include "stdafx.h"
#include "FileUtilities.h"
#include "LoaderUtils.h"

namespace Loader
{

HMODULE LoaderUtils::Load(const std::string & filename)
{
    if (!FileUtilities::IsValidFile(filename))
    {
        throw InvalidFileException(filename);
    }

    DWORD flags = LOAD_LIBRARY_SEARCH_DEFAULT_DIRS;
    auto module = LoadLibraryEx(FileUtilities::GetFullNameAsTChar(filename), NULL, flags);
    if (nullptr == module)
    {
        auto error = GetLastError();
        throw LoadFailException(filename, error);
    }
}

void LoaderUtils::UnLoad(const HMODULE & hmodule)
{
    if (nullptr == hmodule)
    {
        return;
    }

    auto success = FreeLibrary(hmodule);
    if (success == 0)
    {
        auto error = GetLastError();
        UnloadFailException(hmodule, error);
    }
}

}
