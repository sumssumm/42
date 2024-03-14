NAME		=	replace
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

HEADER 		=	.

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
%.o	:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf test.replace

re: 
	make fclean
	make all

.PHONY : all clean fclean re