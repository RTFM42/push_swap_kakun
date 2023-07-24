/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/24 19:56:28 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(t_info *status);
void	debug_comp(t_info *status);

void sort_2args(t_node *node)
{
	long	value1;
	long	value2;

	value1 = node->next->value;
	value2 = node->prev->value;
	if (value1 < value2)
		return;
	sa(node);
}

void sort_3args(t_info *status)
{
	long	value1;
	long	value2;
	long	value3;

	value1 = status->a_node->next->value;
	value2 = status->a_node->next->next->value;
	value3 = status->a_node->next->next->next->value;
	if (value1 < value2 && value2 < value3)
		return ;
	else if (value2 < value1 && value3 < value1)
		ra(status->a_node);
	else if (value2 < value1 && value1 < value3)
		sa(status->a_node);
	else if ((value1 < value3 && value3 < value2) \
			|| (value3 < value1 && value1 < value2))
		rra(status->a_node);
	sort_3args(status);	
}

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
			else if (nbr < (max - min) / 2)
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
	div = 4;
	if (200 < size)
		div = 8;
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

//void	push_2args(t_info *status, int size, int point, int npoint)
//{
//	int	tmp;
//	int	ntmp;
//	int	pre;
//	int	post;
//	int	mv;
//
//	tmp = point;
//	ntmp = npoint;
//	if (!(point < size / 2 || point == 0))
//	{
//		pre = point
//		point = (size - point) - 1;
//		tmp = point * -1;
//	}
//	if (!(npoint < (size - 1) / 2 || npoint == 0))
//	{
//		npoint = (size - 1 - npoint) - 1;
//		ntmp = point * -1;
//	}
//	mv = post - pre; 
//	else if (size / 2)
//}
//
//void	rev_args(t_info *status)
//{
//	int	size;
//	int	point;
//	int	npoint;
//
//	size = status->list_size - 3;
//	while (size != 0 && size != 1)
//	{
//		point = serch_node(status->b_node, status->arry[size - 1]);
//		npoint = serch_node(status->b_node, status->arry[size - 2]);
//		push_2args(status, size, point, npoint);	
//
//
//		if (point == 0);
//		else if (point < size / 2)
//		{
//			while (point--)
//				rb(status->b_node);
//		}
//		else
//		{
//			point = size - point;
//			while (point--)
//				rrb(status->b_node);
//		}
//
//		
//		sort_2args(status->a_node);	
//		size = size - 2;
//	}
//	if (size == 1)
//		pa(status);
//}

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


void	make_compression(t_info *status)
{
	long	i;
	t_node	**arry;

	arry = status->arry;
	i = 0;
	while (i < status->list_size)
	{
		arry[i]->compression = i + 1;
		i++;
	}
}

void	presort_and_make_compress(t_info *status)
{
	t_node	*tmpi;
	t_node	*tmpj;
	int		i;
	int		j;
	t_node	**arry;

	status->status = -1;
	arry = status->arry;
	i = 0;
	while (i < status->list_size)
	{
		j = i + 1;
		while (j < status->list_size)
		{
			tmpi = arry[i];
			tmpj = arry[j];
			if (tmpj->value == tmpi->value)
			{
				status->status = -2;
				return ;
			}
			if (tmpj->value < tmpi->value)
			{
				arry[i] = tmpj;
				arry[j] = tmpi;
				status->status = 0;
			}
			j++;
		}
		i++;
	}
	make_compression(status);
}

void	check_sort(t_info *status)
{
	presort_and_make_compress(status);
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
		rev_args(status);	
	}
}
