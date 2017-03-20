// SimpleExampleLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SimpleExampleLibrary.h"


// This is an example of an exported variable
SIMPLEEXAMPLELIBRARY_API int nSimpleExampleLibrary=0;

SIMPLEEXAMPLELIBRARY_API int fnGetOne()
{
    return 1;
}

// This is an example of an exported function.
SIMPLEEXAMPLELIBRARY_API int fnCppAdder(int left, int right)
{
    return left + right;
}

SIMPLEEXAMPLELIBRARY_API int fnCppAdderThree(int arg1, int arg2, int arg3)
{
    return arg1 + arg2 + arg3;
}

SIMPLEEXAMPLELIBRARY_API int fnAdder(int left, int right)
{
    return left + right;
}

SIMPLEEXAMPLELIBRARY_API int fnAdderThree(int arg1, int arg2, int arg3)
{
    return arg1 + arg2 + arg3;
}


// This is the constructor of a class that has been exported.
// see SimpleExampleLibrary.h for the class definition
CSimpleExampleLibrary::CSimpleExampleLibrary()
{
    return;
}
