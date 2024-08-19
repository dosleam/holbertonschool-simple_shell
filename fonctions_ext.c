#include "main.h"
/**
* free_array - fonction
* Fonction qui libère un tableau
* @tab: tableau a liberer
*/
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
/**
* cut_path - fonction
* Fonction qui découpe le path afin d'obtenir les chemins d'accés
* @tab: tableau ou l'on stocke les valeurs découpés du path
* Return: un tableau contenant les valeurs de path
*/
char **cut_path(char **tab)
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
/**
* sortie_fonction - fonction
* Fonction qui sort de la boucle prompt
* si exit ou ^C a été tapé
* @mot: entrée de l'utilisateur
*/
void sortie_fonction(char *mot)
{
	if ((strcmp(mot, "exit") == 0) || (strcmp(mot, "^C") == 0))
	{
		exit(3);
	}
}

/**
* print_env - fonction
* Foncion qui affiche l'environnement présent
* @mot: entrée utilisateur, doit correspondre à env
* @environnement: environnement a afficher
* Return: 1 si succès, 0 si échec
*/
int print_env(char *mot, char **environnement)
{

	if (strcmp(mot, "env") == 0)
	{
		while (*environnement)
		{
			printf("%s\n", *environnement);
			environnement++;
		}
		return (0);
	}
	return (1);

}

/**
* _strtok - fonction
* Fonction qui découpe l'entrée utilisateur
* et stocke les valeurs dans un tableau
* @array: tableau avec les valeurs decoupés de ligne
* @ligne: entrée utilisateur à découper
*/
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
