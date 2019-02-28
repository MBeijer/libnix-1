#include <errno.h>
#include <stdio.h>
#include <stdlib.h> /* If you use normal file I/O,
                       the memory functions don't count that much on memory */
#include <exec/lists.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include "debuglib.h"
#include "stabs.h"

#include "__filenode.h"
extern struct MinList __filelist;

FILE *fopen(const char *filename,const char *mode)
{ struct filenode *node = (struct filenode *)calloc(1,sizeof(*node));
  if(node!=NULL)
  { if((node->theFILE._bf._base=(char *)malloc(BUFSIZ))!=NULL)
    { node->theFILE._bf._size=BUFSIZ;
      node->theFILE._flags|=__SMBF|__SLBF; /* Buffer is malloc'ed */
      node->theFILE.file = -1;
      if(freopen(filename,mode,&node->theFILE)!=NULL)
      { AddHead((struct List *)&__filelist,(struct Node *)&node->node);
        return &node->theFILE; }
      free(node->theFILE._bf._base);
    }
    else
      errno=ENOMEM;
    free(node);
  }
  else
    errno=ENOMEM;
  return NULL;
}
