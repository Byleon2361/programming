#pragma once

#define MAX_PATH 260
#define MAX_NUMBER_PATH 20
#define MAX_INPUT_DATA 300
#define MAX_OUTPUT_DATA 400

int input(char* string, char* delim);
int checkNameFile(char* string, char delim);
int checkSymbols(char* string, char delim);
int checkPaths(char* string, char delim);
char* process(char* result, char** paths, int count);
int output(char* res);