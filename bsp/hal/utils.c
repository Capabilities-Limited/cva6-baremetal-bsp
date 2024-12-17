// Copyright 2024 Capabilities Limited

#include "time.h"

int usleep(useconds_t wait)
{
  register uint64_t start_cycles;
  // While the asm does not clobber memory, avoid reordering by indicating it does
  __asm__ __volatile__ ("csrr %0, mcycle" : "=r" (start_cycles) : : "memory");
  uint64_t CYCLES_PER_USEC = 50; // 50MHz
  uint64_t target_cycles = wait * CYCLES_PER_USEC;
  while (1) {
    register uint64_t cur_cycles;
    __asm__ __volatile__ ("csrr %0, mcycle" : "=r" (cur_cycles) : : "memory");
    if (cur_cycles - start_cycles >= target_cycles) {
      break;
    }
  }
  return 0;
}
