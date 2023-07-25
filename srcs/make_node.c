/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:07:50 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 21:10:04 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_args_and_make_structs(int argc, char *argv[], t_info *status)
{
	int	i;
	int	j;
	int	count;
	int	listsize;

	listsize = 0;
	i = 1;
	make_dummy_node(status);
	while (i < argc && status->status == 0)
	{
		j = 0;
		while (argv[i][j] != '\0' && status->status == 0)
		{
			count = 0;
			make_node(ps_atoi(&argv[i][j], status, &count), status);
			j += count;
			listsize++;
		}
		i++;
	}
	status->list_size = listsize;
	check_sort(status);
}

//引数が１つの場合は戻す
void	check_node(t_info *status)
{
	t_node	*a_node;

	a_node = status->a_node;
	if (a_node->next == a_node->prev)
		status->status = ONE_ARG;
}

//dummynodeを作成する
void	make_dummy_node(t_info *status)
{
	t_node	*tmp_node;

	status->a_node = (t_node *)malloc(sizeof(t_node));
	status->b_node = (t_node *)malloc(sizeof(t_node));
	if (status->a_node == NULL)
		status->status = A_NODE_ERROR;
	if (status->b_node == NULL)
		status->status = B_NODE_ERROR;
	if (status->a_node == NULL && status->b_node == NULL)
		status->status = BOTH_NODE_ERROR;
	tmp_node = status->a_node;
	tmp_node->value = LONG_MAX;
	tmp_node->compression = LONG_MAX;
	tmp_node->next = status->a_node;
	tmp_node->prev = status->a_node;
	tmp_node = status->b_node;
	tmp_node->value = LONG_MAX;
	tmp_node->compression = LONG_MAX;
	tmp_node->next = status->b_node;
	tmp_node->prev = status->b_node;
}

//構造体のアドレスの配列を作成する
void	make_arry(t_info *status)
{
	int		i;
	t_node	*node;

	i = 0;
	status->arry = (t_node **)malloc(sizeof(t_node *) * status->list_size + 1);
	if (!status->arry)
	{
		status->status = -20;
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
}

//nodeを作成する
void	make_node(int value, t_info *status)
{
	t_node	*node;
	t_node	*dummy;
	t_node	*tmp_node;

	dummy = status->a_node;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		status->status = NODE_ERROR;
		return ;
	}
	node->value = value;
	node->next = dummy;
	tmp_node = dummy->prev;
	dummy->prev = node;
	tmp_node->next = node;
	node->prev = tmp_node;
}
