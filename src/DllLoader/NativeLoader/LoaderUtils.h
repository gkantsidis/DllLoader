#pragma once

#include <Windows.h>
#include <string>
#include "LoaderException.h"

namespace Loader
{

class LoadFailException
    : LoaderException
{
public:
    LoadFailException(const std::string& filename, DWORD error)
        : LoaderException()
        , _filename{ filename }
        , _error(error)
    {
    }

private:
    const std::string _filename;
    DWORD _error;
};

class UnloadFailException
    : LoaderException
{
public:
    UnloadFailException(HMODULE hmodule, DWORD error)
        : LoaderException()
        , _module{ hmodule }
        , _error{ error }
    {
    }

private:
    HMODULE _module;
    DWORD _error;
};

class LoaderUtils sealed
{
public:
    static HMODULE Load(const std::string& filename);
    static void UnLoad(const HMODULE& hmodule);

private:
    LoaderUtils() = delete;
};

}
