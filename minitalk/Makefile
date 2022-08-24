SERVER			=	server

CLIENT			=	client

LD_FLAGS		=	-L libft

LIBFT_FLAGS		=	-lft

CLIENT_SRCS		=	srcs/client.c

SERVER_SRCS		=	srcs/server.c

CLIENT_OBJS			=	${CLIENT_SRCS:.c=.o}

SERVER_OBJS			=	${SERVER_SRCS:.c=.o}

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

all				:	${CLIENT} ${SERVER}

${CLIENT}		:	${CLIENT_OBJS}
					make -C libft
					${CC} ${CFLAGS} ${LD_FLAGS} ${CLIENT_OBJS} -o ${CLIENT} ${LIBFT_FLAGS}

${SERVER}		:	${SERVER_OBJS}
					${CC} ${CFLAGS} ${LD_FLAGS} ${SERVER_OBJS} -o ${SERVER} ${LIBFT_FLAGS}

clean			:
					make clean -C libft
					rm -rf ${SERVER_OBJS} ${CLIENT_OBJS}

fclean			:	clean
					rm -rf ${SERVER} ${CLIENT}
re				:	fclean all

.PHONY			:	all clean fclean re