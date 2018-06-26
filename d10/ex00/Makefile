NAME = libft.a

G = gcc -Wall -Wextra -Werror

L = ../../d06/ex00/

SRC = $(L)ft_putchar.c $(L)ft_putstr.c $(L)ft_strcmp.c $(L)ft_strlen.c $(L)ft_swap.c

all: $(NAME)

$(NAME):
	$(G) -c $(SRC)
	ar rc $(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
