NAME = Bureaucrat

CC = c++

CFLAGS =  -Wall -Werror -Wextra -std=c++98 -g

SRC = main.cpp srcs/Bureaucrat.cpp srcs/Form.cpp

OBJS = $(SRC:.cpp=.o)

.cpp.o:
	${CC} ${CFLAGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME) $(OBJS)
fclean : clean