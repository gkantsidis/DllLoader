// TestLoader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Library.h"

using namespace std;

class SimpleExampleLibrary
    : Loader::Library
{
public:
    SimpleExampleLibrary()
        : Library("SimpleExampleLibrary.dll")
        , GetOne(Module(), "fnGetOne")
        , CAdder(Module(), "fnAdder")
        , DecoratedAdder(Module(), "?fnCppAdder@@YAHHH@Z")
    {
    }

    Loader::CFunction0<int> GetOne;
    Loader::CFunction<int, int, int> CAdder;
    Loader::CFunction<int, int, int> DecoratedAdder;
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Provide filename");
        exit(1);
    }

    string filename = argv[1];
    cout << "Exists   : " << Loader::FileUtilities::IsValidFile(filename) << endl;
    cout << "Full name: " << Loader::FileUtilities::GetFullName(filename) << endl;
    cout << "Directory: " << Loader::FileUtilities::GetDirectory(filename) << endl;
    cout << "Parent   : " << Loader::FileUtilities::GetParentDirectory(filename) << endl;

    SimpleExampleLibrary library;
    cout << "Value from dll: " << library.GetOne() << endl;
    cout << "Add from dll  : " << library.CAdder(3, 6) << endl;
    cout << "Decorated Adder from dll  : " << library.DecoratedAdder(5, 8) << endl;

    return 0;
}

