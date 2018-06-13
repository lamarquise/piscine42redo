#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		c;

	i = 0;
	while (tab[i])
	{
		c = 0;
		while (tab[i][c])
		{
			ft_putchar(tab[i][c]);
			++c;
		}
		ft_putchar('\n');
		++i;
	}
}
