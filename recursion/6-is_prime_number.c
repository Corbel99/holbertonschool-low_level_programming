#include "main.h"
/**
 * is_prime_helper - Recursively checks if a number has a divisor.
 * @n: Number to check.
 * @i: Current divisor being tested.
 *
 * Return: 1 if n is prime, otherwise 0.
 */

int is_prime_helper(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	else if (n % i == 0)
	{
		return (0);
	}
	else
	{
		return (is_prime_helper(n, i + 2));
	}
}
/**
 * is_prime_number - Checks if a number is prime.
 * @n: Number to check.
 *
 * Return: 1 if n is a prime number, otherwise 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else if (n == 2)
	{
		return (1);
	}
	else if (n % 2 == 0)
	{
		return (0);
	}
	else
	{
		return (is_prime_helper(n, 3));
	}
}
