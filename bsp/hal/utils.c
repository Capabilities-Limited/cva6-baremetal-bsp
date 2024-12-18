// Copyright 2024 Capabilities Limited

#include "time.h"
#include "encoding.h"

int usleep(useconds_t wait)
{
  register uint64_t start_cycles = read_csr(mcycle);
  uint64_t CYCLES_PER_USEC = 50; // 50MHz
  uint64_t target_cycles = wait * CYCLES_PER_USEC;
  while (1) {
    register uint64_t cur_cycles = read_csr(mcycle);
    if (cur_cycles - start_cycles >= target_cycles) {
      break;
    }
  }
  return 0;
}
