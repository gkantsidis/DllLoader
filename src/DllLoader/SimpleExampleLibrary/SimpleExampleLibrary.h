// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SIMPLEEXAMPLELIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SIMPLEEXAMPLELIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SIMPLEEXAMPLELIBRARY_EXPORTS
#define SIMPLEEXAMPLELIBRARY_API __declspec(dllexport)
#else
#define SIMPLEEXAMPLELIBRARY_API __declspec(dllimport)
#endif

// This class is exported from the SimpleExampleLibrary.dll
class SIMPLEEXAMPLELIBRARY_API CSimpleExampleLibrary {
public:
    CSimpleExampleLibrary(void);
    // TODO: add your methods here.
};

extern SIMPLEEXAMPLELIBRARY_API int nSimpleExampleLibrary;

SIMPLEEXAMPLELIBRARY_API int fnCppAdder(int left, int right);
SIMPLEEXAMPLELIBRARY_API int fnCppAdderThree(int arg1, int arg2, int arg3);

EXTERN_C SIMPLEEXAMPLELIBRARY_API int fnAdder(int left, int right);
EXTERN_C SIMPLEEXAMPLELIBRARY_API int fnAdderThree(int arg1, int arg2, int arg3);

