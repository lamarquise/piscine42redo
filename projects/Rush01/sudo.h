

#ifndef SUDO_H
# define SUDO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct	s_list
{
	int				x;
	int				y;
	int				ops[9];
	int				nb;
	struct s_list	*next;
}				t_list;

t_list			*create_elem(int x, int y, char **grid);
int				insert_sort(t_list **begin_list, int x, int y, char **grid);
t_list			*first_pass(char **grid);
int				check_square(char **grid, int x, int y, int i);
int				check_col(char **grid, int x, int y, int i);
int				check_line(char **grid, int x, int y, int i);
int				solver(t_list *list, char **grid, char **sol, int *n);
void			print_grid(char **sol);
int				ops_filler(t_list *elem, char **grid);
void			sol_reg(char **grid, int x, int y, int *n, char **sol);
void			color_print(char **sol);
int				final_check(char **grid);



#endif
