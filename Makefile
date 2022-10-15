# NAME		= sever.a client.a

SRC			= client.c server.c
OBJS		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all			: server client

libft		:
			make bonus -C libft/

server		: server.o libft
		cp libft/libft.a server
		ar rcs server $^
# $(CC) -o $^

client		: client.o libft
		cp libft/libft.a client
		ar rcs client $^
# $(CC) -o $^
#$@ ターゲットファイル名　

clean		:
			rm $(OBJS)
			make -C libft clean

fclean		: clean
			rm -f server.a client.a libft/libft.a

re			: fclean all

.PHONY		: all clean fclean re bonus
