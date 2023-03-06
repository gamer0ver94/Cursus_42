NAME = Bureaucrat

CC = c++

CFLAGS =  -std=c++98 -g

SRC = main.cpp srcs/Bureaucrat.cpp

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME) $(OBJS)
fclean : clean