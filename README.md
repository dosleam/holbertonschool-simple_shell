# ./hsh

## Description
A simple shell is a minimalist command interpreter focused on executing essential tasks such as process management and command execution. Its streamlined design makes it ideal for environments where simplicity and efficiency are prioritized.

## installation
git clone https://github.com/dosleam/holbertonschool-simple_shell.git

## Compilation
To compile this project, use the following command:  
'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh'

## Requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

## Authorized Functions
- all functions from string.h
- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- printf
- fprintf
- vfprintf
- sprintf
- putchar
- read
- readdir
- signal
- stat (__xstat)
- lstat (__lxstat)
- fstat (__fxstat)
- strtok
- wait
- waitpid
- wait3
- wait4
- write

## features
Supports format specifiers: `%c`, `%s`, `%i`, `%d`

## examples of use
Here are some usage examples:  
($) ls
shell.c main.h man_page README.md AUTHORS

## testing
To test the implementation. Compile and run it as follows:  
'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh'
`./hsh`

## flowchart
![Flowchart](./image/_printf.png)

## crew
This project was made by Mariama Goudiaby and Jeremy Sousa.