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
//printf("sort2\n");
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = node;
	tmp2 = tmp1->prev;
	tmp1 = tmp1->next;
	if (tmp1->value < tmp2->value)
		return;
	sa(node);
}

void sort_3args(t_info *status)
{
//printf("sort3--------------------------\n");
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = status->a_node;
	tmp3 = tmp1->prev;
	tmp2 = tmp3->prev;
	tmp1 = tmp1->next;
	if (tmp1->value < tmp2->value && tmp2->value < tmp3->value)
		return ;
	else if (tmp1->value > tmp2->value && tmp1->value > tmp3->value)
		ra(status->a_node);
	else if (tmp1->value > tmp2->value && tmp1->value < tmp3->value)
	{
		sa(status->a_node);
	}
	else if ((tmp3->value > tmp1->value && tmp3->value < tmp2->value) \
			|| (tmp1->value < tmp2->value && tmp1->value > tmp3->value))
		rra(status->a_node);
	sort_3args(status);	
}

void rotate_and_push_b(t_info *status ,t_node *a_node, int min, int max)
{
	t_node *tmp;
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = status->list_size;
	while (i < size)
	{
		tmp = a_node->next;
		if (tmp->compression <= max)
		{
			pb(status);
			j++;
//			if (tmp->compression < (max - min) / 2 + min)
//				rb(status->b_node->next);
			if (j == max - min)
				break ;
		}
		else
			ra(a_node);
		i++;
	}
}

void sort_over4(t_info *status)
{
	int size;
	int i;
	int j;
	int max;
	int min;

	i = 0;
	min = 0;
	size = status->list_size - 3;
	j = 9;
	if (200 < size)
		j = 13;
	while (i <= j && size != min)
	{
		max = size / j * i + size % j;
		rotate_and_push_b(status ,status->a_node, min, max);
		min = max;
		i++;
	}
//debug(status);
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

//大きいnodeから順番に送る
void	rev_4args(t_info *status)
{
	int		i;
	int		point;

	i = status->list_size - 3;
	while (i != 0)
	{
		point = serch_node(status->b_node, status->arry[i - 1]);
//printf("point:%d, %d\n",point, i);
//debug(status);
		if (point == 0);
		else if (point < i / 2)
		{
			while (point--)
			{
				rb(status->b_node);
			}
		}
		else
		{
			point = i - point;
			while (point--)
			{
				rrb(status->b_node);
			}
		}
//		while (point--)
//			rb(status->b_node);
		pa(status);
		i--;
	}
}


void	add_compression(t_info *status)
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
	add_compression(status);
//debug_arry(status);
}

void	check_sort(t_info *status)
{
//debug(status);
	presort_and_make_compress(status);
	if (status->status != 0)
		return ;
	if (status->list_size == 1)
		return ;
	else if (status->list_size == 2)
		sort_2args(status->a_node);	
	else if (status->list_size == 3)
		sort_3args(status);
//	else if (4 <= status->list_size && status->list_size <= 6)
//		sort_4to6args(status, status->list_size);	
	else
	{
		//over_4args(status);	
		sort_over4(status);
//debug(status);
		rev_4args(status);	
	}
//	printf("kyoumoiiihi\n\n");
//debug(status);
}
