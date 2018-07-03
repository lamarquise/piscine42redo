#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*mel;

	if (!(mel = malloc(sizeof(t_list))))
		return (0);
	mel->next = NULL;
	mel->data = data;

	return (mel);
}

			//ok so you checked, you are in fact trying to add shit after the NULL or i guess replacing the NULL

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*fred;

	fred = *begin_list;
	if (*begin_list)
	{
		while (fred->next)
			fred = fred->next;
		fred->next = ft_create_elem(data);		//lets see if this works, else use fred->next
	}
	else
		*begin_list = ft_create_elem(data);
	
}

int		main(int argc, char **argv)
{
	t_list	*list;

	list = ft_create_elem(argv[1]);
	if (argc == 1)
		return (0);
	ft_list_push_back(&list, argv[2]);
	while (list)
	{
		while (*(char*)list->data)					//wait why the -> not . isnt it already a pointer???
			write(1, (char*)list->data++, 1);			//ok seriously, at some point take the time to get this
		write(1, "\n", 1);
		list = list->next;
	}
	return (0);
}
