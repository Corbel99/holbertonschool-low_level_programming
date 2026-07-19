#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	operation = get_op_func(argv[2]);

	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((strcmp(argv[2], "/") == 0 ||
		strcmp(argv[2], "%") == 0) &&
		atoi(argv[3]) == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", operation(atoi(argv[1]), atoi(argv[3])));

	return (0);
}
