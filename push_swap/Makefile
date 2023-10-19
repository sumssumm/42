NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIB			= -Llibft -lft

SRCS		=	push_swap.c		\
				operation.c		\
				operation2.c	\
				operation3.c	\
				stack.c			\
				sort.c			\

OBJS		= $(SRCS:.c=.o)

HEADER 	= .

all:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C ./libft/
	$(CC) $(OBJS) $(LIB) -o $(NAME) -fsanitize=address

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/

re: 
	make fclean
	make all

.PHONY : all clean fclean re 
