/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:51:08 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/22 14:02:25 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

# define ONE_ARG -2
# define OK_SORT -1
# define A_NODE_ERROR 1
# define B_NODE_ERROR 2
# define ARGS_ERROR 3

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	long			value;
	long			compression;
}	t_node;

typedef struct s_info {
	t_node	*a_node;
	t_node	*b_node;
	t_node	**arry;;
	int		list_size;
	int		status;
}	t_info;

//make node
void	process_args_and_make_structs(int argc, char *argv[], t_info *status);
void	make_dummy_node(t_info *status);
void	make_node(int value, t_info *status);
void	check_node(t_info *status);

//process args
int		check_num(char *str, t_info *status);
int		ps_atoi(const char *str, t_info *status, int *count);
int		ft_isspace(int c);

//check_sort
void	check_sort(t_info *status);

//utils
int		pa(t_info *status);
int		pb(t_info *status);
int		ra(t_node *node);
int		rb(t_node *node);
int		rr(t_node *a_node, t_node *b_node);
int		sa(t_node *node);
int		sb(t_node *node);
int		ss(t_node *a_node, t_node *b_node);
int		rra(t_node *node);
int		rrb(t_node *node);
int		rrr(t_node *a_node, t_node *b_node);

//debug
void	debug(t_info *status);
void	debug_arry(t_info *status);

#endif
