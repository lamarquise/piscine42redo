#include <stdlib.h>		//i think
#include <unistd.h>

		//ok wait do i write another func like void(*f)(int) to do the printing, or do i assign the destination of the pointer to func in main, i think the latter...
		//yea seems to have worked, somehow...

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int n)
{
	if (n >= 10)
		ft_putint(n / 10);
//	ft_putchar(n % 10 + 48);
//	ft_putchar('\n');
	n = n % 10 + 48;									//
	write(1, &n, 1);								//ok so this doesn't work, possibly because n is an int, compiler sais i didn't cast, which obvi, but fair...
}

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int		i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);					// + 5);	kinda cool... it worked at least...
		ft_putchar('\n');						//shouldnt be here but for the sake of readability
		++i;									//wait is that it ???
	}
}

int		main(int argc, char **argv)
{
	int		*tab;
	void	(*f)(int);
	int		i;

	f = &ft_putint;
	if (argc != 1)
	{
		tab = malloc(sizeof(int) * argc - 1);		//pretty sure there's no need to cast the tab, its already an int
		while (i < argc - 1)
		{
			tab[i] = atoi(argv[i + 1]);
			++i;
		}
		ft_foreach(tab, argc - 1, f);			//could have just called &putnumber, or i guess &putint here, damn, that's toight!!!
	}
	return (0);
}
