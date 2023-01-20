NAME = Unnecessary_violence

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = srcs/main.cpp srcs/HumanA.cpp srcs/HumanB.cpp srcs/Weapon.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean