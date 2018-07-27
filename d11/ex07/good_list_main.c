#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*mel;

	mel = malloc(sizeof(t_list));
	mel->next = NULL;
	mel->data = data;

	return (mel);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

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

	i = 2;
	lust = ft_create_elem(argv[2]);
	if (argc > 1)
	{
		while (i < argc - 1)
		{
			ft_list_push_front(&lust, argv[i + 1]);
			++i;
		}
		printf("%i\n", ft_list_size(lust));

		lust = ft_list_at(lust, atoi(argv[1]));								//insert func here
//		ft_list_clear(&lust);			//i think
//		printf("%i\n", ft_list_size(lust));
		while (lust)
		{
			while (*(char*)lust->data)
				write(1, (char*)lust->data++, 1);
			write(1, "\n", 1);
			lust = lust->next;
		}
/*		ft_list_clear(&lust);
		while (lust)
		{
			while (*(char*)lust->data)
				write(1, (char*)lust->data++, 1);
			write(1, "\n", 1);
			lust = lust->next;
		}	*/
	}
	return (0);
}
