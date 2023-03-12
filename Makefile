NAME	=	minishell
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDES)
LIBS	=	-lreadline
SRC_DIR	=	src/
SRC		=	minishell.c ft_strjoin.c ft_strndup.c ft_get_path.c \
			ft_strdup.c ft_split.c ft_strlen.c ft_puterror.c \
			tokenize.c tokenizeutil.c
SRCS	=	$(addprefix $(SRC_DIR), $(SRC))
OBJS	=	$(SRCS:%.c=%.o)

#################
# General rules #
#################

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

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