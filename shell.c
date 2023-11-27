#include "constantHeader.h"

void shell(char* Macro){
    write(STDOUT_FILENO,Macro,strlen(Macro));
}


