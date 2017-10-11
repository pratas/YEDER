#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "files.h"
#include "sys.h"

int main(int argc,char* argv[]){

  printf("Number of CPUs ............ %u\n", GetCPUsNumber());
  printf("RAM Memory ................ %"PRIu64" KB\n", GetRamInKB());

  return 0;
  }

