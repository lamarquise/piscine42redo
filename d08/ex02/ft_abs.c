#include "ft_abs.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ABS(atoi(argv[1])));
	return (0);
}
