/* Automatically generated header (sfdc 1.11d)! Do not edit! */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined (__libnix__)

#include <stabs.h>
#ifdef __baserel__
void* PaletteBase = 0;
void ** __getPaletteBase() { return &PaletteBase; }
static void * const __init[2] = { __getPaletteBase, "palette.library"};
ADD2LIB(__init);
#else
void* PaletteBase[2] = { 0, "palette.library" };
ADD2LIB(PaletteBase);
#endif

#elif defined (__AMIGAOS4__)

#undef __USE_INLINE__
#define _NO_INLINE
#include <intuition/intuition.h>
#include <intuition/classes.h>

#include <interfaces/palette.h>
#include <proto/exec.h>
#include <assert.h>

__attribute__((weak)) struct Library * PaletteBase = NULL;
__attribute__((weak)) struct PaletteIFace* IPalette = NULL;

void __init_Palette(void) __attribute__((constructor));
void __exit_Palette(void) __attribute__((destructor));

void __init_Palette(void) {
  if (PaletteBase == NULL) {
    PaletteBase = (struct Library *) IExec->OpenLibrary("palette.library", 0);
    assert(PaletteBase != NULL);
  }
  if (IPalette == NULL) {
    IPalette = (struct PaletteIFace*) IExec->GetInterface((struct Library*) PaletteBase, "main", 1, NULL);
    assert(IPalette != NULL);
  }
}

void __exit_Palette(void) {
  IExec->DropInterface((struct Interface*) IPalette);
  IExec->CloseLibrary((struct Library*) PaletteBase);
}


#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
