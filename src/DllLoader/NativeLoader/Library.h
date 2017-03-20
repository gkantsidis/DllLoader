#pragma once

#include <Windows.h>
#include <assert.h>
#include <string>
#include "LoaderException.h"

namespace Loader
{


#define DEFINE_C_FUNCTION_0 (Name, ReturnType) \
    CFunction0<Name, ReturnType> Name

class InvalidFunctionException
    : LoaderException
{
    
};

template<typename functionReturnType>
    struct CFunction0
{
        using Function_t = functionReturnType (*)(void);

    CFunction0(const HMODULE& module, const std::string & function)
        : _module(module)
        , _functionName(function)
        , _function(GetFunction(_module, _functionName))
    {
        assert(nullptr != _module);
        if (nullptr == _function)
        {
            throw InvalidFunctionException();
        }
    }

    functionReturnType operator()()
    {
        auto result = _function();
        return result;
    }

private:
    static Function_t GetFunction(const HMODULE& module, const std::string & function)
    {
        auto fn = Function_t(GetProcAddress(module, function.c_str()));
        return fn;
    }

private:
    const HMODULE _module;
    const std::string _functionName;
    const Function_t _function;
};

template<typename functionReturnType, typename... Arguments>
    struct CFunction
    {
        using Function_t = functionReturnType(*)(Arguments...);

        CFunction(const HMODULE& module, const std::string & function)
            : _module(module)
            , _functionName(function)
            , _function(GetFunction(_module, _functionName))
        {
            assert(nullptr != _module);
            if (nullptr == _function)
            {
                throw InvalidFunctionException();
            }
        }

        functionReturnType operator()(Arguments... params)
        {
            auto result = _function(params...);
            return result;
        }

    private:
        static Function_t GetFunction(const HMODULE& module, const std::string & function)
        {
            auto fn = Function_t(GetProcAddress(module, function.c_str()));
            return fn;
        }

    private:
        const HMODULE _module;
        const std::string _functionName;
        const Function_t _function;
    };

class Library
{
public:
    Library(const std::string& filename);
    virtual ~Library();

protected:
    HMODULE Module() const;

private:
    const std::string _filename;
    const HMODULE _module;
};

}
