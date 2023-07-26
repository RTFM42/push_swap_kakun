/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_compression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:02 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/26 20:26:42 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_make_compression(t_info *status)
{
	t_node	*a_node;

	a_node = status->a_node;
	if (a_node->next == a_node->prev)
		status->status = ONE_ARG;
	if (status->status != 0)
		return ;
	make_arry(status);
}

void	make_arry(t_info *status)
{
	int		i;
	t_node	*node;

	i = 0;
	status->arry = (t_node **)malloc(sizeof(t_node *) * status->list_size + 1);
	if (!status->arry)
	{
		status->status = ARRY_ERROR;
		return ;
	}
	node = status->a_node;
	node = node->next;
	while (node->value != LONG_MAX)
	{
		status->arry[i] = node;
		node = node->next;
		i++;
	}
	status->arry[i] = status->a_node;
	presort(status);
}

void	presort(t_info *status)
{
	int		i;
	int		j;

	status->status = OK_SORT;
	i = 0;
	while (i < status->list_size)
	{
		j = i + 1;
		while (j < status->list_size)
		{
			swap_check_args(status, i, j);
			if (status->status == SAME_ARGS)
				return ;
			j++;
		}
		i++;
	}
	make_compression(status);
}

void	swap_check_args(t_info *status, int i, int j)
{
	t_node	*inode;
	t_node	*jnode;

	inode = status->arry[i];
	jnode = status->arry[j];
	if (jnode->value == inode->value)
	{
		status->status = SAME_ARGS;
		return ;
	}
	else if (jnode->value < inode->value)
	{
		status->arry[i] = jnode;
		status->arry[j] = inode;
		status->status = 0;
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
