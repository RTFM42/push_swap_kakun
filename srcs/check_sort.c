/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/22 17:43:18 by tokazaki         ###   ########.fr       */
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
		sa(status->a_node);
	else if ((tmp3->value > tmp1->value && tmp3->value < tmp2->value) \
			|| (tmp1->value < tmp2->value && tmp1->value > tmp3->value))
		rra(status->a_node);
	sort_3args(status);	
}

void sort(t_node *node)
{
//printf("over sort------\n");
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = node;
	tmp3 = tmp1->prev;
	tmp2 = tmp3->prev;
	tmp1 = tmp1->next;
	if (tmp1->value < tmp2->value && tmp2->value < tmp3->value)
	{
		return ;
	}
	else if ((tmp2->value < tmp1->value && tmp1->value < tmp3->value) \
		|| (tmp2->value < tmp3->value && tmp3->value < tmp1->value) \
		|| (tmp3->value < tmp2->value && tmp2->value < tmp1->value)) 
		sa(node);
	else if (tmp1->value < tmp3->value && tmp3->value < tmp2->value)
	{
		ra(node);
		sa(node);
		rra(node);
	}
	else if (tmp3->value < tmp1->value && tmp1->value < tmp2->value)
	{
		ra(node);
		sa(node);
		rra(node);
	}
	sort(node);	
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
//printf("point:%d, value:%ld\n",point,node->value);
	return (point);
}

void	over_4args(t_info *status)
{
//printf("4 to 6  sort------\n");
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*a_node;
	int		i;
	int		point;

	i = 0;
	a_node = status->a_node;
	while (i < status->list_size - 3)
	{
		tmp = a_node->next;
		tmp2 = a_node->next;
		point = serch_node(status->a_node, status->arry[i]);
		if (point == 0);
		else if (point < (status->list_size - i) / 2)
		{
			while (point--)
			{
				ra(status->a_node);
			}
		}
		else
		{
			point = status->list_size - i - point;
			while (point--)
			{
				rra(status->a_node);
			}
		}
			pb(status);
			i++;
//debug(status);
	}
	sort_3args(status);
	while (i--)
	{
		pa(status);
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
//debug_comp(status);
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
		over_4args(status);	
//	printf("kyoumoiiihi\n\n");

}
