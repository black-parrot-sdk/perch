#ifndef PK
#include "bp_utils.h"
#include "bsg_newlib_intf.h"

int dramfs_init(void) {
  bp_reset_counters();
#ifndef BAREMETAL
  // Init file system
  if(dramfs_fs_init() < 0)
    return -1;
#endif
  return 0;
}

void dramfs_exit(int exit_status) {
  bp_freeze_counters();
  bp_finish(exit_status);
}

void dramfs_sendchar(char ch) {
  bp_cprint(ch);
}

int dramfs_getchar(void) {
  return bp_cget();
}
#endif
