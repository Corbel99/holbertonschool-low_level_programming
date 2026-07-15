#include "function_pointers.h"
/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: pointer to the function used to print the name
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	(*f)(name);

}
