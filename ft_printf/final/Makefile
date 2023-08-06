NAME		= libftprintf.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -c

SRCS		=	./ft_printf.c				\
				./print_char.c				\
				./print_str.c				\
				./print_ptr.c				\
				./print_decimal.c			\
				./print_unsigned_decimal.c	\
				./print_hex.c				\
				./check_error.c				\

OBJS		= $(SRCS:.c=.o)

HEADER 	= .

OBJS 		= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $@ $^

%.o	:	%.c
	$(CC) $(CFLAGS) $< -o $@ -I$(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
