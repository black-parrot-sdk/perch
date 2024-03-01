// See LICENSE for license details.

#include "htif.h"
#include "pk.h"
//#include "atomic.h"
//#include "mtrap.h"
//#include "fdt.h"
#include "syscall.h"
#include <string.h>

//extern uint64_t __htif_base;
//volatile uint64_t tohost __attribute__((section(".htif")));
//volatile uint64_t fromhost __attribute__((section(".htif")));
extern uint64_t tohost;
extern uint64_t fromhost;
//uint64_t* tohost = (uint64_t*)_tohost;
//uint64_t* fromhost = (uint64_t*)_fromhost;
volatile int htif_console_buf;
//static spinlock_t htif_lock = SPINLOCK_INIT;
//uintptr_t htif;

//#define TOHOST(base_int)	(uint64_t *)(base_int + TOHOST_OFFSET)
//#define FROMHOST(base_int)	(uint64_t *)(base_int + FROMHOST_OFFSET)

//#define TOHOST_OFFSET		((uintptr_t)tohost - (uintptr_t)__htif_base)
//#define FROMHOST_OFFSET		((uintptr_t)fromhost - (uintptr_t)__htif_base)

static void __check_fromhost()
{
  uint64_t fh = fromhost;
  if (!fh)
    return;
  fromhost = 0;

  // this should be from the console
  kassert(FROMHOST_DEV(fh) == 1);
  switch (FROMHOST_CMD(fh)) {
    case 0:
      htif_console_buf = 1 + (uint8_t)FROMHOST_DATA(fh);
      break;
    case 1:
      break;
    default:
      kassert(0);
  }
}

static void __set_tohost(uintptr_t dev, uintptr_t cmd, uintptr_t data)
{
  while (tohost)
    __check_fromhost();
  tohost = TOHOST_CMD(dev, cmd, data);
}

int htif_console_getchar()
{
  //spinlock_lock(&htif_lock);
    __check_fromhost();
    int ch = htif_console_buf;
    if (ch >= 0) {
      htif_console_buf = -1;
      __set_tohost(1, 0, 0);
    }
  //spinlock_unlock(&htif_lock);

  return ch - 1;
}

static void do_tohost_fromhost(uintptr_t dev, uintptr_t cmd, uintptr_t data)
{
  //spinlock_lock(&htif_lock);
    __set_tohost(dev, cmd, data);

    while (1) {
      uint64_t fh = fromhost;
      if (fh) {
        if (FROMHOST_DEV(fh) == dev && FROMHOST_CMD(fh) == cmd) {
          fromhost = 0;
          break;
        }
        __check_fromhost();
      }
    }
  //spinlock_unlock(&htif_lock);
}

void htif_syscall(uintptr_t arg)
{
  do_tohost_fromhost(0, 0, arg);
}

void htif_console_putchar(uint8_t ch)
{
  //spinlock_lock(&htif_lock);
    __set_tohost(1, 1, ch);
  //spinlock_unlock(&htif_lock);
}

void htif_poweroff()
{
  while (1) {
    //spinlock_lock(&htif_lock);
    __set_tohost(0, 0, 1);
    //spinlock_unlock(&htif_lock);
  }
}