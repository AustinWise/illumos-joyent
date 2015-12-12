// dllmain.cpp : Defines the entry point for the DLL application.

//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
//#include <windows.h>

#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
DECLARE_HANDLE(HINSTANCE);
typedef HINSTANCE HMODULE;      /* HMODULEs can be used in place of HINSTANCEs */
typedef int                 BOOL;
typedef unsigned long       DWORD;
typedef void               *LPVOID;
#define DLL_PROCESS_ATTACH   1
#define DLL_THREAD_ATTACH    2
#define DLL_THREAD_DETACH    3
#define DLL_PROCESS_DETACH   0
#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

BOOL __stdcall DllMain( HMODULE hModule,
                       DWORD   ul_reason_for_call,
                       LPVOID  lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
