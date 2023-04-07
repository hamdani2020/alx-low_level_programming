#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the standard output
 *                in POSIX format.
 *
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print from the file.
 *
 * Return: The number of letters successfully read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Check if the filename is valid. */
	if (filename == NULL)
		return (0);

	/* Open the file. */
	int file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	/* Allocate a buffer of the appropriate size. */
	char *buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	/* Read the file into the buffer. */
	ssize_t read_check = read(file, buffer, letters);
	if (read_check == -1)
		return (0);

	/* Write the buffer to the standard output. */
	ssize_t write_count = write(STDOUT_FILENO, buffer, read_check);
	if (write_count == -1 || write_count != read_check)
		return (0);

	/* Free the buffer and close the file. */
	free(buffer);
	close(file);

	return (write_count);
}

