#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*mel;

	if (!(mel = malloc(sizeof(t_list))))
		return (0);
	mel->data = data;
	mel->next = NULL;

	return (mel);
}
