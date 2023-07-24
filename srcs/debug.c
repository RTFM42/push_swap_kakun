/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:10:54 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/24 19:09:08 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

__attribute__((destructor))
static void	destructor(void)
{
//	system("leaks -q push_swap");
}

void	debug_arry(t_info *status)
{
	printf("-------debug_arry-----------\n");
	int		i;
	t_node	*tmp;
	t_node	**arry;

	arry = status->arry;
	i = 0;
	while (i < status->list_size)
	{
		tmp = arry[i];
		printf("arry[%d] : %ld\n", i, tmp->value);
		i++;
	}
		tmp = arry[i];
		printf("arry[%d] : %ld\n", i, tmp->value);
}

void	debug_comp(t_info *status)
{
(void)status;
//	printf("--------debug-compression--------\n");
//	int		i;
//	t_node	*tmp;
//
//	tmp = status->a_node;
//	tmp = tmp->next;
//	i = 0;
//	while (tmp->value != LONG_MAX)
//	{
//		printf("a_node[%d] : %ld\n", i, tmp->compression);
//		tmp = tmp->next;
//		i++;
//	}
//	printf("a_node[%d] : %ld\n", i, tmp->compression);
//	tmp = status->b_node;
//	tmp = tmp->next;
//	i = 0;
//	while (tmp->value != LONG_MAX)
//	{
//		printf("b_node[%d] : %ld\n", i, tmp->compression);
//		tmp = tmp->next;
//		i++;
//	}
//	printf("b_node[%d] : %ld\n\n", i, tmp->compression);
//	printf("-----------------\n");
}

void	debug(t_info *status)
{
(void)status;
	printf("--------debug--compression-------\n");
	int		i;
	t_node	*tmp;

	tmp = status->a_node;
	tmp = tmp->next;
	i = 0;
	while (tmp->value != LONG_MAX)
	{
		printf("a_node[%2d] : %2ld : %5ld\n", i, tmp->compression,tmp->value);
		tmp = tmp->next;
		i++;
	}
	printf("a_node[%2d] : %2ld : %5ld\n", i, tmp->compression,tmp->value);
	tmp = status->b_node;
	tmp = tmp->next;
	i = 0;
	while (tmp->value != LONG_MAX)
	{
		printf("b_node[%2d] : %2ld : %5ld\n", i, tmp->compression,tmp->value);
		tmp = tmp->next;
		i++;
	}
	printf("b_node[%2d] : %2ld : %5ld\n\n", i, tmp->compression,tmp->value);
	printf("-----------------\n");
}

