#ifndef PK
#include <stdlib.h>
#include <machine/dramfs_fs.h>

int dramfs_init(void);
void dramfs_exit(int exit_status);
void dramfs_sendchar(char ch);
int dramfs_getchar(void);
#endif
