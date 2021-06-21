SRCS	= printf.c\
	  printf_utils_part1.c\
	  printf_utils_part2.c\

OBJS	= $(SRCS:.c=.o)

NAME	= ft_printf

CC	= gcc

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -Iincludes

all:	$(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(CLFAGS) -o $(NAME) $^
			@echo "$(NAME) compiled"

clean:	
			@$(RM) $(OBJS)
			@echo ".o deleted"

fclean: clean
			@$(RM) $(NAME)
			@echo "$(NAME) deleted"

re:	fclean all

.PHONY:	all clean fclean re