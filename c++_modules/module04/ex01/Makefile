NAME = Animals_with_Brain

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean