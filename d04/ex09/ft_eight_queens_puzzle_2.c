#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//
//		OK so i got it, but i honestly still don't fully understand how it works, so haven't cleaned anything up yet
//	may just leave as is, and try to redo without looking for ex08

void	top();
void	row(int row, int val);
void	bottom();
void	ft_grid(int *grid);

int		m;

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

int		ft_reality_check(int *grid, int i, int c)	//so checks if a particular option is valid relative to rest of grid, but doesn't change that option
{		//i is pos of testing val, c is val
	int		a;

	a = 1;
	while (a <= i)
	{
		if (c == grid[i - a] || c == grid[i - a] + a || c == grid[i - a] - a)		//prolly can find way to get it to work without c == 0
			return (0);
		++a;
	}
	return (c);		//thinking about using this func to write in the grid directly
}

void		ft_generate(int *grid, int i, int y, int n)		//not sure what the return should be, work out later, wait wait, maybe i don't need a return
{
	int		c;

	c = 1;
	//ft_print(grid);
	if (i == 8)		//end condition
		return;		//was just return, this is where i could print
	while (c <= 8)
	{
		/*if (ft_reality_check(grid, i, c) == 0 && c <= 8)
		{
			++c;
			ft_generate(grid, i);
		} */
		if (ft_reality_check(grid, i, c) != 0 && i < 8)
		{
			grid[i] = c;
			if (i == 7)		//change this && if you want to print all solutions
			{
				if (y == 1)
					ft_print(grid);
				else if (y == 2)
					if (m == n)
					{
						ft_print(grid);
						ft_grid(grid);
					}
				++m;
			}
			ft_generate(grid, i + 1, y, n);			//added return so it would only print 1 answer
		}									//So not working perfectly yet, this is the part where you add backtracking
		++c;
	}
	//if (ft_reality_check(grid, 7, grid[7]) != 0)
	//	ft_print(grid);
	//return (0);
}

/*
	if ((grid[i] == grid[c]) || (grid[i] == grid[c] - i - c) || (grid[i] == grid[c] + i - c) || (grid[i] == 0))  //i get the sense this will only chech Qs relative to Q0, (i + 1) or just i??? not sure
	{
		++grid[i];
		ft_generate(grid, i, c);
	}
	//else if ((grid[c + 1] != 0) && c < 8 && c < i)		//the != 0 so doesnt get ahead of itself
	//{
	//	++c;
	//	ft_generate(grid, i, c);	//my thought process was fist increment, then check other Qs, but don't need to go back because if bad in 1 place doesn't matter, it just bad, so don't need to re check.
//	}
	else if (i < 8)
	{
		++i;
		ft_generate(grid, i, c);
	}
	//return (grid, i); 		yea that's not gona work with this return
*/

void	ft_eight_queens_puzzle_2(int y, int n)
{
	int		grid[8] = {0,0,0,0,0,0,0,0};	//not sure the norm will let me do this
//	int		i;
	
//	i = 0;
	m = 0;
	ft_generate(grid, 0, y, n);		//whatever starting with 1, ok so might need to change what im sending to just the grid, no i, so can have a return
	if (y == 1)
		printf("\n%i", m);
	/*while (i < 8)
	{
		printf("%i\n", grid[i]);
		++i;
	}*/
}

int		main(int argc, char *argv[])		//ok so the first imput is either 1 or 2 and sais either do ex09 or my side project and input 2 is for side project
{
	if (argc == 2)
		ft_eight_queens_puzzle_2(atoi(argv[1]), 1);
	if (argc == 3)
		ft_eight_queens_puzzle_2(atoi(argv[1]), atoi(argv[2]));
	return (0);
}





