#include "ft_list.h"

		//I mean i think it works, seems so anyway...
		//But let's be real, i have no idea if it actually works, so many things could bo wrong, my tests are far from extensive, for all i know, only the first pointer to 
		//list is made NULL and the rest is all still there...

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;		//does it need to be a pointer, yea i think so, cuz of t_list param restrictions
	while (*begin_list)
	{
		tmp = *begin_list;
		free(*begin_list);				//is this good enough, or should i do it stages, like one for next = NULL and one for free data ???
		*begin_list = tmp->next;
	}
}
