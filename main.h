#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

void free_array(char **tab);
char** cut_path(char **tableau);
void sortie_fonction(char *mot);
void _strtok(char **array, char *ligne);
int print_env(char *mot, char ** environnement);
#endif
