
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_strdup(char *str)
{
	int i = 0;
	char *new;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
char	*get_next_line(int fd)
{
	int i = 0;
	static int	buf_pos = 0;
	static int	buf_read = 0;
	static char buf[BUFFER_SIZE];
	char	line[70000];
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_read = read(fd, buf, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_read <= 0)
				break;
		}
		line[i] = buf[buf_pos++];
		if (line[i++] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return(ft_strdup(line));
}
int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}

	close(fd);
	return 0;
}