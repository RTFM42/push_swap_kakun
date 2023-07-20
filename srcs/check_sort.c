/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/20 20:18:56 by tokazaki         ###   ########.fr       */
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

void	sort_4to6args(t_info *status)
{
//printf("4 to 6  sort------\n");
	t_node	*tmp;
	int		i;
	int		j;

	tmp = status->a_node;
	tmp = tmp->next;
	j = 0;	
	i = 0;
	while (i < status->list_size - 3)
	{
		if (tmp->compression == status->list_size - i - 1)
		{
			pa(status);
			i++;
		}
		tmp = tmp->next;
	}
	sort_3args(status);
//debug(status);
	while (i--)
	{
		pb(status);
		ra(status->a_node);
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
//	debug_comp(status);
}

void	presort_and_make_compress(t_info *status)
{
	t_node	*tmpi;
	t_node	*tmpj;
	int		i;
	int		j;
	t_node	**arry;

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
				status->status = 110;
			if (tmpj->value < tmpi->value)
			{
				arry[i] = tmpj;
				arry[j] = tmpi;
			}
			j++;
		}
		i++;
	}
	add_compression(status);
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
//	else if (4 <= status->list_size && status->list_size <= 6)
//		sort_4to6args(status, status->list_size);	
	else
		sort_4to6args(status);	
//	printf("kyoumoiiihi\n\n");

}
