/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_compression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:02 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 21:22:05 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	presort(t_info *status)
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
