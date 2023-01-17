NAME = PhoneBook

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = srcs/main.cpp srcs/contact.cpp srcs/phoneBook.cpp

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re :  fclean all

clean :
	rm -rf $(NAME)
fclean : clean