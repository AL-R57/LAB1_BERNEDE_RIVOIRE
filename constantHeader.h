#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

#ifndef UNTITLED_CONSTANTHEADER_H
#define UNTITLED_CONSTANTHEADER_H

#define WELCOME_MSG "Welcome to ENSEA Tiny Shell \nType 'exit' to quit.\n"
#define PROMPT "enseash %"
void shell(char* Macro);
void command();
void return_code(int status,struct timespec start, struct timespec stop);

#endif //UNTITLED_CONSTANTHEADER_H
#define MAX_INPUT_SIZE 1024

