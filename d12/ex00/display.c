



#include "play.h"

int		display(char *name)
{
	char	c;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1) > 0)
	{
		write(1, &c, 1);
	}
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (display(av[1]) != 1)
			return (0);						//or some error message ???
	}
	else if (ac < 2)
		write(1, "File name missing.\n", 19);
	else
		write(1, "Too many arguments.\n", 20);
	return (0);
}
