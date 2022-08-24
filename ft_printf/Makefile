CC = gcc

RM = rm -f
LIBFT = ../libft

SRCS =	srcs/ft_printf.c\
		srcs/ft_hexaconvert.c\
		srcs/ft_putstr.c\
		srcs/ft_writeitoa.c\
		srcs/ft_pointertohexa.c\
		srcs/ft_unsigneditoa.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a


all:	${NAME}
${NAME}:	${OBJS}
	make -C ${LIBFT}
	cp ../libft/libft.a .
	@mv libft.a ${NAME}
	@ar rcs ${NAME} ${OBJS}
	@echo "done"

clean:
	make clean -C ${LIBFT}
	${RM} ${OBJS}
	
fclean:	clean
	${RM} ${LIBFT}/libft.a
	${RM} ${NAME}

re:	fclean all