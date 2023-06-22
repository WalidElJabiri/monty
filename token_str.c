#include <stdlib.h>
#include "monty.h"

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_length(char *str, char *delims);
int get_count(char *str, char *delims);
char *get_word(char *str, char *delims);

/**
 * strtow - takes a str and seperate its words
 * @str: str to seperate
 * @delims: delimitors to use delimit words
 * Return: 2D array
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordlen = get_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_word(str, delims);
		}
		words[i] = malloc((wordlen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - checks delimitor char
 * @ch: char in stream
 * @delims: P to null terminated array of delimitors
 * Return: 1 succes otherwise 0
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_length - gets the word length
 * @str: str to get word length from current word
 * @delims: delimitors to use delimit words
 * Return: word length
 */

int get_length(char *str, char *delims)
{
	int wlen = 0, pend = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pend = 1;
		else if (pend)
		{
			wlen++;
		}
		if (wlen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wlen);
}

/**
 * get_count - gets the word count
 * @str: str to get word count from it
 * @delims: delimitors to use delimit words
 * Return: the word count of the str
 */

int get_count(char *str, char *delims)
{
	int wc = 0, pend = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
		pend = 1;
		else if (pend)
		{
			pend = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_word - gets the next word
 * @str: str to get next word from it
 * @delims: delimitors to use delimit words
 * Return: p to first char of next word
 */

char *get_word(char *str, char *delims)
{
	int pend = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pend = 1;
		else if (pend)
			break;
		i++;
	}
	return (str + i);
}
