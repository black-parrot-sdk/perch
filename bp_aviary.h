#ifndef AVIARY_H
#define AVIARY_H

//
// This file MUST be kept in sync with black-parrot/bp_common/src/include/bp_common_aviary_pkgdef.svh
// It defines a software interface to the hardware parameters available in a BP processor.
//   Currently this is implemented as a non-synth ROM in a host module, but on a real BP chip
//   this file could be in flash, some static bootrom, etc. For this reason, we don't
//   optimize for size.
//

#define PARAM_ROM_BASE_ADDR 0x120000

#define PARAM_CC_X_DIM                            ((char *)(PARAM_ROM_BASE_ADDR | 0x0000))
#define PARAM_CC_Y_DIM                            ((char *)(PARAM_ROM_BASE_ADDR | 0x0004))
#define PARAM_IC_Y_DIM                            ((char *)(PARAM_ROM_BASE_ADDR | 0x0008))
#define PARAM_MC_Y_DIM                            ((char *)(PARAM_ROM_BASE_ADDR | 0x000c))
#define PARAM_CAC_X_DIM                           ((char *)(PARAM_ROM_BASE_ADDR | 0x0010))
#define PARAM_SAC_X_DIM                           ((char *)(PARAM_ROM_BASE_ADDR | 0x0014))
#define PARAM_CACC_TYPE                           ((char *)(PARAM_ROM_BASE_ADDR | 0x0018))
#define PARAM_SACC_TYPE                           ((char *)(PARAM_ROM_BASE_ADDR | 0x001c))
#define PARAM_NUM_CCE                             ((char *)(PARAM_ROM_BASE_ADDR | 0x0020))
#define PARAM_NUM_LCE                             ((char *)(PARAM_ROM_BASE_ADDR | 0x0024))
#define PARAM_VADDR_WIDTH                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0028))
#define PARAM_PADDR_WIDTH                         ((char *)(PARAM_ROM_BASE_ADDR | 0x002c))
#define PARAM_DADDR_WIDTH                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0030))
#define PARAM_CADDR_WIDTH                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0034))
#define PARAM_ASID_WIDTH                          ((char *)(PARAM_ROM_BASE_ADDR | 0x0038))
#define PARAM_BRANCH_METADATA_FWD_WIDTH           ((char *)(PARAM_ROM_BASE_ADDR | 0x003c))
#define PARAM_BTB_TAG_WIDTH                       ((char *)(PARAM_ROM_BASE_ADDR | 0x0040))
#define PARAM_BTB_IDX_WIDTH                       ((char *)(PARAM_ROM_BASE_ADDR | 0x0044))
#define PARAM_BHT_IDX_WIDTH                       ((char *)(PARAM_ROM_BASE_ADDR | 0x0048))
#define PARAM_BHT_ROW_ELS                         ((char *)(PARAM_ROM_BASE_ADDR | 0x004c))
#define PARAM_GHIST_WIDTH                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0050))
#define PARAM_ITLB_ELS_4K                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0054))
#define PARAM_ITLB_ELS_1G                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0058))
#define PARAM_DTLB_ELS_4K                         ((char *)(PARAM_ROM_BASE_ADDR | 0x005c))
#define PARAM_DTLB_ELS_1G                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0060))
#define PARAM_ICACHE_COHERENT                     ((char *)(PARAM_ROM_BASE_ADDR | 0x0064))
#define PARAM_ICACHE_SETS                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0068))
#define PARAM_ICACHE_ASSOC                        ((char *)(PARAM_ROM_BASE_ADDR | 0x006c))
#define PARAM_ICACHE_BLOCK_WIDTH                  ((char *)(PARAM_ROM_BASE_ADDR | 0x0070))
#define PARAM_ICACHE_FILL_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x0074))
#define PARAM_DCACHE_WRITETHROUGH                 ((char *)(PARAM_ROM_BASE_ADDR | 0x0078))
#define PARAM_DCACHE_AMO_SUPPORT                  ((char *)(PARAM_ROM_BASE_ADDR | 0x007c))
#define PARAM_DCACHE_SETS                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0080))
#define PARAM_DCACHE_ASSOC                        ((char *)(PARAM_ROM_BASE_ADDR | 0x0084))
#define PARAM_DCACHE_BLOCK_WIDTH                  ((char *)(PARAM_ROM_BASE_ADDR | 0x0088))
#define PARAM_DCACHE_FILL_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x008c))
#define PARAM_ACACHE_AMO_SUPPORT                  ((char *)(PARAM_ROM_BASE_ADDR | 0x0090))
#define PARAM_ACACHE_SETS                         ((char *)(PARAM_ROM_BASE_ADDR | 0x0094))
#define PARAM_ACACHE_ASSOC                        ((char *)(PARAM_ROM_BASE_ADDR | 0x0098))
#define PARAM_ACACHE_BLOCK_WIDTH                  ((char *)(PARAM_ROM_BASE_ADDR | 0x009c))
#define PARAM_ACACHE_FILL_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x00a0))
#define PARAM_CCE_TYPE                            ((char *)(PARAM_ROM_BASE_ADDR | 0x00a4))
#define PARAM_CCE_PC_WIDTH                        ((char *)(PARAM_ROM_BASE_ADDR | 0x00a8))
#define PARAM_BEDROCK_DATA_WIDTH                  ((char *)(PARAM_ROM_BASE_ADDR | 0x00ac))
#define PARAM_L2_EN                               ((char *)(PARAM_ROM_BASE_ADDR | 0x00b0))
#define PARAM_L2_BANKS                            ((char *)(PARAM_ROM_BASE_ADDR | 0x00b4))
#define PARAM_L2_AMO_SUPPORT                      ((char *)(PARAM_ROM_BASE_ADDR | 0x00b8))
#define PARAM_L2_DATA_WIDTH                       ((char *)(PARAM_ROM_BASE_ADDR | 0x00bc))
#define PARAM_L2_SETS                             ((char *)(PARAM_ROM_BASE_ADDR | 0x00c0))
#define PARAM_L2_ASSOC                            ((char *)(PARAM_ROM_BASE_ADDR | 0x00c4))
#define PARAM_L2_BLOCK_WIDTH                      ((char *)(PARAM_ROM_BASE_ADDR | 0x00c8))
#define PARAM_L2_FILL_WIDTH                       ((char *)(PARAM_ROM_BASE_ADDR | 0x00cc))
#define PARAM_L2_OUTSTANDING_REQS                 ((char *)(PARAM_ROM_BASE_ADDR | 0x00d0))
#define PARAM_FE_QUEUE_FIFO_ELS                   ((char *)(PARAM_ROM_BASE_ADDR | 0x00d4))
#define PARAM_FE_CMD_FIFO_ELS                     ((char *)(PARAM_ROM_BASE_ADDR | 0x00d8))
#define PARAM_MULDIV_SUPPORT                      ((char *)(PARAM_ROM_BASE_ADDR | 0x00dc))
#define PARAM_FPU_SUPPORT                         ((char *)(PARAM_ROM_BASE_ADDR | 0x00e0))
#define PARAM_COMPRESSED_SUPPORT                  ((char *)(PARAM_ROM_BASE_ADDR | 0x00e4))
#define PARAM_ASYNC_COH_CLK                       ((char *)(PARAM_ROM_BASE_ADDR | 0x00e8))
#define PARAM_COH_NOC_FLIT_WIDTH                  ((char *)(PARAM_ROM_BASE_ADDR | 0x00ec))
#define PARAM_COH_NOC_CID_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x00f0))
#define PARAM_COH_NOC_LEN_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x00f4))
#define PARAM_COH_NOC_MAX_CREDITS                 ((char *)(PARAM_ROM_BASE_ADDR | 0x00f8))
#define PARAM_ASYNC_MEM_CLK                       ((char *)(PARAM_ROM_BASE_ADDR | 0x00fc))
#define PARAM_MEM_NOC_FLIT_WIDTH                  ((char *)(PARAM_ROM_BASE_ADDR | 0x0100))
#define PARAM_MEM_NOC_CID_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x0104))
#define PARAM_MEM_NOC_LEN_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x0108))
#define PARAM_MEM_NOC_MAX_CREDITS                 ((char *)(PARAM_ROM_BASE_ADDR | 0x010c))
#define PARAM_ASYNC_IO_CLK                        ((char *)(PARAM_ROM_BASE_ADDR | 0x0110))
#define PARAM_IO_NOC_FLIT_WIDTH                   ((char *)(PARAM_ROM_BASE_ADDR | 0x0114))
#define PARAM_IO_NOC_CID_WIDTH                    ((char *)(PARAM_ROM_BASE_ADDR | 0x0118))
#define PARAM_IO_NOC_DID_WIDTH                    ((char *)(PARAM_ROM_BASE_ADDR | 0x011c))
#define PARAM_IO_NOC_LEN_WIDTH                    ((char *)(PARAM_ROM_BASE_ADDR | 0x0120))
#define PARAM_IO_NOC_MAX_CREDITS                  ((char *)(PARAM_ROM_BASE_ADDR | 0x0124))

#endif

