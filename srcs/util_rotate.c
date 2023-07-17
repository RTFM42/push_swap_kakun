/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:55:01 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/17 15:31:54 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node *node)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = node->next;
	tmp2 = tmp1->next;
	tmp2->prev = node;
	node->next = tmp2;
	tmp1->next = node;
	tmp1->prev = node->prev;
	node->prev = tmp1;
	tmp2 = tmp1->prev;
	tmp2->next = tmp1;
}

int	ra(t_node *node)
{
	if (node == node->next)
		return (0);
	rotate(node);
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rb(t_node *node)
{
	if (node == node->next)
		return (0);
	rotate(node);
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rr(t_node *a_node, t_node *b_node)
{
	if (a_node == a_node->next && a_node == a_node->next)
		return (0);
	rotate(a_node);
	rotate(b_node);
	ft_putstr_fd("rr\n", 1);
	return (1);
}
