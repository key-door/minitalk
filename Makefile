NAME		= minitalk

SRC_CLIENT	= client.c
SRC_SERVER	= server.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_CLIENT	= client
NAME_SERVER = server

LIBFTDIR	= libft/
LIBFT		= libft.a



all			: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME)		: all

client		: $(OBJ_CLIENT) libft
			$(CC) $(CFLAGS) $< $(LIBFT) -o $@

server		: $(OBJ_SERVER) libft
			$(CC) $(CFLAGS) $< $(LIBFT) -o $@

libft		:
			make bonus -C $(LIBFTDIR)
			cp $(LIBFTDIR)$(LIBFT) ./

clean		:
			rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
			make clean -C $(LIBFTDIR)

fclean		: clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER) $(LIBFT)

re			: fclean all

.PHONY		: all clean fclean re libft
