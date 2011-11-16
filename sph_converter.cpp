#include "sphere.h"
#include "eos.h"
#include "anphora.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void tosphere ( char filename[] );
void toeos ( char filename[] );
void toanphora ( char filename[] );

main ()
{

char filename[30];
short int opc;
short int def;

printf("Put the name of your SPH file:\n\n");
gets(filename);

system("clear");

printf("Convert to:\n\n");
printf("1 -> Sphere code\n");
printf("2 -> Eos code\n");
printf("3 -> Anphora code\n");
scanf("%d" ,&opc);

switch (opc)
{
case 1:
tosphere(filename);
break;

case 2:
toeos(filename);
break;

case 3:
toanphora(filename);
break;

default:
printf("ERROR: Value out of range");
break;
}

}


void tosphere ( char filename[] )
{
clear_op(sphere_search_command);
s_convert(filename);
}

void toeos ( char filename[] )
{
e_convert(filename);
}

void toanphora ( char filename[] )
{
a_convert(filename);
}
