NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIB			= -Llibft -lft

SRCS		= philo.c

OBJS		= $(SRCS:.c=.o)

HEADER 	= philo.h

all:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
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
