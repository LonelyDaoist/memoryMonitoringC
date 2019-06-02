#ifndef __MEMORY_MONITOR_H_
#define __MEMORY_MONITOR_H_
#include <stdio.h>
#include <stdlib.h>
#define malloc XMALLOC
#define calloc XCALLOC
#define free XFREE

void init();
void *XMALLOC(int);
void *XCALLOC(int,int);
void XFREE(void*);

#endif
