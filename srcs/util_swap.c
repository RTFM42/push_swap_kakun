/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:44:01 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/13 17:59:45 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *node)
{
	t_node	*tmp;
	int		tmp_value;

	tmp = node->next;
	node = tmp->next;
	tmp_value = tmp->value;
	tmp->value = node->value;
	node->value = tmp_value;
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
	if (a_node == a_node->next && b_node == b_node->next)
		return (0);
	swap(a_node);
	swap(b_node);
	ft_putstr_fd("ss\n", 1);
	return(1);
}
