#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void check_argument_count(int argc);
void check_read(int read_value, char *filename);
void check_write(int write_value, char *filename);
void check_close(int close_value, int fd);

int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t read_count, write_count;
    char buffer[BUFFER_SIZE];
    mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    check_argument_count(argc);

    fd_from = open(argv[1], O_RDONLY);
    check_read(fd_from, argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
    check_write(fd_to, argv[2]);

    while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_count = write(fd_to, buffer, read_count);
        check_write(write_count, argv[2]);
    }

    check_close(close(fd_to), fd_to);
    check_close(close(fd_from), fd_from);

    return 0;
}

void check_argument_count(int argc)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        exit(97);
    }
}

void check_read(int read_value, char *filename)
{
    if (read_value == -1) {
        fprintf(stderr, "Error: Can't read from file %s\n", filename);
        exit(98);
    }
}

void check_write(int write_value, char *filename)
{
    if (write_value == -1) {
        fprintf(stderr, "Error: Can't write to file %s\n", filename);
        exit(99);
    }
}

void check_close(int close_value, int fd)
{
    if (close_value == -1) {
        fprintf(stderr, "Error: Can't close file descriptor %d\n", fd);
        exit(100);
    }
}

