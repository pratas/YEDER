#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "defs.h"
#include "files.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Fdelete(char *name){
  int ret = remove(name);
  if(ret == 0)
    ; //printf("File %s deleted successfully!\n", name);
  else
    printf("Error: unable to delete the file!\n");
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Fclose(FILE *F){
  if(F == NULL){
    fprintf(stderr, "Error (Fclose): NULL file pointer.\n");
    exit(EXIT_FAILURE);
    }

  if(ferror(F)){
    fprintf(stderr, "Error (Fclose): unable to close the stream due to an "
    "unknown error.\n");
    exit(EXIT_FAILURE);
    }
		
  if(fclose(F) != 0){
    fprintf(stderr, "Error (Fclose): unable to close the file stream.\n");
    exit(EXIT_FAILURE);	
    }
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Fseeko(FILE *F, off_t offset, int32_t ac){

  if(F == NULL){
    fprintf(stderr, "Error (Fseeko): NULL file pointer.\n");
    exit(EXIT_FAILURE);
    }
		
  if(fseeko(F, offset, ac) != 0){
    Fclose(F);
    fprintf(stderr, "Error (Fseeko): unable to change file position.\n");
    fprintf(stderr, "Error (Fseeko): offset = %"PRId64".\n",offset);
		
    switch(ac){
      case SEEK_SET:
      fprintf(stderr, "Error (Fseeko): origin = %d (SEEK_SET).\n", ac);
      break;
      case SEEK_CUR:
      fprintf(stderr, "Error (Fseeko): origin = %d (SEEK_CUR).\n", ac);
      break;
      case SEEK_END:
      fprintf(stderr, "Error (Fseeko): origin = %d (SEEK_END).\n", ac);
      default:
      fprintf(stderr, "Error (Fseeko): invalid origin value = %d.\n", ac);
      exit(EXIT_FAILURE);
      }			
    }
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	
	
uint64_t Ftello(FILE *F){
  if(F == NULL){
    fprintf(stderr, "Error (Ftello): NULL file pointer.\n");
    exit(EXIT_FAILURE);
    }
	
  if(ftello(F) < 0){
    Fclose(F);
    fprintf(stderr, "Error (Ftello): unable get the current position of the"
    " file associated with stream.\n");
    exit(EXIT_FAILURE);	
    }
	
  return (uint64_t) ftello(F);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int FileExists(const char *fn){
  FILE *F = NULL;
  if((F = fopen(fn, "r")) != NULL){ 
    fclose(F);
    return 1;
    }
  return 0;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

FILE *Fopen(const char *path, const char *mode){
  FILE *file = fopen(path, mode);

  if(file == NULL){
    fprintf(stderr, "Error opening: %s (mode %s). Does the file exist?\n", 
    path, mode);
    exit(1);
    }

  return file;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TestReadFile(char *fn){
  FILE *f = NULL;
  f = Fopen(fn, "r");
  fclose(f);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

