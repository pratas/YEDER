#include <stdio.h>
#include <stdlib.h>
#include "sys.h"
#include "defs.h"
#include "files.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint64_t GetRamInKB(void){
  FILE *meminfo = Fopen("/proc/meminfo", "r");

  char line[256];
  while(fgets(line, sizeof(line), meminfo)){
    uint64_t ram;
    if(sscanf(line, "MemTotal: %"PRIu64" kB", &ram) == 1){
      fclose(meminfo);
      return ram;
      }
    }

  fprintf(stderr, "Unable to get RAM memory\n");
  fclose(meminfo);
  return -1;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint32_t GetCPUsNumber(void){
  return sysconf(_SC_NPROCESSORS_ONLN);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

