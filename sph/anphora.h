#ifndef __anphora_h
#define __anphora_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *anphora_convert;
char a_code[200];

#define a_convert(x) anphora_convert = fopen( x ,"r"); fscanf( anphora_convert, "%s" ,a_code ); printf("%s" ,&a_code); fclose(anphora_convert); anphora_convert = fopen( "code.sh" ,"w"); fprintf(anphora_convert,"echo '%s'",a_code); fclose(anphora_convert);

#endif
