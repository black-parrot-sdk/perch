
RISCV_COMPILE = riscv64-unknown-elf-
DRAMFS_COMPILE = riscv64-unknown-elf-dramfs-
GCC_FLAGS = -fPIC -march=rv64ima -mabi=lp64 -mcmodel=medany -static -I$(BP_SDK_INCLUDE_DIR)

.PHONY: perch

perch:
	$(DRAMFS_COMPILE)gcc $(GCC_FLAGS) -c *.c *.S
	$(DRAMFS_COMPILE)ar -rc libperch.a *.o
	$(DRAMFS_COMPILE)ranlib libperch.a
	rm -rf *.o
	
	$(DRAMFS_COMPILE)gcc $(GCC_FLAGS) -c -DBAREMETAL *.c *.S
	$(DRAMFS_COMPILE)ar -rc libperchbm.a *.o
	$(DRAMFS_COMPILE)ranlib libperchbm.a
	rm -rf *.o
	
	$(RISCV_COMPILE)gcc $(GCC_FLAGS) -Ipk -c -DPK *.c pk/*.c *.S
	$(DRAMFS_COMPILE)ar -rc libperchpk.a *.o
	$(DRAMFS_COMPILE)ranlib libperchpk.a
	rm -rf *.o
	
	$(DRAMFS_COMPILE)gcc $(GCC_FLAGS) -c -DSYSTRACE *.c *.S
	$(DRAMFS_COMPILE)ar -rc libperchs.a *.o
	$(DRAMFS_COMPILE)ranlib libperchs.a
	rm -rf *.o
	
	$(DRAMFS_COMPILE)gcc $(GCC_FLAGS) -c -DBAREMETAL -DSYSTRACE *.c *.S
	$(DRAMFS_COMPILE)ar -rc libperchbms.a *.o
	$(DRAMFS_COMPILE)ranlib libperchbms.a
	rm -rf *.o
	
	$(RISCV_COMPILE)gcc $(GCC_FLAGS) -Ipk -c -DPK -DSYSTRACE *.c pk/*.c *.S
	$(DRAMFS_COMPILE)ar -rc libperchpks.a *.o
	$(DRAMFS_COMPILE)ranlib libperchpks.a
	rm -rf *.o

clean:
	-rm -rf *.a
	-rm -rf *.o
