SERVER_NAME	= server
CLIENT_NAME	= client
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ./libft/libft.a
HEADER 	= minitalk.h

SERVER_SRCS	= server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

ifdef WITH_BONUS
	CLIENT_OBJS	= $(CLIENT_BONUS_SRCS:.c=.o)
	SERVER_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
else
	CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
	SERVER_OBJS = $(SERVER_SRCS:.c=.o)
endif

all:	$(SERVER_NAME) $(CLIENT_NAME)

bonus:
	@make WITH_BONUS=1 all

$(LIBFT):
	make -C ./libft/

$(SERVER_NAME)	:	$(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER_NAME)
$(CLIENT_NAME)	:	$(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_NAME)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	make clean -C ./libft/
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_SRCS:.c=.o) $(SERVER_BONUS_SRCS:.c=.o)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
