NAME = Conversion_of_scalar_types

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp srcs/ScalarConverter.cpp

OBJS = $(SRC:.cpp=.o)

.cpp :
	${CC} ${CFLAGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME) $(OBJS)
fclean : clean