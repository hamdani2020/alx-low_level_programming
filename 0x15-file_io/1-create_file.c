#include "main.h"
/**
 * create_file -makes an array of chars, and introduce
 *
 * @text_content: is a NULL terminated string to write to the file
 * @filename: is the name of the file to make
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int o, w, lengh = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lengh = 0; text_content[lengh];)
			lengh++;
	}

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content, lengh);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
