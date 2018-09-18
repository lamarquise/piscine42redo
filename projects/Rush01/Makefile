




NAME	=	sudoku

CC		=	gcc

CFLAG	=	-Wall -Wextra -Werror

SRCS	=	main_sudo.c		\
			checker.c		\
			list_gen.c		\
			solver.c		\
			more_room.c


all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(CFLAG) $(SRCS)

clean:
	rm -f $(NAME)

re: 	clean all


