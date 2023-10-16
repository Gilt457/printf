#include "main.h"

/**
 * is_printable - Determines whether a character is printable.
 * @c: The character to be assessed.
 *
 * If c is printable, return 1; otherwise, return 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Add ascci to buffer in hexadecimal code.
 * @buffer: A character array.
 * @i: The index from which to begin adding.
 * @ascii_code: ASSCI CODE.
 *
 * Always return 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Determines whether a character is a digit.
 * @c: To be evaluated character
 *
 * If c is a digit, return 1; otherwise, return 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Converts a number to the given size.
 * @num: The number to be cast.
 * @size: A number that indicates the type to be cast.
 *
 * num's casted value is returned.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Converts a number to the given size.
 * @num: The number to be cast
 * @size: A number specifying the type to be casted.
 *
 * num's casted value is returned.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
