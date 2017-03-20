#include "stdafx.h"
#include "FileUtilities.h"
#include "LoaderUtils.h"
#include "Library.h"

namespace Loader
{

Library::Library(const std::string& filename)
    : _filename(filename)
{
    if (!FileUtilities::IsValidFile(filename))
    {
        throw InvalidFileException(filename);
    }

    _module = LoaderUtils::Load(filename);
    assert(nullptr != _module);
}


Library::~Library()
{
    LoaderUtils::UnLoad(this->_module);
}

}
