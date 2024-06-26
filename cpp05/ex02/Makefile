NAME		=	Bureaucrat
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

SRCS		=	main.cpp \
					Bureaucrat.cpp \
					AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp
OBJS		=	$(SRCS:.cpp=.o)

HEADER 		=	Bureaucrat.hpp \
						AForm.hpp \
						ShrubberyCreationForm.hpp \
						RobotomyRequestForm.hpp \
						PresidentialPardonForm.hpp

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