#include "main.h"
/**
 * _sqrt_helper - Recursively searches for the natural square root of a number.
 * @n: Number whose natural square root is searched.
 * @i: Current candidate being tested.
 *
 * Return: The natural square root if found, or -1 otherwise.
 */

int _sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	else if (i * i > n)
	{
		return (-1);
	}
	else
	{
		return (_sqrt_helper(n, i + 1));
	}
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: Number whose natural square root is searched.
 *
 * Return: The natural square root of n, or -1 if it does not exist.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (_sqrt_helper(n, 1));
	}
}
