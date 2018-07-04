#include "ft_list.h"

			//I mean it does something, i think this is how it's ment to work

t_list	*ft_create_elem(void *data)
{
	t_list	*mel;

	mel = malloc(sizeof(t_list));
	mel->next = NULL;
	mel->data = data;

	return (mel);
}
/*
t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*tmp;

	tmp = begin_list;
	tmp->next = NULL;
	return (tmp);			//it can't be that easy can it???
}
*/
//Alternative version that might be right

//yea i don't know which to use, they both work, just to different ends, the sujet syntax was super vague and unclear

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *tmp;

	tmp = begin_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
