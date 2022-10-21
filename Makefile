NAME		= minitalk

SRC_CLIENT	= client.c 
SRC_SERVER	= server.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_CLIENT	= client
NAME_SERVER = server

PRINTFDIR		= ft_printf/
PRINTF		= libftprintf.a



all			: $(NAME)

$(NAME)		: server client

client		: $(OBJ_CLIENT) printf
			$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(PRINTF)

server		: $(OBJ_SERVER) printf
			$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_CLIENT) $(PRINTF)
			ar rcs server $^

printf		:
			make -C printf
			mv $(PRINTFDIR)$(PRINTF) ./

clean		:
			rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
			make clean -C $(PRINTFDIR)

fclean		: clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER) $(PRINTF)

re			: fclean all

.PHONY		: all clean fclean re libft printf
