CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_aide00.c ft_aide01.c

NAME = libftprintf.a

AR = ar -rs

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rs $(NAME) $(OBJS)
clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all
