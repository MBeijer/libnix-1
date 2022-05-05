/* Automatically generated header (sfdc 1.11d)! Do not edit! */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined (__libnix__)

#include <stabs.h>
#ifdef __baserel__
void* MiscBase = 0;
void ** __getMiscBase() { return &MiscBase; }
static void * const __init[2] = { __getMiscBase, "misc.resource"};
ADD2LIB(__init);
#else
void* MiscBase[2] = { 0, "misc.resource" };
ADD2LIB(MiscBase);
#endif

#elif defined (__AMIGAOS4__)

#undef __USE_INLINE__
#define _NO_INLINE
#include <exec/types.h>

#include <interfaces/misc.h>
#include <proto/exec.h>
#include <assert.h>

__attribute__((weak)) struct Library * MiscBase = NULL;
__attribute__((weak)) struct MiscIFace* IMisc = NULL;

void __init_Misc(void) __attribute__((constructor));
void __exit_Misc(void) __attribute__((destructor));

void __init_Misc(void) {
  if (MiscBase == NULL) {
    MiscBase = (struct Library *) IExec->OpenLibrary("misc.resource", 0);
    assert(MiscBase != NULL);
  }
  if (IMisc == NULL) {
    IMisc = (struct MiscIFace*) IExec->GetInterface((struct Library*) MiscBase, "main", 1, NULL);
    assert(IMisc != NULL);
  }
}

void __exit_Misc(void) {
  IExec->DropInterface((struct Interface*) IMisc);
  IExec->CloseLibrary((struct Library*) MiscBase);
}


#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
