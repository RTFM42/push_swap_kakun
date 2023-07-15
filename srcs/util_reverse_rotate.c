/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:16:57 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/13 13:23:00 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node *node)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = node->prev;
	tmp2 = tmp1->prev;
	tmp2->next = node;
	node->prev = tmp2;
	tmp1->prev = node;
	tmp1->next = node->next;
	node->next = tmp1;
	tmp2 = tmp1->next;
	tmp2->prev = tmp1;
}

int	rra(t_node *node)
{
	if (node == node->next)
		return (0);
	reverse_rotate(node);
	ft_putstr_fd("rra\n", 1);
	return(1);
}

int	rrb(t_node *node)
{
	if (node == node->next)
		return (0);
	reverse_rotate(node);
	ft_putstr_fd("rra\n", 1);
	return(1);
}

int	rrr(t_node *a_node, t_node *b_node)
{
	if (a_node == a_node->next && a_node == a_node->next)
		return (0);
	reverse_rotate(a_node);
	reverse_rotate(b_node);
	ft_putstr_fd("rrr\n", 1);
	return(1);
}
