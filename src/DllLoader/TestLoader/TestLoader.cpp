// TestLoader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

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

    return 0;
}

