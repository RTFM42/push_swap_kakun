/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/19 19:46:24 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(t_info *status);
void sort_2args(t_node *node)
{
printf("sort2\n");
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
printf("sort3\n");
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = status->a_node;
	tmp3 = tmp1->prev;
	tmp2 = tmp3->prev;
	tmp1 = tmp1->next;
printf("[1]%ld\n",tmp1->value);
printf("[2]%ld\n",tmp2->value);
printf("[3]%ld\n",tmp3->value);
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
printf("over sort------\n");
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = node;
	tmp3 = tmp1->prev;
	tmp2 = tmp3->prev;
	tmp1 = tmp1->next;
printf("[1]%ld\n",tmp1->value);
printf("[2]%ld\n",tmp2->value);
printf("[3]%ld\n",tmp3->value);
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

void	sort_4to6args(t_info *status, int index)
{
	t_node	*tmp;
	int		i;
	int		j;

	tmp = status->a_node;
	tmp = tmp->next;
	j = 0;	
	i = 0;
	if (index == 0)
		return ;
	while (index == status->list_size && i < index - 3)
	{
		if (tmp->compression < 3)
		{
			pa(status);
			i++;
		}
		tmp = tmp->next;
	}
	if (i == 2)
		sort_2args(status->a_node);	
	else if (i == 3)
	{
		sort(status->b_node);
	}
	sort(status->a_node);
debug(status);
	rrb(status->b_node);
	while (i--)
	{
		pb(status);
		rrb(status->b_node);
	}
}

//void	sort_over_3args(t_info *status,int index)
//{
//printf("over sort 3 args\n");
//	t_node *a_node;
//	t_node *b_node;
//	int		i;
//	int		j;
//	int		k;
//
//	j = 0;	
//	i = 0;
//	if (index == 0)
//		return ;
//	while (index == status->list_size && i < index - 3)
//	{
//		pa(status);
//		i++;
//	}
//printf("[i:%d]\n",i);
//debug(status);
//	while (i != 0)
//	{
//		j = 0;
//		while(j < index)
//		{
//printf("-----------------------------------------------------\n");
//		sort(status);
//		a_node = status->a_node;
//		b_node = status->b_node;
//		a_node = a_node->next;
//		b_node = b_node->next;
//		k = 0;
//		while (k < i)
//		{
//			if (b_node->value > a_node->value)
//			{
//				pa(status);
//				rrb(status->b_node);
//				pb(status);
//			}
//			rrb(status->b_node);
//			k++;
//		}
//printf("[k:%d]\n",k);
//		j++;
//debug(status);
//		}
//		pb(status);
//		i--;
//	}
//	sort(status);
//	printf("END over sort 3 args\n");
//}

void	make_compress(t_info *status)
{
	t_node	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < status)
	{
		j = 0;
		while (j < )
		{
			if ()
			{
			}
			j++;
		}
		i++;
	}
}

void	check_sort(t_info *status)
{
	make_compress(status);
	if (status->list_size == 1)
		return ;
	else if (status->list_size == 2)
		sort_2args(status->a_node);	
	else if (status->list_size == 3)
		sort_3args(status);
	else if (4 <= status->list_size && status->list_size <= 6)
		sort_4to6args(status, status->list_size);	
//	else
//		sort_over_3args(status, status->list_size);	
	printf("kyoumoiiihi\n\n");
}
