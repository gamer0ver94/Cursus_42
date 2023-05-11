NAME = IndentiFy_Real_Number

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp srcs/A.cpp srcs/B.cpp srcs/C.cpp

OBJS = $(SRC:.cpp=.o)

.cpp.o :
	${CC} ${CFLAGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME) $(OBJS)
fclean : clean