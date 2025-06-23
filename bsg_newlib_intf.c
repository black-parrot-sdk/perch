#include "bp_utils.h"

void dramfs_exit(int code) {
    bp_finish(code);
}

void dramfs_sendchar(int ch) {
    bp_cprint(ch);
}

int dramfs_getchar(void) {
    return bp_cget();
}

