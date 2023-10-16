#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - This function prints an unsigned number.
 * @types: a list of arguments
 * @buffer: A buffer array for printing.
 * @flags: Computes active flags.
 * @width: get the width
 * @precision: Precision requirements
 * @size is a size specifier.
 * Return the number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Displays an unsigned number in octal notation.
 * @types: Arguments list
 * @buffer: A buffer array for printing.
 * @flags: Computes active flags.
 * @width: get the width
 * @precision: Precision requirements
 * @size is a size specifier.
 * Return the number of characters printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - This function outputs an unsigned number in hexadecimal format.
 * @types: Arguments list
 * @buffer: A buffer array for printing.
 * @flags: Computes active flags.
 * @width: get the width
 * @precision: Precision requirements
 * @size is a size specifier.
 * Return the number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * Prints an unsigned number in higher hexadecimal format.
 * @types: Arguments list
 * @buffer: A buffer array for printing.
 * @flags: Computes active flags.
 * @width: get the width
 * @precision: Precision requirements
 * @size is a size specifier.
 * Return the number of characters printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - This function prints a hexadecimal number in either lower or upper case.
 * @types: Arguments list
 * @map_to: An array of values to which the number should be mapped.
 * @buffer: A buffer array for printing.
 * @flags: Computes active flags.
 * @flag_ch: Determines active flags.
 * @width: get the width
 * @precision: Precision requirements
 * @size is a size specifier.
 * @size: Size information
 * Return the number of characters printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
