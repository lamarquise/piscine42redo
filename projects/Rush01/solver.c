


#include "sudo.h"

//regular recusive, but then add the linked list to go throught more efficiently.
//rather than increaseing x or y, increase pos in linked list

/*
___________________
|   |
| 1 | 2 3 5 6 8 9 0 9|
|___|
| 2 | 4 5 6 7 8 8 5



*/


void		color_print(char **sol)
{
	int		i;
	int		a;

	i = 0;
	printf("_____________________________________\n");
	while (i < 9)
	{
		a = 0;
		printf("|   |   |   |   |   |   |   |   |   |\n|");
		while (a < 9)
		{
			printf(" \033[38;5;%im%c\033[0m |", sol[i][a] - 49 + 7, sol[i][a]);
			++a;
		}
		printf("\n|___|___|___|___|___|___|___|___|___|\n");
		++i;
	}
//	write(1, "___________________\n", 20);
}

void		print_grid(char **sol)
{
	int		i;

	i = 0;
	while (i < 9)
	{
			write(1, sol[i], 10);
			++i;
	}
}

int			check_again(t_list *node, char **grid, int i)
{
	if (check_line(grid, node->x, node->y, i) == 1 &&
		check_col(grid, node->x, node->y, i) == 1 &&
		check_square(grid, node->x, node->y, i) == 1)
	{
			return (1);
	}
	return (0);
}

int			copy_sol(char **grid, char **sol)
{
	int		i;
	int		a;

	i = 0;
	while (i < 9)
	{
			a = 0;
			while (a < 10)
			{
					sol[i][a] = grid[i][a];
					++a;
			}
			++i;
	}
	return (1);
}
/*
int			full_grid(char **grid)
{
	int		i;
	int		a;

	i = 0;
	while (i < 9)
	{
			a = 0;
			while (a < 9)
			{
					if (!(grid[i][a] >= 49 && grid[i][a] <= 57))
							return (0);
					++a;
			}
			++i;
	}
	return (1);
}
*/
int			solver(t_list *list, char **grid, char **sol, int *n)
{
	int		c;

	c = 0;
	if (!list)
	{
		++*n;
		if (copy_sol(grid, sol) != 1)
			return (0);
		return (1);
	}
	while (c < 9 && list)												//could have an else, but either way need to be like you're done, so be done, the rest of the 
	{																	//backtracking is still underway so you don't have to worry about it not finding the multiple sols
		if (list->ops[c] == 1 && check_again(list, grid, c) == 1)
		{
			grid[list->y][list->x] = c + 49;
			solver(list->next, grid, sol, n);
			grid[list->y][list->x] = '.';
		}
		++c;
	}
	return (1);
}


int			check_it(char **grid, int x, int y, int i)
{
	if (check_line(grid, x, y, i) == 1 &&
		check_col(grid, x, y, i) == 1 &&
		check_square(grid, x, y, i) == 1)
	{
		return (1);
	}
	return (0);
}

void		sol_reg(char **grid, int x, int	y, int *n, char **sol)
{
	int		c;

	c = 0;
	if (y > 8)
	{
		if (copy_sol(grid, sol) != 1)
			return ;
		++*n;
	}
	else if (grid[y][x] >= 49 && grid[y][x] <= 57)
	{
		if (x < 8)
			sol_reg(grid, x + 1, y, n, sol);
		else
			sol_reg(grid, 0, y + 1, n, sol);
	}
	else
	{
		while (c < 9)
		{
			if (check_it(grid, x, y, c) == 1)
			{
				grid[y][x] = c + 49;
				if (x < 8)
					sol_reg(grid, x + 1, y, n, sol);
				else
					sol_reg(grid, 0, y + 1, n, sol);
				grid[y][x] = '.';
			}
			++c;
		}
	}
}









