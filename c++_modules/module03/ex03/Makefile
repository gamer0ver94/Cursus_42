NAME = FragTrap

CC = g++

CFLAGS = -Wall -Wextra -Werror -Wshadow and -Wno-shadow -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean