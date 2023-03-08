NAME   = minishell
CC     = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
LIBS   = -lreadline
SRCS   = src/readline.c
OBJS   = $(SRCS:%.c=%.o)

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./test.sh
.PHONY: all clean fclean re test