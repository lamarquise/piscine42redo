


#include "sudo.h"






t_list		*create_elem(int x, int y, char **grid)
{
	t_list		*new;

//	printf("OMG\n");

	if (!(new = malloc(sizeof(t_list))))											//ok so apparently this malloc is the one that fails...
		return (0);
	new->next = NULL;
	new->x = x;
	new->y = y;
//	printf("hello.\n");
	if (ops_filler(new, grid) != 1)
		return (0);
	
//	printf("hi???\n");

	return (new);
}

int			insert_sort(t_list **begin_list, int x, int y, char **grid)									//t_list *new_elem)
{	
	t_list		*par;
	t_list		*tmp;
	t_list		*new_elem;

	if (!(new_elem = create_elem(x, y, grid)))
		return (0);
	if (!(*begin_list))
	{
//		printf("1st elem X: %i Y: %i\n", new_elem->x, new_elem->y);

		*begin_list = new_elem;
		return (1);
	}
	par = *begin_list;

//	printf("more elems\n");

	if (new_elem->nb <= par->nb)
	{
		new_elem->next = par;
		*begin_list = new_elem;
		return (1);
	}
	while (par->next && new_elem->nb > par->nb)		//may have to go over this again...
		par = par->next;
	tmp = par->next;			//or possibly swich the nexts of tmp
	par->next = new_elem;
	new_elem->next = tmp;

//	*begin_list = 
	
//	printf("elem added X: %i Y: %i\n", new_elem->x, new_elem->y);

	return (1);
}









