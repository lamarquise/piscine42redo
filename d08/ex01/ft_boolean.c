#include "ft_boolean.h"

void	ft_putstr(char *str)				//shit that's clean
{
	while (*str)
		write(1, str++, 1);					//do i put #include unistd.h in ft_boolean.h ???
}

t_bool	ft_is_even(int nbr)					//ok so is t_bool already defined as a thing?
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);						//Im assuming SUCCESS is a \n
}
