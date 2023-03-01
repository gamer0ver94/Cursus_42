NAME = Interfaces

CC = g++

CFLAGS =  -std=c++98 -g

SRC = main.cpp Sources/Character.cpp Sources/AMateria.cpp Sources/Ice.cpp Sources/Cure.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean