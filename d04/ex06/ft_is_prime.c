#include <stdlib.h>
#include <stdio.h>

	// Iterative Methode:

int		ft_is_prime(int nb)
{
	int		c;

	c = 3;
	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	else if (nb <= 1 || nb % 2 == 0)
		return (0);
	while (c < nb / 2)
	{
		if (nb % c == 0)
			return (0);
		c = c + 2;
	}
	return (1);		//seems dangerours, my default being positive
}

	// Looks like it works, i'm still skeptical but perhaps i should move on to more important problems

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_is_prime(atoi(argv[1])));
	return (0);
}
