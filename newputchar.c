#include "main.h"
/**
 * newputchar - function that prints character.
 * @c: a character to print.
 * Return: 1 for success
 */
int newputchar(char c)
{
	return (write(1, &c, 1));
}
