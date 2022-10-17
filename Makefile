NAME		= talk

SRC_CLIENT	= client.c 
SRC_SERVER	= server.c
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_CLIENT	= client
NAME_SERVER = server



all			: $(NAME)

$(NAME)		: server client

#cp libft/libft.a ./

# cp libft/libft.a $(NAME)
client		: $(OBJ_CLIENT) libft
			ar rcs client $^
# make bonus -C libft
# cp libft/libft.a $(NAME_CLIENT)
# $(CC) -o $^
#$@ ターゲットファイル名　

server		: $(OBJ_SERVER) libft
			ar rcs server $^
# cp libft/libft.a $(NAME_SERVER)
# ar rcs server libft.a
# $(CC) -o $^

libft	:
			make -C libft

clean		:
			rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
			make clean -C libft

fclean		: clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER) libft/libft.a

re			: fclean all

.PHONY		: all clean fclean re libft
