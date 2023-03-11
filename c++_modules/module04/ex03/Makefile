NAME = Interfaces

CC = g++

CFLAGS =  -std=c++98 -Wall -Wextra -Werror -lstdc++

SRC = main.cpp Sources/Character.cpp Sources/AMateria.cpp Sources/Ice.cpp Sources/Cure.cpp Sources/MateriaSource.cpp

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean