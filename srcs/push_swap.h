/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:51:08 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/17 17:37:45 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

# define A_NODE_ERROR 1
# define B_NODE_ERROR 2
# define ARGS_ERROR 3

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	long			value;
	long			number;
}	t_node;

typedef struct s_info {
	t_node	*a_node;
	t_node	*b_node;
	int		list_size;
	int		status;
}	t_info;

//make node
void	process_args_and_make_structs(int argc, char *argv[], t_info *status);
void	make_dummy_node(t_info *status);
void	make_node(int value, t_info *status);
int		check_args(t_node *a_node);

//process args
int		check_num(char *str, t_info *status);
int		ps_atoi(const char *str, t_info *status, int *count);
int		ft_isspace(int c);

//check_sort
void	check_sotr(t_info *status);

//utils
int		pa(t_node *a_node, t_node *b_node);
int		pb(t_node *b_node, t_node *a_node);
int		ra(t_node *node);
int		rb(t_node *node);
int		rr(t_node *a_node, t_node *b_node);
int		sa(t_node *node);
int		sb(t_node *node);
int		ss(t_node *a_node, t_node *b_node);
int		rra(t_node *node);
int		rrb(t_node *node);
int		rrr(t_node *a_node, t_node *b_node);
#endif
