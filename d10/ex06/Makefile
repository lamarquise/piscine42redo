CC = gcc
CFLAGS = -Wall -Wextra -Werror -iquote includes

NAME = do-op

TEMP = arg_check.c do_op.c ft_putnbr.c ft_atoi.c main_do_op.c

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(TEMP) $(CFLAGS)

clean:
	/bin/rm -f $(NAME)

re:	clean all
