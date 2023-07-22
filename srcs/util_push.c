/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:16:05 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/21 15:15:16 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node *active_node, t_node *passive_node)
{
	t_node	*tmp;

	tmp = active_node->next;
	active_node->next = tmp->next;
	active_node = active_node->next;
	active_node->prev = tmp->prev;
	tmp->prev = passive_node;
	tmp->next = passive_node->next;
	passive_node->next = tmp;
	passive_node = tmp->next;
	passive_node->prev = tmp;
}

int	pb(t_info *status)
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = status->a_node;
	b_node = status->b_node;
	if (a_node == a_node->next)
		return (0);
	push(a_node, b_node);
	ft_putstr_fd("pb\n", 1);
	return (1);
}

int	pa(t_info *status)
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = status->a_node;
	b_node = status->b_node;
	if (b_node == b_node->next)
		return (0);
	push(b_node, a_node);
	ft_putstr_fd("pa\n", 1);
	return (1);
}
