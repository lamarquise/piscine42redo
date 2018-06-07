#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 1)
	{
		while (argv[0][i] != '\0')			//ok so if i don't have the [i], it prints a whole bunch of stuff and then segfaults, cool
		{
			ft_putchar(argv[0][i]);
			++i;
		}
	}
	return (0);
}
