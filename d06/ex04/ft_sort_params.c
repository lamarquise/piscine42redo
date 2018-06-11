#include <unistd.h>

			//go look at d03 ex09 and d05 ex03
			//Creds go to Pascal

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		compare(char *s1, char *s2)						//You "borrowed" this from Pascal, give him credit
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;								//didnt know this was possible but cool :)
	}
	return (*s1 - *s2);
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*c;
	int		b;
	
	i = 0;
	while (++i < argc - 1)					//need - 1 because last param is caught by + 1 below
	{
		while (compare(argv[i], argv[i + 1]) > 0)
		{
			c = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = c;
			if (i != 1)									//ok so i could make this shorter, but this way is faster
				--i;
		}
	}
	i = 0;
	while (++i < argc)
	{
		b = 0;
		while (argv[i][b] != '\0')						//and i could make this shorter, but i don't feel like making a putstr
		{
			ft_putchar(argv[i][b]);
			++b;
		}
		ft_putchar('\n');
	}
	return (0);
}
