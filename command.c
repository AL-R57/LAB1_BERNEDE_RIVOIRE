#include "constantHeader.h"

void command(){
    char input[MAX_INPUT_SIZE] = {0};
    int status;
    struct timespec start;
    struct timespec stop;

    while(1){

        //read user input
        int number_of_bytes_read = read(STDIN_FILENO,input,sizeof(input));
        if (number_of_bytes_read == -1) {
            perror("Error reading input");
        }

        //Remove the newline character '\n' from the input
        input[number_of_bytes_read - 1] = '\0';

        // Start the timer
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Execute the command
        pid_t pid = fork();
        if (pid==-1){
            perror("Fork failed");
        }
        else if (pid == 0){
            //Child process
            execlp(input,input,NULL);
            exit(EXIT_FAILURE);
        } else {
            //Parent process
            wait(&status);
            clock_gettime(CLOCK_MONOTONIC,&stop);
            return_code(status,start,stop);
        }

        // Check if the user wants to exit
        if (strcmp(input,"exit") == 0){
            write(STDOUT_FILENO,"Goodbye!\n",9);
            break;
        }
    }
}

