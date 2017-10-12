#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#include "defs.h"
#include "files.h"
#include "sys.h"

void RunExec(char **cmd){
  pid_t pid = fork();    // SPAWN CHILD FOR PROGRAM RUN
  if(pid == 0){          // CHILD PROCESS
    execv(cmd[0], cmd);
    exit(127);           // IF FAILS
    }
  else{                  // PID != 0 & PARENT PROCESS
    waitpid(pid, 0, 0);  // WAIT FOR CHILD TO EXIT
    }
  sleep(1);
  }

int main(int argc, char *argv[]){

  uint64_t Max_ram_memory = 0;
  uint32_t Max_cpu_number = 0;

  Max_ram_memory = GetRamInKB();
  Max_cpu_number = GetCPUsNumber();

  printf("RAM Memory ................ %"PRIu64" MB\n", Max_ram_memory / 1024);
  printf("Number of CPUs ............ %u\n", Max_cpu_number);

  static char *falcon_cmd[]           = {"../bins/FALCON", 
                                         "FALCON parameters",   
                                          NULL};

  static char *falcon_filter_cmd[]    = {"../bins/FALCON-filter",  
                                         "FALCON-filter parameters",   
                                          NULL};

  static char *falcon_eye_cmd[]       = {"../bins/FALCON-eye",     
                                         "FALCON-eye parameters",   
                                          NULL};

  static char *gull_map_cmd[]         = {"../bins/GULL-map",
                                         "GULL parameters",     
                                          NULL};

  static char *gull_visual_cmd[]      = {"../bins/GULL-visual",  
                                         "GULL-visual parameters",     
                                          NULL};

  static char *chester_map_cmd[]      = {"../bins/CHESTER-map", 
                                         "CHESTER-map parameters",  
                                          NULL};

  static char *chester_filter_cmd[]   = {"../bins/CHESTER-filter", 
                                         "CHESTER-filter parameters",  
                                          NULL};

  static char *chester_visual_cmd[]   = {"../bins/CHESTER-visual",
                                         "CHESTER-visual parameters",
                                          NULL};

  static char *kestrel_cmd[]          = {"../bins/KESTREL",
                                         "KESTREL parameters",
                                          NULL};

  static char *cryfa_cmd[]            = {"../bins/CRYFA",
                                         "CRYFA parameters",
                                          NULL};

  static char *uncryfa_cmd[]          = {"../bins/CRYFA",
                                         "UNCRYFA parameters",
                                          NULL};

  static char *goose_info_cmd[]       = {"../bins/goose-info",
                                         "goose-x parameters",
                                          NULL};

  RunExec(falcon_cmd);
  RunExec(gull_map_cmd);
  
  return 0;
  }

