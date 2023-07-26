/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_3args_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:32:17 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/26 14:33:17 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_args(t_info *status)
{
	int	size;
	int	point;
	int	npoint;

	size = status->list_size - 3;
	while (size != 0 && size != 1)
	{
		point = serch_node(status->b_node, status->arry[size - 1]);
		npoint = serch_node(status->b_node, status->arry[size - 2]);
		set_push_2args(status, size, point, npoint);
		sort_2args(status->a_node);
		size = size - 2;
	}
	if (size == 1)
		pa(status);
}

int	serch_node(t_node *a_node, t_node *node)
{
	int		point;
	t_node	*tmp;

	point = 0;
	tmp = a_node->next;
	while (node != tmp)
	{
		tmp = tmp->next;
		point++;
	}
	return (point);
}

void	set_push_2args(t_info *status, int size, int point, int npoint)
{
	int	p_dis;
	int	np_dis;
	int	dis;

	p_dis = distance(point, size);
	np_dis = distance(npoint, size);
	dis = p_dis;
	if (abs(np_dis) < abs(p_dis))
	{
		dis = np_dis;
		np_dis = p_dis;
		p_dis = dis;
	}
	properly_push(status, dis);
	dis = np_dis - p_dis;
	if ((size) / 2 < abs(dis))
	{
		dis = size - abs(dis);
		if (p_dis < 0 && 0 < np_dis)
			dis *= -1;
	}
	if (0 < dis)
		dis--;
	properly_push(status, dis);
}

void	properly_push(t_info *status, int dis)
{
	while (0 < dis)
	{
		rb(status->b_node);
		dis--;
	}
	while (dis < 0)
	{
		rrb(status->b_node);
		dis++;
	}
	pa(status);
}
