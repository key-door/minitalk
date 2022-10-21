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

client		: printf $(OBJ_CLIENT)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

server		: printf $(OBJ_SERVER)
			$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(NAME_SERVER)

printf		:
			make -C $(PRINTFDIR)
			mv $(PRINTFDIR)$(PRINTF) ./

clean		:
			rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
			make clean -C $(PRINTFDIR)

fclean		: clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER) $(PRINTF)

re			: fclean all

.PHONY		: all clean fclean re libft printf
