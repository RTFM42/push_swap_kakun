/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/18 18:00:30 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort2(t_info *status)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = status->a_node;
	tmp2 = tmp1->prev;
	tmp1 = tmp1->next;
	if (tmp1->value < tmp2->value)
		return;
	sa(status->a_node);
}

void sort3(t_info *status)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = status->a_node;
	tmp2 = tmp1->prev;
	tmp3 = tmp1->prev;
	tmp1 = tmp1->next;
	if (tmp1->value < tmp2->value && )
		return;
	sa(status->a_node);
}

void check_sort(t_info *status)
{
	if (status->list_size == 1)
		return ;
	else if (status->list_size == 2)
		sort2(status);	
	else if (status->list_size == 3)
		sort2(status);	
	printf("kyoumoiiihi\n\n");
}
