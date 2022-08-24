/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:44 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/09 12:59:42 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	create_stack(t_list **stack_a, char **argv, int argc);
void	print_list(t_list *stack_a, t_list *stack_b);
int		sort_verification(t_list **list, int size);
int		error_handler(int argc, char **argv);
void	swap_rules(t_list **stack_a, t_list **stack_b, char *rule);
void	push_rules(t_list **stack_a, t_list **stack_b, char *rule);
void	del_first_elem(t_list **lst);
void	rotate_rules(t_list **stack_a, t_list **stack_b, char *rule);
void	reverse_rules(t_list **stack_a, t_list **stack_b, char *rule);
void	sort_big_num(t_list **stack_a, t_list **stack_b, int size);
char	**convert_to_binary(int *args, int size);
int		count_size(int n);
int		get_args_size(char **argv);
int		*cpy_array(int *array, int size);
int		get_max_index(int *args, int size);
int		binary_to_int(char *bin);
void	sort_small_num(t_list **stack_a, t_list **stack_b);
void	sort_helper(t_list **stack_a, t_list **stack_b, int n);
void	sort_three(t_list **stack_a, t_list **stack_b);
#endif