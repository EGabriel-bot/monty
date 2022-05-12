#include "monty.h"
/**
 * main - check the code
 *@argc: argument count
 *@argv: argument value
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	FILE *fo;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *first;
	char *second;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fo = fopen(argv[1], "r");
	if (fo == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fo)) != -1)
	{
		first = strtok(line, " \t\n");
		second = strtok(NULL, " \t\n");
		printf("%s %s\n", first, second);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
