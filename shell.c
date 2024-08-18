#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

void free_array(char **tab)
{
    int i, len_tab;

    while (*tab)
    {
        len_tab++;
    }

    for (i = 0; i <= len_tab; i++)
    {
        free(tab[i]);
    }
}


int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t child_pid;

    int status;
    int i = 0;
    char **args;
    char *env[] = {"PATH=/bin", NULL};
    char *token;

    args = malloc(i * sizeof(char *));
    /* probleme d'allocation*/
    while(1)/* affiche #cisfun*/
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        i = 0;
        line = NULL;
        len = 0;

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
            /* free parent ? */
            if (child_pid < 0)
            {
                exit(100);
            }
            if (strcmp(args[0], "exit") == 0 ||strcmp(args[0], "^C") == 0)/* check si exit a été tapé ou ctrl c*/
            {
                exit(3);
            }
            if (child_pid == 0)
            {
                if (execve(args[0], args, env) == -1)/*execute*/
                {
                    perror("./shell");
                    exit(1);
                }
            }
            wait(&status);
        }
        free(line);
        line = NULL;
        len = 0;
    }
    return (0);
}