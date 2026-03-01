#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
void Error( char *Str )
{
    fprintf( stderr, "%s\n", Str );
}

void FatalError( char *Str )
{
    Error( Str );
    exit( 1 );
}