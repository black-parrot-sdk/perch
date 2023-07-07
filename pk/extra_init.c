#include <stdlib.h>
#include "file.h"

typedef void (*func_ptr) (void);

static func_ptr __extra_init_array_entry[]
  __attribute__ ((__used__, section(".init_array"), aligned(sizeof(func_ptr))))
  = { file_init };
