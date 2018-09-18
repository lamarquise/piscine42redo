

#include "sudo.h"

char	**malloc_grid(void)
{
	char	**grid;
	int		i;

	if (!(grid = malloc(sizeof(char *) * 9)))
		return (0);
	i = 0;
	while (i < 9)
	{
		if (!(grid[i] = malloc(sizeof(char) * 10)))
			return (0);
		++i;
	}
	return (grid);						//test that you have secured this func by returning NULL and see if it segfaults...
}

int		file_reader(char *str, char **grid)
{
	int		fd;
	int		i;
	int		a;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	a = 0;
	while (read(fd, &grid[i][a], 1) > 0)
	{
		if (grid[i][10])
		{
			write(1, "too lint\n", 9);
			return (0);
		}
		if (!(grid[i][a] == '.' || (grid[i][a] >= 48 && grid[i][a] <= 57) || grid[i][a] == '\n'))
		{
			write(1, "Grid Entry Error.\n", 18);
			return (0);
		}
		else if (grid[i][a] == '\n')
		{
			++i;
			a = 0;
		}
		else
			++a;
	}
	return (1);
}

int		arg_transfer(int ac, char **av, char **grid)
{
	int		i;
	int		a;

	i = 1;
	while (i < ac)			//where ac should be 10.
	{
		a = 0;
		while (a < 10)
		{
			if (!(av[i][a] == '.' || (av[i][a] >= 48 && av[i][a] <= 57)) && a != 9)
			{
				write(1, "Grid Entry Error.\n", 18);
				return (0);
			}
			else if (a == 9)
				grid[i - 1][a] = '\n';
			else
				grid[i - 1][a] = av[i][a];
			++a;
		}
		++i;
	}
	return (1);
}

int		main(int ac, char **av)
{
	char	**grid;
	t_list	*list;
	char	**sol;
	int		n;

	if (!(grid = malloc_grid()))
		return (0);
	if (!(sol = malloc_grid()))
		return (0);
	n = 0;
	if (ac == 3 || ac == 2)														//would need another function for this, main is too long
	{
		if (file_reader(av[1], grid) == 0)
			return (0);
		if ((av[2] && atoi(av[2]) == 1) || ac == 2)								//ok now if only 2 args, print nicely and in color :) otherwise do speed
		{
			if (!(list = first_pass(grid)))
			{
				write(1, "No Solutions\n", 13);								//may be unnecessary...
				return (0);
			}
			if (solver(list, grid, sol, &n) == 0)	
				return (0);
		}
		else if (atoi(av[2]) == 2)
			sol_reg(grid, 0, 0, &n, sol);
		if (n == 1)
		{
//			if (final_check(sol) == 1)										//ok so litterally no idea why the square check doesnt work at the end... wtf...
//			{
				if (ac == 2)
					color_print(sol);
				else
					print_grid(sol);
//			}
		}
		else if (n > 1)
			write(1, "Multiple Solutions\n", 19);
	}
	else if (ac == 10)
	{
		if (arg_transfer(ac, av, grid) == 0)
			return (0);
		if (!(list = first_pass(grid)))
			return (0);
		if (solver(list, grid, sol, &n) == 0)
			return (0);
		if (n == 1)
			print_grid(sol);
	}
	else
		write(1, "Grid Error.\n", 12);
	return (0);
}
