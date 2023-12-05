#include "constantHeader.h"

void command() {
    char input[MAX_INPUT_SIZE]={0}; //
    int status;
    struct timespec start;
    struct timespec stop;

    while (1) {

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
        else if(pid == 0) {
            // Child process

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

                if((strcmp(arguments,">"))==0){
                    // Remove '>' from arguments
                    arguments_list[i] = NULL;

                    // recuperation of the i+1 th argument
                    arguments = strtok(NULL, splitter);
                    arguments_list[i+1] = malloc(strlen(arguments));
                    strcpy(arguments_list[i+1], arguments);

                    int file = open(arguments_list[i+1], O_WRONLY | O_CREAT | O_TRUNC,0666); // write mode | create the file if it doesn't exist | overwrite an existing file | activation of authorised access

                    if (file == -1) {
                        perror("Error opening input file");
                        exit(EXIT_FAILURE);
                    }

                    // Redirect standard output to the file
                    if (dup2(file, fileno(stdout)) == -1) {
                        perror("Error redirecting standard output");
                        exit(EXIT_FAILURE);
                    }

                    // Close the file descriptor, as it's no longer needed
                    close(file);

                    // Stop processing arguments after the redirection
                    break;

                }else if((strcmp(arguments,"<"))==0){
                    // Remove '<' from arguments
                    arguments_list[i] = NULL;

                    // recuperation of the i+1 th argument
                    arguments = strtok(NULL, splitter);
                    arguments_list[i+1] = malloc(strlen(arguments));
                    strcpy(arguments_list[i+1], arguments);

                    int file = open(arguments_list[i+1], O_RDONLY); // read mode

                    if (file == -1) {
                        perror("Error opening output file");
                        exit(EXIT_FAILURE);
                    }

                    // Redirect standard output to the file
                    if (dup2(file, fileno(stdin)) == -1) {
                        perror("Error redirecting standard output");
                        exit(EXIT_FAILURE);
                    }

                    // Close the file descriptor, as it's no longer needed
                    close(file);

                    // Stop processing arguments after the redirection
                    break;

                }else {
                    arguments = strtok(NULL, splitter);
                    i++;
                }
            }
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
        if (strcmp(input, "exit") == 0) {
            write(STDOUT_FILENO, "Goodbye!\n", 9);
            break;
        }
    }
}