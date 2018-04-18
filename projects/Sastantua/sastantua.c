#include <unistd.h>
#include <stdlib.h>

int		ft_calc_max_height(int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

		//could have an outsourced function for printing spaces and one for printing the symbols, all dependent on size

int		d_spaces(int sizeish)			//ok das good, cumulatively adds extra spaces (same reason have var d) based on layer number
{	
	if (sizeish > 4)
		return (d_spaces(sizeish - 1) + (sizeish - 2) / 2);
	else if (sizeish == 4)
		return (1);
	return (0);	
}

void	print_spaces(int size, int height, int b)		//could prolly make this function's inner workings cleaner, but compared the rest it's spotless so whatever
{
	int		s;
	int		r;

	r = 0;
	if (size > 3)
		r = d_spaces(size);												//right workes because add spaces based on max, then substract less max for each level when relevant
		//r = (size - 3) + (size - 2) / 2;								//ok so this worked but wasn't cumulative
		if (b > 2)
			r = r - d_spaces(b + 1);									//holly shit that actually worked
			// r = r - ((b - 2) + (b - 3)/2;	 						//this is removed spaces by layer, same worked but wasn't cumulative
	s = ft_calc_max_height(size) - height + r + 2 * (size - b) - 2;		//no idea why need - 2????
	while (s > 0)
	{
		ft_putchar(' ');
		--s;
	}
}
int		ft_calc_max_height(int size)									//recursive finc like fibo, but do i really need it??? Yea i think so.
{
	if (size > 1)
		return (ft_calc_max_height(size - 1) + size + 2);
	else if (size == 1)
		return (3);
	return (0);
}

void	print_pyramid(int a, int b, int size, int height)
{
	int		n;
	int		printheight;

	n = a;
	printheight = ft_calc_max_height(size) - (((size + 1) / 2) - 1) * 2 ;	//end bit to account for extra door layers needed farther down pyramid
	ft_putchar('/');
	while (a > 0)
	{				 //may not need b == size - 1, cuz have height and printheight
		if (b >= 4 && height == (ft_calc_max_height(size) - printheight) / 2 + printheight && a == n / 2 - (size + 1) / 2 + 3) //+3 cuz is by default +/- 1 and then we adding
			ft_putchar('$');
		else if ((a >= n / 2 + 2 - (size + 1) / 2 && a <= n / 2 + (size + 1) / 2) && height >= printheight)
			ft_putchar('|');
		else
			ft_putchar('*');
		--a;
	}
	ft_putchar(92);															//ascii code for backslash, i can't even type it it fucks shit up in the comments
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int		a;			//# of stars
	int		b;			//the layer/size counter? yea i think so
	int		d;			//# of stars added every 2 levels
	int		height;

	height = 1;
	d = 0;
	b = 0;
	a = 1;
	while (b < size)
	{		//(a < 6 + b * (9 + b) + (d * (c - 3)))		had this in while, worked before i noticed wrong base # of *'s added, uses # *'s to say when stop printing rows
		while (height <= ft_calc_max_height(b + 1))		//got rid of c, used b instead down in if
		{
			print_spaces(size, height, b);				//had : a / 2 + 1 - b - d, as height (works but, a bit long)
			print_pyramid(a, b, size, height);			//a / 2 + 1 - b - d);  somehow that equation at the end actally works
			a = a + 2;
			++height;
		}
		if (b % 2 == 0 && b != 0)						//means b is even
			d = d + 2;									//the thing that makes it add 2 * every 2 levels, could prolly get rid of d and use c with some math instead, maybe
		a = a + 4 + d;
		++b;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		sastantua(atoi(argv[1]));
	return (0);
}
