NAME = Iter

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I./generic

SRC = main.cpp

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
