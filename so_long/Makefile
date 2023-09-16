NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIB			= -Llibft -lft

SRCS		=	so_long.c \
				game.c \
				image.c \
				map.c \
				check.c	\
				key.c \
				path.c
				

OBJS		= $(SRCS:.c=.o)

HEADER 	= .

all:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C ./libft/
	$(CC) $(OBJS) $(MLX) $(LIB) -o $(NAME)

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
