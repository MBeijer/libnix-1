/* Automatically generated header (sfdc 1.11d)! Do not edit! */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined (__libnix__)

#include <stabs.h>
#ifdef __baserel__
void* PenMapBase = 0;
void ** __getPenMapBase() { return &PenMapBase; }
static void * const __init[2] = { __getPenMapBase, "penmap.library"};
ADD2LIB(__init);
#else
void* PenMapBase[2] = { 0, "penmap.library" };
ADD2LIB(PenMapBase);
#endif

#elif defined (__AMIGAOS4__)

#undef __USE_INLINE__
#define _NO_INLINE
#include <intuition/intuition.h>
#include <intuition/classes.h>

#include <interfaces/penmap.h>
#include <proto/exec.h>
#include <assert.h>

__attribute__((weak)) struct Library * PenMapBase = NULL;
__attribute__((weak)) struct PenMapIFace* IPenMap = NULL;

void __init_PenMap(void) __attribute__((constructor));
void __exit_PenMap(void) __attribute__((destructor));

void __init_PenMap(void) {
  if (PenMapBase == NULL) {
    PenMapBase = (struct Library *) IExec->OpenLibrary("penmap.library", 0);
    assert(PenMapBase != NULL);
  }
  if (IPenMap == NULL) {
    IPenMap = (struct PenMapIFace*) IExec->GetInterface((struct Library*) PenMapBase, "main", 1, NULL);
    assert(IPenMap != NULL);
  }
}

void __exit_PenMap(void) {
  IExec->DropInterface((struct Interface*) IPenMap);
  IExec->CloseLibrary((struct Library*) PenMapBase);
}


#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
