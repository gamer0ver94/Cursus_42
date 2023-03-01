NAME = Animals_with_Brain

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean