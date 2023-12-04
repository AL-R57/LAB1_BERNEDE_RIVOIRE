#include "constantHeader.h"

void return_code(int status){
    char buff[18];
    if (WIFEXITED(status)) {
        sprintf(buff,"enseash [exit:%d] %% ",WEXITSTATUS(status));
        write(STDOUT_FILENO,buff,sizeof(buff));
    } else if (WIFSIGNALED(status)) {
        sprintf(buff,"enseash [sign:%d] %% ", WTERMSIG(status));
        write(STDOUT_FILENO,buff,sizeof(buff));
    } else {
        write(STDOUT_FILENO,"enseash %%", 10);
    }
}