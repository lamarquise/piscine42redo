



#include "sudo.h"

int			final_check(char **grid)
{
	int		x;
	int		y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			printf("%c ", grid[y][x]);
/*			if (!(check_line(grid, x, y, grid[y][x] - 49) == 1 &&
				check_col(grid, x, y, grid[y][x] - 49) == 1 &&
			 	check_square(grid, x, y, grid[y][x] - 49) == 1))
			{
				write(1, "Invalid Grid :(\n", 16);
				return (0);
			}
*/			if (!(check_line(grid, x, y, grid[y][x] - 49) == 1))
			{
				printf("line\n");
				return (0);
			}
			if (!(check_col(grid, x, y, grid[y][x] - 49) == 1))
			{
				printf("col\n");
				return (0);
			}
			if (!(check_square(grid, x, y, grid[y][x] - 49) == 1))
			{
				printf("square\n");
				return (0);
			}
			++x;
		}
		printf("\n");
		++y;
	}
	return (1);
}



