NAME = HI_THIS_IS_BRAIN

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean