#ifndef __sphere_h
#define __sphere_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *sphere_convert;
FILE *sphere_search_command;
char s_code[200];

const char start[] = "sph_start"; 
const char stop[] = "sph_stop"; 
const char program_start[] = "program_list_start";
const char program_stop[] = "program_list_stop";
bool p_start = false;
bool s_start = false;

#define convert_op(x) sphere_convert = fopen("converted.sh","a"); fprintf(sphere_convert,x); fclose(sphere_convert);

#define convert_var_op(x,y) sphere_convert = fopen("converted.sh","a"); fprintf(sphere_convert,x,y); fclose(sphere_convert);

#define clear_op(x) x = fopen("converted.sh","w"); fprintf(x,""); fclose(x);

#define s_convert(x) sphere_search_command = fopen( "root.sph" ,"r" ); while(!feof(sphere_search_command)) { fscanf(sphere_search_command,"%s",s_code); printf("%s" ,s_code); if(strcmp(start,s_code) == 0) { convert_op("echo 'Start of SPH code';\n"); s_start = true; } else if(strcmp(stop,s_code) && s_start == true) { convert_op("echo 'End of SPH code';\n"); s_start = false; } else if(strcmp(program_start,s_code) == 0 && s_start == true) { convert_op("echo 'Program list start';\n"); p_start = true; } else if(p_start == true && s_start == true){ convert_var_op("sudo apt-get install %s;\n",s_code); } else if(strcmp(program_stop,s_code) == 0 && p_start == true && s_start == true) { convert_op("echo 'Program list end';\n"); p_start = false; } else if(s_start == true) { convert_var_op("echo '%s';\n",s_code);} else { } } fclose(sphere_search_command);

#endif
