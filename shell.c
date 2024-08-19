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

char** cut_path(char **tab)
{
    char *path;
    int i;
    char *token;

    path = getenv("PATH");

    if (path == NULL)
    {
        return (NULL);
    }

    token = strtok(path, ":"); /* decoupe le path*/
    i = 0;
    while (token != NULL)
    {
        tab[i] = token;
        i++;
        token = strtok(NULL, ":");
    }
    tab[i] = NULL;
    return (tab);
}

void sortie_fonction(char *mot)
{
    if (strcmp(mot, "exit") == 0 ||strcmp(mot, "^C") == 0)/* check si exit a été tapé ou ctrl c*/
        {
            exit(3);
        }
}

extern char **environ;

void print_env(char *mot)
{
    int i;

    i = 0;
    if (strcmp(mot, "env") == 0)
    {
        while (environ[i] != NULL)
        {
            printf("%s\n", *environ);
            i++;
        }
    }

}

void _strtok(char **array, char *ligne)
{
    char *token;
    int i;

    token = strtok(ligne, " \n"); /* decoupe le flux*/
    i = 0;
    while (token != NULL)
    {
        array[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    array[i] = NULL;
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
    char *env[64];

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
            _strtok(args, line);

            child_pid = fork();/*crée process*/
            /* free parent ? */
            if (child_pid < 0)
            {
                exit(100);
            }

            sortie_fonction(args[0]);
            print_env(args[0]);

            cut_path(env);

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
