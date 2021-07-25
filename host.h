#ifndef HOST_H
#define HOST_H

// This file MUST be kept in sync with black-parrot/bp_common/src/include/bp_common_host_pkgdef.svh
#define HOST_DEV_BASE_ADDR 0x00100000

#define GETCHAR_BASE_ADDR           (HOST_DEV_BASE_ADDR | 0x00000)
#define PUTCHAR_BASE_ADDR           (HOST_DEV_BASE_ADDR | 0x01000)
#define FINISH_BASE_ADDR            (HOST_DEV_BASE_ADDR | 0x02000)
#define PUTCH_CORE_BASE_ADDR        (HOST_DEV_BASE_ADDR | 0x03000)
#define BOOTROM_BASE_ADDR           (HOST_DEV_BASE_ADDR | 0x10000)

#endif

