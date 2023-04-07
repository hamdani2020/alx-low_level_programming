#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */

size_t _strlen(char *str)
{
	size_t iterate;

	for (iterate = 0; str[iterate]; iterate++);
	return (iterate);
}

/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int filen;
	ssize_t len;

	if (filename == NULL)
		return (-1);
	filen = open(filename, O_WRONLY | O_APPEND);
	if (filen == -1)
		return (-1);
	if (text_content)
		len = write(filen, text_content, _strlen(text_content));
	close(filen);
	if (len == -1)
		return (-1);
	return (1);
}
