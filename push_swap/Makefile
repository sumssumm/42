NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIB			= -Llibft -lft

SRCS		=	push_swap.c		\
				operation.c		\
				operation2.c	\
				operation3.c	\
				stack.c			\
				sort_small.c	\
				check_errors.c	\
				utils.c			\
				utils2.c		\
				sort_big.c		\
				sort_big2.c		\
				sort_big3.c		\
				free.c			\

OBJS		= $(SRCS:.c=.o)

HEADER 	= .

all:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C ./libft/
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
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
