#include "bp_utils.h"

// BAREMETAL ifdef overrides the weak dramfs_init function such that we don't
//   need to go through filesystem initialization if we're not using this
//   feature.
#ifdef BAREMETAL
    int dramfs_fs_init() { return 0; };
    void dramfs_sendchar(char ch) { }
    int dramfs_getchar(void) { return 0; }
    void dramfs_exit(int exit_status) { bp_finish(exit_status); }
#else
    extern int dram_fs_init(void);
    void dramfs_sendchar(char ch) { bp_cprint(ch); }
    int dramfs_getchar(void) { return bp_cget(); }
    void dramfs_exit(int exit_status) { bp_finish(exit_status); }
#endif

