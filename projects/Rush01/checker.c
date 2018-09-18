

#include "sudo.h"

int			check_line(char **grid, int x, int y, int i)
{
	int		c;

	c = 0;
	while (c < 9)		//line
	{
		if (grid[y][c] == i + 49 && c != x)			//49 cuz + 1 since vals from 1 to 9;
			return (0);
		++c;
	}
	return (1);
}

int			check_col(char **grid, int x, int y, int i)
{
	int		c;

	c = 0;
	while (c < 9)
	{
		if (grid[c][x] == i + 49 && c != y)
			return (0);
		++c;
	}
	return (1);
}

int			check_square(char **grid, int x, int y, int i)
{
	int		c;
	int		a;

	c = 0;
	while (c < 3)
	{
		a = 0;
		while (a < 3)																						//ok so it's not happy...
		{
			if (grid[(y / 3) * 3 + c][(x / 3) * 3 + a] == i + 49 && c != y && a != x)
				return (0);
			++a;
		}
		++c;
	}
	return (1);
}

int			ops_filler(t_list *elem, char **grid)
{
	int			*ops;
	int			i;
	int			c;

	if (!(ops = malloc(sizeof(int) * 9)))
	{
		write(1, "Malloc Failure\n", 15);
		return (0);
	}
	i = 0;
	c = 0;
	while (i < 9)
	{
		if (check_line(grid, elem->x, elem->y, i) == 1 &&
			check_col(grid, elem->x, elem->y, i) == 1 &&
			check_square(grid, elem->x, elem->y, i) == 1)
		{
			ops[i] = 1;
			++c;
		}
		else
			ops[i] = 0;
		++i;
	}
	if (c == 0)
	{
		write(1, "Grid has no solutions.\n", 23);
		return (0);
	}
	elem->nb = c;
	i = 0;
	while (i < 9)
	{	
		elem->ops[i] = ops[i];												//could go back to this being shorter...
		++i;
	}
	return (1);
}

t_list		*first_pass(char **grid)
{
	int			y;
	int			x;
	t_list		*list;
//	t_list		*tmp;
//	int			c;

	y = 0;
	list = NULL;
	while (y < 9)
	{
		x = 0;
		while (x < 9)		//9 because we want to ignore the '\n's seems reasonable
		{
			if (!(grid[y][x] >= 48 && grid[y][x] <= 57))
			{
				if (insert_sort(&list, x, y, grid) != 1)
				{
					write(1, "Malloc or something error\n", 26);
					return (0);
				}
			}
			++x;
		}
		++y;
	}
	return (list);
}
