#include <stdio.h>
#include <stdlib.h>

int		ft_fibonacci(int index)
{
	if (index > 1)
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));		//ok i thinki i kinda get recursion, lets see if i can describe it better somewhere else
	else if (index == 1)
		return (1);
	else if (index == 0)
		return (0);
	return (-1);			// -1 I guess since 0 is a valid return???
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_fibonacci(atoi(argv[1])));
	return (0);
}
