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

        //arguments recovery
        char splitter[]=" ";
        int i = 0;
        char **arguments_list = NULL;
        char *arguments = strtok(input, splitter);
        while(arguments != NULL){
            //allocation of the memory
            arguments_list = realloc(arguments_list, (i + 1) * sizeof(char *));
            arguments_list[i] = malloc(strlen(arguments));
            strcpy(arguments_list[i], arguments);

            arguments = strtok(NULL, splitter);
            i++;
        }

        // Execute the command
        pid_t pid = fork();
        if (pid==-1){
            perror("Fork failed");
        }
        else if(pid == 0) {
            // Child process
            execvp(arguments_list[0], arguments_list);
            free(arguments_list); // free the allocated memory
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(&status);
            clock_gettime(CLOCK_MONOTONIC, &stop);
            return_code(status,start,stop);
        }

        // Check if the user wants to exit
        if (strcmp(input,"exit") == 0){
            write(STDOUT_FILENO,"Goodbye!\n",9);
            break;
        }
    }
}

