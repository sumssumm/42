NAME		=	phonebook
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Contact.cpp Phonebook.cpp
OBJS		=	$(SRCS:.c=.o)

HEADER 		=	Contact.hpp Phonebook.hpp

all:	$(NAME)

$(NAME):	$(OBJS)
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