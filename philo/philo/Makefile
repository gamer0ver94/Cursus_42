NAME			=	philo

SRCS			=	srcs/create_enviroment.c \
					srcs/free_data.c \
					srcs/info_init.c \
					srcs/main.c \
					srcs/philos_init.c \
					srcs/print_message.c \
					srcs/routines.c \
					srcs/simulation.c \
					srcs/tasks.c \
					srcs/threads_utils.c \
					srcs/time_stamp.c \
					srcs/utils.c \

OBJS			=	${SRCS:.c=.o}

CC				=	gcc -g

CFLAGS			=	-Wall -Werror -Wextra

$(NAME)			:	${OBJS}
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME}

all				:	${NAME}

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re