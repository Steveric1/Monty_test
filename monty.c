#include "monty.h"

stream_t bus = {NULL};
/**
 * main - stack and queue data structure interpreter
 * @av: argument
 * @ac: argument counter
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *file_path;
	stream_t file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = av[1];
	file.file = fopen(file_path, "r");
	bus.file = file.file;
	if (file.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	processMonty(file);
	fclose(file.file);
	return (0);
}
