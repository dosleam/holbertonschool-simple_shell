#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t child_pid;
    int status;
    int i = 0;
    char *args[100];
    char *env[] = {NULL};
    char *token;

    while(1)/* affiche #cisfun*/
    {
        printf("#cisfun$ ");
        i = 0;
        if ((read = getline(&line, &len, stdin)) != -1) /*lit le flux*/
        {
            token = strtok(line, " \n"); /* decoupe le flux*/
            while (token != NULL)
            {
                args[i] = token;
                i++;
                token = strtok(NULL, " \n");
            }
            args[i] = NULL;

            child_pid = fork();/*crée process*/
            if (child_pid < 0)
            {
                exit(100);
            }
            if (child_pid == 0)
            {
            if (execve(args[0], args, env) == -1)/*execute*/
            {
                perror("execve");
                    exit(1);
            }
            wait(&status);
        }
        free(line);
        line = NULL;
        len = 0;
    }
}
}