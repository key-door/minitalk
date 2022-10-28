NAME		= minitalk
NAME_CLIENT	= client
NAME_SERVER = server

SRC_CLIENT	= client.c
SRC_SERVER	= server.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFTDIR	= libft/
LIBFT_NAME		= libft.a



all					: $(NAME)

$(NAME)				: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT)		: $(OBJ_CLIENT)
						make libft
						$(CC) $(CFLAGS) $< -Llibft -lft -o $@

$(NAME_SERVER)		: $(OBJ_SERVER)
						make libft
						$(CC) $(CFLAGS) $< -Llibft -lft -o $@

libft				:
						make bonus -C $(LIBFTDIR)

clean				:
						rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
						make clean -C $(LIBFTDIR)

fclean				: clean
						rm -f $(NAME_CLIENT) $(NAME_SERVER) $(LIBFTDIR)$(LIBFT_NAME)

re					: fclean all

.PHONY				: all clean fclean re libft
