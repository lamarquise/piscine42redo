#include "ft_list.h"

			//cool it works, and while is still feel i need some time to work through exactly what goes on with these list things, i do feel fairly confident that i can
			//use them effectively, cool :)

int		ft_list_size(t_list *begin_list)
{
	int		i;

	while (begin_list)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_list	*lust;
	int		i;

	i = 1;
	lust = ft_create_elem(argv[1]);
	if (argc > 1)
	{
		while (i < argc - 1)
		{
			ft_list_push_front(&lust, argv[i + 1]);
			++i;
		}
		printf("%i\n", ft_list_size(lust));
		while (lust)
		{
			while (*(char*)lust->data)
				write(1, (char*)lust->data++, 1);
			write(1, "\n", 1);
			lust = lust->next;
		}
	}
	return (0);
}
