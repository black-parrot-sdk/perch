#ifndef CONFIG_H
#define CONFIG_H

//
// This file MUST be kept in sync with black-parrot/bp_common/src/include/bp_common_cfg_bus_pkgdef.svh

#define CONFIG_BASE_ADDR 0x200000

#define CONFIG_REG_UNUSED                  (CONFIG_BASE_ADDR | 0x00004)
#define CONFIG_REG_FREEZE                  (CONFIG_BASE_ADDR | 0x00008)
#define CONFIG_REG_CORE_ID                 (CONFIG_BASE_ADDR | 0x0000c)
#define CONFIG_REG_DID                     (CONFIG_BASE_ADDR | 0x00010)
#define CONFIG_REG_CORD                    (CONFIG_BASE_ADDR | 0x00014)
#define CONFIG_REG_HOST_DID                (CONFIG_BASE_ADDR | 0x00018)
#define CONFIG_REG_HIO_MASK                (CONFIG_BASE_ADDR | 0x0001c)
#define CONFIG_REG_ICACHE_ID               (CONFIG_BASE_ADDR | 0x00200)
#define CONFIG_REG_ICACHE_MODE             (CONFIG_BASE_ADDR | 0x00204)
#define CONFIG_REG_DCACHE_ID               (CONFIG_BASE_ADDR | 0x00400)
#define CONFIG_REG_DCACHE_MODE             (CONFIG_BASE_ADDR | 0x00404)
#define CONFIG_REG_CCE_ID                  (CONFIG_BASE_ADDR | 0x00600)
#define CONFIG_REG_CCE_MODE                (CONFIG_BASE_ADDR | 0x00604)
#define CONFIG_REG_CCE_UCODE_START         (CONFIG_BASE_ADDR | 0x08000)
#define CONFIG_REG_CCE_UCODE_BASE          CONFIG_REG_CCE_UCODE_START
#define CONFIG_REG_CCE_UCODE_END           (CONFIG_BASE_ADDR | 0x08FFC)

#endif

