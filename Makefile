NAME		= minitalk.a
SRC			= client.c server.c
OBJS		= $(SRC:.c=.o)
cc			= gcc
INCLUDE		=
CFLAGS		= -Wall -Wextra -Werror

all			: $(NAME)

$(NAME)		: $(OBJS)
			make -C $(LIBFTDIR)
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $^

clean		:
			rm $(OBJS)

fclean		: clean
			rm $(NAME)

re			: fclean all

.PHONY		: all clean fclean re bonus
