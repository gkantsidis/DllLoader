#pragma once

#include <exception>

namespace Loader
{

class LoaderException
    : std::exception
{
public:

    LoaderException()
        : std::exception()
    {
    }

    LoaderException(const char * const &message)
        : std::exception(message)
    {
    }

    LoaderException(const char * const &message, int value)
        : std::exception(message, value)
    {
    }

    LoaderException(const exception &right)
        : std::exception(right)
    {
    }

    ~LoaderException()
    {
    }
};

}
