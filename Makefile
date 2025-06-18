
WITH_MARCH ?= rv64gc
WITH_MABI ?= lp64d

RISCV_GCC = $(CROSS_COMPILE)gcc -fPIC -march=$(WITH_MARCH) -mabi=$(WITH_MABI) --specs=dramfs.specs
RISCV_AR = $(CROSS_COMPILE)ar
RISCV_RANLIB = $(CROSS_COMPILE)ranlib

.PHONY: perch

perch:
	$(RISCV_GCC) -c *.c *.S
	$(RISCV_AR) -rc libperch.a *.o
	$(RISCV_RANLIB) libperch.a

clean:
	-rm -rf *.a
	-rm -rf *.o
