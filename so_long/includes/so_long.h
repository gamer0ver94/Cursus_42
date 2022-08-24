/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:47:33 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/24 09:47:21 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "structs.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# define WATER "assets/water.xpm"
# define SAND "assets/sand.xpm"
# define PLAYERDOWN "assets/rabit_down.xpm"
# define PLAYERLEFT "assets/rabit_left.xpm"
# define PLAYERRIGHT "assets/rabit_right.xpm"
# define PLAYERUP "assets/rabit_up.xpm"
# define COIN "assets/ball.xpm"
# define ENEMYLEFT "assets/fox_left.xpm"
# define ENEMYRIGHT "assets/fox_right.xpm"
# define ENEMYUP "assets/fox_up.xpm"
# define ENEMYDOWN "assets/fox_down.xpm"
# define ENEMYLEFTMAD "assets/fox_left_mad.xpm"
# define ENEMYRIGHTMAD "assets/fox_right_mad.xpm"
# define ENEMYUPMAD "assets/fox_up_mad.xpm"
# define ENEMYDOWNMAD "assets/fox_down_mad.xpm"
# define EXIT1 "assets/silver_door.xpm"
# define EXIT2 "assets/gold_door.xpm"
# define P2DOWN "assets/mouse_down.xpm"
# define P2LEFT "assets/mouse_left.xpm"
# define P2UP "assets/mouse_up.xpm"
# define P2RIGHT "assets/mouse_right.xpm"
# define GAME_MENU "assets/game_menu.xpm"
# define EFFECT_1 "assets/effect_1.xpm"
# define EFFECT_2 "assets/effect_2.xpm"
# define BG "assets/bg_menu.xpm"
# define BGSP "assets/bg_menu_sp.xpm"
# define BGMP "assets/bg_menu_mp.xpm"
# define BGQUIT "assets/bg_menu_quit.xpm"
# define SCORE "assets/score.xpm"
# define WIN_WIDTH 1900
# define WIN_HEIGHT 1080
# define IMG_SIZE 49
# define ON  1
# define OFF  0
# define WAIT  2
# define SELECTED 3
# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53
# define R 15
# define L 37
# define ENEMY_SPEED 40
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ENTER 36

void	s_initialization(t_data *data);
void	read_map(t_data *data, char *argv);
void	new_window(t_data *data);
void	debugger(t_data *data);
void	keys_event(t_data *data);
void	player_move(t_data *data, int key);
void	player_position(t_data *data);
void	enemy_position(t_data *data);
int		graphics_render(t_data *data);
int		enemy_moves(t_data *data);
int		count_coins(t_data *data);
void	exit_position(t_data *data);
void	finish_game(t_data *data, int key);
int		check_enemy(t_data *data);
void	player2_move(t_data *data, int key);
void	player2_position(t_data *data);
void	menu_update(t_data *data, int key);
void	map_update(t_data *data, int row, int col);
int		check_player(t_data *data);
int		check_map(t_data *data);
void	check_errors(t_data *data, int error);
int		count_enemys(t_data *data);
void	check_exit(t_data *data);
void	gameover(t_data *data);
int		check_path(t_data *data, int col, int row);
int		check_path_to_coins(t_data *data, int col, int row);

#endif
