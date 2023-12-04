# LAB1_BERNEDE_RIVOIRE

## Question 1
We learned how to use the write function with STDOUT_FILENO to display 
the background of our tinyshell: the welcome message and "enseash %".
(basic function of the courses)

## Question 2
We learned how to use the read function with STDIN_FILENO to read and execute
the command (with the execlp command) in the shell and display 
the prompt "enseash %" after it.
(basic function of the courses)

## Question 3
We learned how to exit the shell by writing "exit" with
if loop, fork() and break function.
(fork() function we saw in the first tutorial)

## Question 4
We learned the examination of status returned by a termination child 
using WIFEXITED(), WIFSIGNALED(), WEXITESTATUS(), WSIGNALED()
to display the return code or signal of the previous command.

## Question 5
The clock_gettime function allowed us to display the time needed to execute 
the previous command in the shell. We saw how to use the timespec structs.

## Question 6
We execute a complex command, for example cowsay which is a function
taking arguments. We see how to store arguments with realloc, malloc and 
free, and execute the command with its arguments with execvp.

