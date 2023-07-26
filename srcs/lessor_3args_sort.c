/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_3args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:48:56 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 18:57:11 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2args(t_node *node)
{
	long	value1;
	long	value2;

	value1 = node->next->value;
	value2 = node->next->next->value;
	if (value1 < value2)
		return ;
	sa(node);
}

void	sort_3args(t_info *status)
{
	long	value1;
	long	value2;
	long	value3;

	value1 = status->a_node->next->value;
	value2 = status->a_node->next->next->value;
	value3 = status->a_node->next->next->next->value;
	if (value1 < value2 && value2 < value3)
		return ;
	else if (value2 < value1 && value3 < value1)
		ra(status->a_node);
	else if (value2 < value1 && value1 < value3)
		sa(status->a_node);
	else if ((value1 < value3 && value3 < value2) \
			|| (value3 < value1 && value1 < value2))
		rra(status->a_node);
	sort_3args(status);
}
