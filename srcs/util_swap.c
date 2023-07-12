/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:44:01 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/12 13:54:43 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *node)
{
	t_node	tmp;

	tmp = node->next;
	node->next = tmp->next;
	node = tmp->next;
	node->prev = tmp->prev;
	tmp->prev = node;
	tmp->next = node->next;
	node->next = tmp;
	node = tmp->next;
	node->prev = tmp;
}

int	sa(t_node *node)
{
	if (node == node->next)
		return (0);
	swap(node);
	ft_putstr_fd("sa\n", 1);
	return(1);
}

int	sb(t_node *node)
{
	if (node == node->next)
		return (0);
	swap(node);
	ft_putstr_fd("sb\n", 1);
	return(1);
}

int	ss(t_node *a_node, t_node *b_node)
{
	if (node == node->next)
		return (0);
	swap(a_node);
	swap(b_node);
	ft_putstr_fd("ss\n", 1);
	return(1);
}
