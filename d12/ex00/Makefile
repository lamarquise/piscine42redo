



NAME	=	ft_display_file

CC		=	gcc

CFLAG	=	-Wall -Wextra -Werror

SRCS	=	display.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
	$(CC) -c -o $@ $< $(CFLAG)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(CFLAG) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
