NAME		=	philo
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -pthread

SRCS		=	philo.c \
				utils.c \
				data.c	\
				philo.c	\
				


OBJS		=	$(SRCS:.c=.o)

HEADER		=	philo.h

all:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re 
