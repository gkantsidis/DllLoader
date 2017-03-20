#include "stdafx.h"
#include "FileUtilities.h"
#include "LoaderUtils.h"
#include "Library.h"

namespace Loader
{

static HMODULE GetModule(const std::string& filename)
{
    if (!FileUtilities::IsValidFile(filename))
    {
        throw InvalidFileException(filename);
    }

    auto module = LoaderUtils::Load(filename);
    return module;
}

Library::Library(const std::string& filename)
    : _filename(filename)
    , _module(GetModule(_filename))
{
    assert(nullptr != _module);
}


Library::~Library()
{
    LoaderUtils::UnLoad(this->_module);
}

HMODULE Library::Module() const
{
    return _module;
}

}
