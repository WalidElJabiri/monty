#include "monty.h"
#include <stdlib.h>

char *get_int(int num);
unsigned int abs_monty(int i);
int get_len(unsigned int num, unsigned int base);
void fill_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);

/**
 * get_int - gets a character pointer to new str
 * @num: number to convert to str
 * Return: character pointer to newly created str. NULL
 */
char *get_int(int num)
{
	unsigned int temp;
	int len = 0;
	long num_l = 0;
	char *ret;

	temp = abs(num);
	len = get_len(temp, 10);

	if (num < 0 || num_l < 0)
		len++;
		ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	fill_buff(temp, 10, ret, len);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * abs - gets the absolute value of an int
 * @i: integer to get absolute valu
 * Return: i
 */
unsigned int abs_monty(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_len - get len of buffer needed for an unsigned int
 * @num: number to get len needed for
 * @base: base of number
 * Return: integer containing length of buffer
 */
int get_len(unsigned int num, unsigned int base)
{
	int i = 1;

	while (num > base - 1)
	{
		i++;
		num /= base;
	}
	return (i);
}

/**
 * fill_buff - fills buffer with corect numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion
 * @buff: buffer to fill
 * @buff_size: size of buffer in byte
 * Return: void
 */
void fill_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
	int r, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		r = num % base;
		if (r > 9)
			buff[i] = r + 87;
		else
			buff[i] = r + '0';
		num /= base;
		i--;
	}
}
