NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIB			= -Llibft -lft
PRINTF		= -Lft_printf -lftprintf

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
	make -C ./libft/ && make -C ./ft_printf/
	$(CC) $(OBJS) $(MLX) $(LIB) $(PRINTF) -o $(NAME) -fsanitize=address

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/ && make clean -C ./ft_printf/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/ && make fclean -C ./ft_printf/

re: 
	make fclean
	make all

.PHONY : all clean fclean re 
