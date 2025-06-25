
WITH_MARCH ?= rv64gc
WITH_MABI ?= lp64d

RISCV_GCC = $(CROSS_COMPILE)gcc -fPIC -march=$(WITH_MARCH) -mabi=$(WITH_MABI) -mcmodel=medany -mstrict-align -nostartfiles
RISCV_AR = $(CROSS_COMPILE)ar
RISCV_RANLIB = $(CROSS_COMPILE)ranlib

.PHONY: perch

PYTHON ?= python

perch.ld:
	$(PYTHON) linker_gen.py $(PLATFORM_DRAM_BASE) $(PLATFORM_SP) > $@

perch: perch.ld
	$(RISCV_GCC) -c *.c *.S
	$(RISCV_AR) -rc libperch.a *.o
	$(RISCV_RANLIB) libperch.a
	rm -rf *.o
	$(RISCV_GCC) -c -o perch_crt0.o crt0.s

clean:
	-rm -rf *.a
	-rm -rf *.o
	-rm -rf *.ld
