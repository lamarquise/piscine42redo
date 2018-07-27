#include "ft_list.h"

		//seems to work, it does something at least, keep in mind, the first element is called using 1, not 0 as in arrays.

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int		i;

	i = 1;
	while (i < nbr)
	{
		if (!begin_list)
			return (NULL);					//not an especially extensive safety net, but whatever, i have no internet, so fuck off.
		begin_list = begin_list->next;
		++i;
	}
	return (begin_list);
}
