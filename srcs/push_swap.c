/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:50:24 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/26 13:52:52 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	*status;

	if (argc == 1)
		return (0);
	status = (t_info *)malloc(sizeof(t_info));
	if (!status)
		return (0);
	status->status = 0;
	status->a_node = NULL;
	status->b_node = NULL;
	status->arry = NULL;
	status->list_size = 0;
	process_args_and_make_structs(argc, argv, status);
	if (status->status == OK_SORT || status->status == ONE_ARG)
		;
	else if (status->status)
		ft_putstr_fd("ERROR\n", 0);
	all_free(status);
	exit (0);
	return (0);
}

void	all_free(t_info	*status)
{
	node_free(status->a_node);
	node_free(status->b_node);
	free (status->arry);
	free (status);
}

void	node_free(t_node *node)
{
	t_node	*tmp;

	node = node->next;
	while (node->value != LONG_MAX)
	{
		tmp = node->next;
		free (node);
		node = tmp;
	}
	free (node);
}
