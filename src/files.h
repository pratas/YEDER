#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include "defs.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void        Fdelete          (char *);
void        Fclose           (FILE *);
void        Fseeko           (FILE *, off_t, int32_t);
uint64_t    Ftello           (FILE *);
int         FileExists       (const char *);
FILE        *Fopen           (const char *, const char *);
void        TestReadFile     (char *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif
