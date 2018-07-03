#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

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
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;				//because, created new elem, which took begin list and added data before, but now have to change begin list, cuz pointers... makes
}										//sense

int		main(int argc, char **argv)
{
	t_list *list;

	list = ft_create_elem(argv[1]);
	if (argc != 3)
		return (0);
	ft_list_push_front(&list, argv[2]);
	while (list)
	{
		while (*(char*)list->data)
			write(1, (char*)list->data++, 1);
		write(1, "\n", 1);
		list = list->next;			//why list not *list???
	}
	return (0);
}
