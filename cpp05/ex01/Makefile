NAME		=	Bureaucrat
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Bureaucrat.cpp Form.cpp
OBJS		=	$(SRCS:.cpp=.o)

HEADER 		=	Bureaucrat.hpp Form.hpp

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
%.o	:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re