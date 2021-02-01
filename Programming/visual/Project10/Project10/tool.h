#ifndef tool_h
#define tool_h
#include <stdio.h>

FILE* fo;

char* getArray(char* path_to_file);
void writeArray(char* array, char* path_to_file);

#endif