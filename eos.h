#ifndef __eos_h
#define __eos_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *eos_convert;
char e_code[200];

#define e_convert(x) eos_convert = fopen( x ,"r"); fscanf( eos_convert, "%s" ,e_code ); printf("%s" ,&e_code); fclose(eos_convert); eos_convert = fopen( "code.html" ,"w"); fprintf(eos_convert,"<head>\n</head>\n\n<body>\n<p>\n%s\n</p>\n</body>",e_code); fclose(eos_convert);

#endif
