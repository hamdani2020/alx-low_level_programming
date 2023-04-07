#include "main.h"

/**
 * create_file - creates a file with the given name and writes the given text
 *               content to it
 *
 * @filename: the name of the file to create
 * @text_content: the text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	// Check if filename is NULL
	if (filename == NULL)
		return (-1);

	// Count the number of characters in the text content
	int text_length = 0;
	if (text_content != NULL)
	{
		while (text_content[text_length] != '\0')
			text_length++;
	}

	// Create the file with the given name and open it for reading and writing
	int file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	// Write the text content to the file
	int write_result = write(file_descriptor, text_content, text_length);

	// Check if the file could not be created or if the text content could not be written
	if (file_descriptor == -1 || write_result == -1)
		return (-1);

	// Close the file
	close(file_descriptor);

	return (1);
}


/* Hamdani Alhassan Gandi */
