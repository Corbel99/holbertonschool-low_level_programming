#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	(void)argc;
	
	printf("%d\n", a * b);

	return (0);
}
