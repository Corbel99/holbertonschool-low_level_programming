#include <stdio.h>

/**
 * main - Entry point of the Simple Calculator program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice = -1;
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	printf("Simple Calculator\n");

	while (choice != 0)
	{
		printf("\n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		if (choice >= 1 && choice <= 4)
		{
			printf("Enter first number: ");
			scanf("%d", &num1);

			printf("Enter second number: ");
			scanf("%d", &num2);

			if (choice == 1)
				result = num1 + num2;
			else if (choice == 2)
				result = num1 - num2;
			else if (choice == 3)
				result = num1 * num2;
			else if (choice == 4)
			{
				if (num2 != 0)
					result = num1 / num2;
				else
				{
					printf("Error: division by zero.\n");
					continue;
				}
			}

			printf("Result: %d\n", result);
		}
		else if (choice != 0)
		{
			printf("Invalid choice.\n");
		}
	}

	printf("Bye!\n");

	return (0);
}
