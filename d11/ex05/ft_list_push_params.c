#include "ft_list.h"

		//yea ok so i could make it print in the other order, since it's unclear im just gonna assume this is good enough and i could do the other if i needed to, cool.
		//WAIT NVM, i'm pretty sure i got it right.


t_list	*ft_create_elem(void *data)
{
	t_list	*mel;

	mel = malloc(sizeof(t_list));
	mel->next = NULL;
	mel->data = data;
	return (mel);
}
		
		//ok so it's like the main.c with push to front combo you've been using, except in a more inconvignient format

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	t_list	*ret;
	int		i;

	i = 1;
	ret = ft_create_elem(av[0]);
	while (i < ac)
	{
		tmp = ft_create_elem(av[i]);
		tmp->next = ret;
		ret = tmp;
		++i;
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	t_list	*new_elem;
	if (argc > 1)
	{
		new_elem = ft_list_push_params(argc, argv);
		while (new_elem)
		{
			while (*(char*)new_elem->data)
				write(1, (char*)new_elem->data++, 1);
			write(1, "\n", 1);
			new_elem = new_elem->next;
		}
	}
	return (0);
}
