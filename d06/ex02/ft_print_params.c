#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		c;

	c = 1;
	while (c < argc)
	{
		i = 0;
		while (argv[c][i])
		{
			ft_putchar(argv[c][i]);
			++i;
		}
		ft_putchar('\n');
		++c;
	}
	return (0);
}
