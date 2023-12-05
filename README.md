# LAB1_BERNEDE_RIVOIRE

## First step: display a welcome message
We learned how to use the write function with STDOUT_FILENO to display 
the background of our tinyshell: the welcome message and "enseash %".
(basic function of the courses)

## REPL: read–eval–printloop
We learned how to set up a REPL.
- We use the read function with STDIN_FILENO to get a user command (without any arguments). [read]
- We learned to execute the user command with the execlp function and how to use correctly the buffer. [eval]
- We finish the REPL loop by returning the prompt "enseash %".[printloop]

All this is done thanks to the fork() function.
The father process is put in sleep mode thanks to wait(&status) while the child process is executing the user command.

## Exiting the shell
We learned how to exit the shell by writing "exit" with if-loop, fork() and break function.
(nothing really complicated here, just comparing input user with "exit")

## Examination of status returned by a termination child
We had to use wisely the write() function in order to write a message containing an integer variable.
Knowing how to use the macros (WIFEXITED(), WIFSIGNALED(), WEXITESTATUS(), WSIGNALED()) to examine the 
signal number that causes the termination of the child.

##  Measurement of the command execution time using the call clock_gettime
We implemented a timer using the struct timespec. The clock_gettime function with the macro CLOCK_MONOTONIC 
allowed us to display the time needed to execute the previous command in the shell. 

## Execution of a complex command (with arguments)
The difficult part here was the memory allocation for the local argument_list variable to get the different 
arguments of the user command.
We cut the user command with the strtok() function with the " " character as a splitter and a while-loop.
All the arguments are stored in a table.
Here we had to use execvp instead of execlp because the arguments are passed at once in a (char**) whose the 
last element is a (char*)NULL.

We test our code with different function whose take several arguments, for example cowsay.

## Management of redirections to stdin and stdout with ’<’ and ’>’
In this section, we learned how to work with stdin and stdout redirection using '<' and '>'.
This part is the one that caused us the most trouble. We learned how to use the 'open' function 
with the correct parameters. The aspect that posed the most difficulty for us was writing to the 
file we had just opened, particularly the use of the 'dup2' function and the 'fileno(stdout)' and 
'fileno(stdin)' functions.