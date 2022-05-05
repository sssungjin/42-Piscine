CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op

INCDIR = ex05

OBJS = $(SRCS:.c=.o)

all: 
	$(CC) $(CFLAGS) -o $(NAME) main.c my_func.c oper.c -I $(INCDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
