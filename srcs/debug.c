/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:10:54 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/17 16:45:02 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q push_swap");
}

void	debug(t_info *status)
{
	int		i;
	t_node	*tmp;

	tmp = status->a_node;
	tmp = tmp->next;
	i = 0;
	while (tmp->value != LONG_MAX)
	{
		printf("a_node[%d] : %ld\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
	printf("a_node[%d] : %ld\n", i, tmp->value);
	tmp = status->b_node;
	tmp = tmp->next;
	i = 0;
	while (tmp->value != LONG_MAX)
	{
		printf("b_node[%d] : %ld\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
	printf("b_node[%d] : %ld\n", i, tmp->value);
}
