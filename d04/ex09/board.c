#include <stdio.h>
#include <unistd.h>

/*
....1...2   3
..____________
..|   |   |
1.| X |   |
..|___|___|
. |   |
2 | X |
  |___|

  1 2 3 4 5 6 7 8
 ------------------
 |x| | | | | | | |
 --------------
 | | | | |X|

*/


	// Wait WTF, why am i doing this according to the norm, i know how to use write properly

void	top()
{
	int		a;

	a = 0;
	write(1, "  |", 3);
	while (a < 8)
	{
		write(1, "   |", 4);
		++a;
	}
	write(1, "\n", 1);

}

void	row(int row, int val)		//val = grid[row]
{
	int		a;						// i think i need a itoa, int to char
	char	r;

	a = 1;
	r = row + 48;
	write(1, &r, 1);
	write(1, " ", 1);
	while (a <= 8)
	{
		if (a == val)
			write(1, "| X ", 4);
		else
			write(1, "|   ", 4);
		++a;
	}
	write(1, "|\n", 2);
}

void	bottom()		//could prolly turn top() and bottom() into a single func, where swap "   " and "___" depending
{
	int		a;

	a = 0;
	write(1, "  |", 3);
	while (a < 8)
	{
		write(1, "___|", 4);
		++a;
	}
	write(1, "\n", 1);
}

void	ft_grid(int *grid)		//prolly gonna have to input the gird, int *grid
{
	int		a;
	char	b;

	a = 1;
	write(1, " ", 1);
	while (a <= 8)
	{
		b = a + 48;
		write(1, "   ", 3);
		write(1, &b, 1);		//i know there's a way to combine these but i don't know what it is yet
		++a;
	}
	write(1, "\n  ", 3);
	while (a < 42)			//cuz need _ but don't feel like reinitializing a
	{
		write(1, "_", 1);
		++a;
	}
	write(1, "\n", 1);

	//this is the part where i fit the grid in

	a = 0;
	while (a < 8)
	{
		top();
		row(a + 1, grid[a]);
		bottom();
		++a;
	}

}		//could call on seperate functions, like one to do wall, one to do square (une case)
/*
int		main()
{
	ft_grid();
	return (0);
}

*/
