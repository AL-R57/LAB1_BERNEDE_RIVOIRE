#include "constantHeader.h"

void command(){
    char input[MAX_INPUT_SIZE] = {0};
    int status;
    while(1){

        shell(PROMPT);

        //read user input
        int number_of_bytes_read = read(STDIN_FILENO,input,sizeof(input));

        //Remove the newline character '\n' from the input
        input[number_of_bytes_read - 1] = '\0';

        // Execute the command
        pid_t pid = fork();
        if (pid==-1){
            perror("Fork failed");
        }
        else if (pid == 0){
            //Child process
            execlp(input,input,NULL);
            exit(EXIT_SUCCESS);
        } else {
            //Parent process
            wait(&status);
        }
    }
}

