/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:51:08 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/26 16:56:48 by tokazaki         ###   ########.fr       */
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
# define BOTH_NODE_ERROR 4
# define NODE_ERROR 5
# define ARRY_ERROR 6
# define SAME_ARGS 6
# define NO_ARGS 7

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	long			value;
	long			compression;
}	t_node;

typedef struct s_info {
	t_node	*a_node;
	t_node	*b_node;
	t_node	**arry;
	int		list_size;
	int		status;
}	t_info;

//push swap
int		main(int argc, char *argv[]);
void	all_free(t_info	*status);
void	node_free(t_node *node);

//make node
void	process_args_and_make_structs(int argc, char *argv[], t_info *status);
void	make_dummy_node(t_info *status);
void	make_node(int value, t_info *status);

//process args
int		check_num(char *str, t_info *status);
int		ps_atoi(const char *str, t_info *status, int *count);
int		ft_isspace(int c);

//make compression
void	check_make_compression(t_info *status);
void	make_arry(t_info *status);
void	presort(t_info *status);
void	swap_check_args(t_info *status, int i, int j);
void	make_compression(t_info *status);

//check_sort
void	check_sort(t_info *status, int argc, char *argv[]);
void	check_args(t_info *status, int argc, char *argv[]);

//less or 3args sort
void	sort_2args(t_node *node);
void	sort_3args(t_info *status);

//more 3args advance
void	sort_over4(t_info *status);
void	rotate_and_push_b(t_info *status, t_node *a_node, int min, int max);

//more 3args reverse
void	rev_args(t_info *status);
int		serch_node(t_node *a_node, t_node *node);
void	set_push_2args(t_info *status, int size, int point, int npoint);
void	properly_push(t_info *status, int dis);

//utils
int		distance(int nbr, int size);
int		abs(int nbr);

//operations
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
