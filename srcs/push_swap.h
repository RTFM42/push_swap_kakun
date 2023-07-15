/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:51:08 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/13 20:05:21 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	long			value;
	long			number;
}	t_node;

typedef struct s_info {
	t_node	*a_node;
	t_node	*b_node;
	int				count;
	int				status;
}	t_info;

void	process_args_and_make_structs(int argc,char *argv[], t_info *status);

int		pa(t_node *a_node, t_node *b_node);
int		pb(t_node *b_node, t_node *a_node);
int		ra(t_node *node);
int		rb(t_node *node);
int		rr(t_node *a_node, t_node *b_node);
int		sa(t_node *node);
int		sb(t_node *node);
int		ss(t_node *a_node, t_node *b_node);
int	rra(t_node *node);
int	rrb(t_node *node);
int	rrr(t_node *a_node, t_node *b_node);
#endif

