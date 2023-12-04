#include "constantHeader.h"

void return_code(int status,struct timespec start, struct timespec stop){
    u_int64_t execution_time = (start.tv_sec - stop.tv_sec)*1000+ (stop.tv_nsec - start.tv_nsec)/1000000;

    char buff[30];
    if (WIFEXITED(status)) {
        sprintf(buff, "enseash [exit:%d |%ld ms] %%", WEXITSTATUS(status),execution_time);
        write(STDOUT_FILENO,buff,strlen(buff));
    } else if (WIFSIGNALED(status)) {
        sprintf(buff,"enseash [sign:%d |%ld ms] %%", WTERMSIG(status),execution_time);
        write(STDOUT_FILENO,buff,strlen(buff));
    } else {
        write(STDOUT_FILENO,"enseash %%",10);
    }
}