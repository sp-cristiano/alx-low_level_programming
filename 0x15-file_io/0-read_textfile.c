#include "main.h"

/**
 * read_textfile - this function will reads a text file
 * and prints the letters
 * @filename: this is the filename.
 * @letters: this is the numbers of letters printed.
 *
 * Return: it will return 0 if numbers of letters printed fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(fd, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(fd);

	free(buf);

	return (nwr);
}
