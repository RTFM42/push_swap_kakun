/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:50:24 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 21:22:08 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_free(t_node *node);
void	all_free(t_info	*status);

int	main(int argc, char *argv[])
{
	t_info	*status;

	if (argc == 1)
		return (0);
	status = (t_info *)malloc(sizeof(t_info));
	if (!status)
		return (0);
	status->status = 0;
	status->list_size = 0;
	process_args_and_make_structs(argc, argv, status);
	if (status->status == -1 || status->status == -3)
		;
	else if (status->status)
		ft_putstr_fd("ERROR\n", 0);
//	debug(status);
	exit (0);
	all_free(status);
	return (0);
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

void	all_free(t_info	*status)
{
	if (status->status == BOTH_NODE_ERROR)
		;
	if (status->status == A_NODE_ERROR)
		node_free(status->b_node);
	if (status->status == B_NODE_ERROR)
		node_free(status->a_node);
	if (status->status == NODE_ERROR)
	{
		node_free(status->a_node);
		node_free(status->b_node);
	}
	if (status->status != B_NODE_ERROR && status->status != A_NODE_ERROR \
			&& status->status != NODE_ERROR)
		free (status->arry);
	free (status);
}
