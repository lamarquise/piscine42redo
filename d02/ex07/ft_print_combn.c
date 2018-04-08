#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *tab, int	n)
{
	int		a;

	a = 0;
	while (a < n)
	{
		ft_putchar(tab[a] + 48);
		++a;
	}
	if (tab[0] != 9 - n + 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int		tab[n];
	int		counter;

	counter = -1;
	while (++counter < n)
		tab[counter] = counter;
	--counter;		//the most important part of your code that you keep forgetting about
	while (tab[0] <= 9 - n + 1)		//Hey idiot, 9 - n + 1 = 10 - n, DUHHHH
	{
		ft_print(tab, n);
		while (tab[counter] == 9 - n + counter + 1 && counter != 0)		//so this while moves the counter down the table until it finds a non maxed out value
			--counter;
		++tab[counter];													//incriment that value
		while (counter < n - 1)											//reinitializes all values after the one that was just increased
		{
			tab[counter + 1] = tab[counter] + 1;
			++counter;
		}
	}
}

int		main(int argc, char *argv[])
{
	int		a;

	a = atoi(argv[1]);
	if (argc == 1)
		return (0);
	if (argc > 2)
		return (0);
	if (argc == 2 && a > 0 && a < 11)
		ft_print_combn(a);
	return (0);
}
