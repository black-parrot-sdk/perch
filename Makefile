
WITH_MARCH ?= rv64gc
WITH_MABI ?= lp64d

RISCV_GCC = $(CROSS_COMPILE)gcc -fPIC -march=$(WITH_MARCH) -mabi=$(WITH_MABI) -mcmodel=medany -static -I$(BP_SDK_INCLUDE_DIR)
RISCV_AR = $(CROSS_COMPILE)ar
RISCV_RANLIB = $(CROSS_COMPILE)ranlib

.PHONY: perch

perch:
	$(RISCV_GCC) -c *.c *.S
	$(RISCV_AR) -rc libperch.a *.o
	$(RISCV_RANLIB) libperch.a
	$(RISCV_GCC) -c -DBAREMETAL *.c *.S
	$(RISCV_AR) -rc libperchbm.a *.o
	$(RISCV_RANLIB) libperchbm.a

clean:
	-rm -rf *.a
	-rm -rf *.o
