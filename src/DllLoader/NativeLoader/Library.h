#pragma once

#include <Windows.h>
#include <string>

namespace Loader
{



class Library
{
public:
    Library(const std::string& filename);
    virtual ~Library();

private:
    const std::string _filename;
    HMODULE _module;
};

}
