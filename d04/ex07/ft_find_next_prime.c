#include <stdio.h>
#include <stdlib.h>

	// Iterative Methode:

int		ft_find_next_prime(int nb)
{
	int		c;

	c = 3;
	if (nb == 2 || nb == 3 || nb == 5)		// forego the 5?
		return (nb);
	else if (nb <= 1)
		return (2);
	else if (nb % 2 == 0)
		++nb;
	while (c < nb / 2)		//i guesss that works
	{
		if (nb % c == 0)
		{
			nb = nb + 2;
			c = 1;		//perhaps there's a more efficient way
		}
		c = c + 2;
	}
	return (nb);
}

	// Again, it works, but im fairly certain it's exactly what i did last time

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_find_next_prime(atoi(argv[1])));
	return (0);
}
