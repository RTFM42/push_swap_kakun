/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_3args_advance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:29:50 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/26 12:30:47 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_over4(t_info *status)
{
	int	size;
	int	div;
	int	max;
	int	min;
	int	i;

	i = 1;
	min = 0;
	size = status->list_size - 3;
	div = 5;
	if (200 < size)
		div = 9;
	while (i <= div && size != min)
	{
		max = size / div * i + size % div;
		rotate_and_push_b(status, status->a_node, min, max);
		min = max;
		i++;
	}
	sort_3args(status);
}

void	rotate_and_push_b(t_info *status, t_node *a_node, int min, int max)
{
	int	nbr;
	int	nnbr;
	int	count_pb;

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
				rr(status->a_node, status->b_node);
			else if (nbr < (max - min) / 2 + min)
				rb(status->b_node);
		}
		else
			ra(a_node);
	}
}
