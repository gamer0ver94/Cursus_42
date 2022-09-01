# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 23:47:14 by dpaulino          #+#    #+#              #
#    Updated: 2022/09/01 16:03:59 by dpaulino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRCS			=	main.c srcs/get_next_line.c srcs/s_initialization.c srcs/get_next_line_utils.c \
					srcs/debugger.c srcs/read_map.c srcs/new_window.c srcs/keys_event.c srcs/generate_window.c \
					srcs/player_move.c srcs/player_position.c srcs/graphics_render.c srcs/enemy_move.c \
					srcs/enemy_position.c srcs/count_coins.c srcs/exit_position.c srcs/finish_game.c \
					srcs/check_enemy.c srcs/player2_move.c srcs/player2_position.c srcs/menu_update.c \
					srcs/map_update.c srcs/check_player.c srcs/check_map.c srcs/check_errors.c srcs/map_update2.c \
					srcs/count_enemys.c srcs/check_exit.c srcs/gameover.c srcs/check_path.c srcs/check_path_to_coins.c
					
OBJS			=	${SRCS:.c=.o}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	 -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS		=	-lft

CC				=	gcc -g

CFLAGS			=	-Wall -Werror -Wextra -ggdb3

$(NAME)			:	${OBJS}
					make -C libft
					cp ../libft/libft.a .
					@mv libft.a ${NAME}
					# make -C minilibx-linux
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${LIBFT_FLAGS} ${MLX_FLAGS}

all				:	${NAME}

clean			:
					make clean -C libft
					# make clean -C minilibx-linux
					make clean -C mlx
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re