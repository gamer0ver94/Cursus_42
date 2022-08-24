NAME		:=	MiniShelll

# SRCS_DIR	:=	srcs

SRCS		:=	main.c srcs/get_prompt_name.c

OBJS		:=	$(srcs:.c=*.o)

CC			:=	gcc

RL_FLAG		:=	-lreadline

ALL	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(SRCS) $(RL_FLAG)

clean	:
		rm -rf $(NAME)
