/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 21:20:48 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_and_push_b(t_info *status ,t_node *a_node, int min, int max)
{
	int	nbr;
	int	nnbr;
	int count_pb;

	count_pb = 0;
	while (count_pb < max - min)
	{
		nbr = a_node->next->compression;
		nnbr = a_node->next->next->compression;
		if (nbr <= max)
		{
			pb(status);
			count_pb++;
			if (nbr < (max - min) / 2 + min && max < nnbr)
					rr(status->a_node,status->b_node);
			else if (nbr < (max - min) / 2 + min)
				rb(status->b_node);
		}
		else
			ra(a_node);
	}
}

void sort_over4(t_info *status)
{
	int size;
	int div;
	int max;
	int min;
	int i;

	i = 1;
	min = 0;
	size = status->list_size - 3;
	div = 5;
	if (200 < size)
		div = 9;
	while (i <= div && size != min)
	{
		max = size / div * i + size % div;
		rotate_and_push_b(status ,status->a_node, min, max);
		min = max;
		i++;
	}
	sort_3args(status);
}

int	serch_node(t_node *a_node,t_node *node)
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

void	push_2args(t_info *status, int size, int point, int npoint)
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
	dis = np_dis - p_dis;
	if ((size) / 2 < abs(dis))
	{
		dis = size - abs(dis);
		if (p_dis < 0 && 0 < np_dis)
			dis *= -1;
		if (0 < dis)
			;
	}
	if (0 < dis)
		dis--;
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

void	rev_args2(t_info *status)
{
	int	size;
	int	point;
	int	npoint;

	size = status->list_size - 3;
	while (size != 0 && size != 1)
	{
		point = serch_node(status->b_node, status->arry[size - 1]);
		npoint = serch_node(status->b_node, status->arry[size - 2]);
		push_2args(status, size, point, npoint);	
		sort_2args(status->a_node);	
		size = size - 2;
	}
	if (size == 1)
		pa(status);
}

void	rev_args(t_info *status)
{
	int		size;
	int		point;

	size = status->list_size - 3;
	while (size != 0)
	{
		point = serch_node(status->b_node, status->arry[size - 1]);
		if (point == 0);
		else if (point < size / 2)
		{
			while (point--)
				rb(status->b_node);
		}
		else
		{
			point = size - point;
			while (point--)
				rrb(status->b_node);
		}
		pa(status);
		size--;
	}
}

void	check_sort(t_info *status)
{
	check_node(status);
	if (status->status != 0)
		return ;
	make_arry(status);
	presort(status);
	if (status->status != 0)
		return ;
	if (status->list_size == 1)
		return ;
	else if (status->list_size == 2)
		sort_2args(status->a_node);	
	else if (status->list_size == 3)
		sort_3args(status);
	else
	{
		sort_over4(status);
		rev_args2(status);	
	}
}
