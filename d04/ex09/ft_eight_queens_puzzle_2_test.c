#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *grid)
{
	int		a;

	a = 0;
	while (a < 8)
	{
		ft_putchar(grid[a] + 48);
		++a;
	}
	ft_putchar('\n');
}

int		ft_reality_check(int *grid, int i, int c)
{
	int		a;

	a = 1;
	while (a <= i)											//Holy shit, not calibrating this properly really fucks things up!
	{					//if a = 0 or (a < i) or both, shit be wild.
		if (grid[i - a] == c || grid[i - a] + a == c || grid[i - a] - a == c)
			return (0);
		++a;
	}
	return (c);
}

void		ft_generate(int *grid, int i, int *n)
{
	int		c;

	c = 1;
	if (i == 8)
		return;
	while (c <= 8)
	{
		if (ft_reality_check(grid, i, c) != 0 && i < 8)
		{
			grid[i] = c;
			if (i == 7)
			{
				ft_print(grid);
				++*n;
			}
			ft_generate(grid, i + 1, n);
		}
		++c;
	}
}

void	ft_eight_queens_puzzle_2()
{
	int		grid[8];			// = {0,0,0,0,0,0,0,0};
	int		n;

	n = 0;
	while (n < 8)
		grid[n++] = 0;
	n = 0;
	ft_generate(grid, 0, &n);
	printf("Number of Solutions: %i\n", n);
}

int		main()
{
	ft_eight_queens_puzzle_2();
	return (0);
}





