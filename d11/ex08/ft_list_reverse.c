#include "ft_list.h"

		//ok i get that there could be a malloc problem, but why is the error on the begin list next then?????

		//ok get back to this when have the internet...

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*oth;

//	tmp = malloc(sizeof(t_list));
//	oth = malloc(sizeof(t_list));
	tmp = *begin_list;				//wait star? cuz that way only the first elem of begin list, not pointer to all of b list
	while (*begin_list)				
	{
		*begin_list = *begin_list->next;		//WHY the FUCK isnt this line working?
		oth = *begin_list;
		oth->next = tmp;
		tmp = oth;
	}
	*begin_list = tmp;
}
/*
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (begin_list)				//ok so it would seem this method im kinda considering, were i to follow it to fruition, would probably look somthing like switching the
	{								//first with the last pointers, then moving in one closer on each end, and so on until get to middle... yea i fucking hate that.
		*begin_list = begin_list
	}
}	*/
