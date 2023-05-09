#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check97 - looks out for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check98 - looks out for that file_from exists and can be read
 * @checks: looks out if true of false
 * @filenames: file_from name
 * @fde_from: file descriptor of file_from, or -1
 * @fde_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check98(ssize_t checks, char *filenames, int fde_from, int fde_to)
{
	if (checks == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filenames);
		if (fde_from != -1)
			close(fde_from);
		if (fde_to != -1)
			close(fde_to);
		exit(98);
	}
}

/**
 * check99 - checks that file_to was made and/or can be written to
 * @checks: checks if true of false
 * @filenames: file_to name
 * @fde_from: file descriptor of file_from, or -1
 * @fde_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check99(ssize_t checks, char *filenames, int fde_from, int fde_to)
{
	if (checks == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filenames);
		if (fde_from != -1)
			close(fde_from);
		if (fde_to != -1)
			close(fde_to);
		exit(99);
	}
}

/**
 * check100 - looks out for that file descriptors were closed properly
 * @check: checks if true or false
 * @fde: file descriptor
 *
 * Return: void
 */
void check100(int check, int fde)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fde);
		exit(100);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments that were passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fde_from, fde_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_permission;

	check97(argc);
	fde_from = open(argv[1], O_RDONLY);
	check98((ssize_t)fde_from, argv[1], -1, -1);
	file_permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fde_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_permission);
	check99((ssize_t)fde_to, argv[2], fde_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fde_from, buffer, 1024);
		check98(lenr, argv[1], fde_from, fde_to);
		lenw = write(fde_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		check99(lenw, argv[2], fde_from, fde_to);
	}
	close_to = close(fde_to);
	close_from = close(fde_from);
	check100(close_to, fde_to);
	check100(close_from, fde_from);
	return (0);
}
