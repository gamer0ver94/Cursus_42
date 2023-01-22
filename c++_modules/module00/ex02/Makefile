NAME = The_Job_Of_Your_Dreams

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp Account.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean