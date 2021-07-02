#ifndef _STRUCTURES_INIT_H
#define _STRUCTURES_INIT_H

#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"

#define BUFFER_SIZE 1000
#define InitBuffer(Class) (Class*) malloc(sizeof(Class) * BUFFER_SIZE);

#endif /*_STRUCTURES_INIT_H*/
