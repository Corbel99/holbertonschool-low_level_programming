#include <stdio.h>

int main(void)
{
	int choice = -1;

	printf("Simple Calculator\n");

	while (choice != 0)
	{
		printf("\n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		if (choice != 0)
			printf("Invalid choice.\n");
	}

	printf("Bye!\n");

	return (0);
}
