/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:07:50 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/17 17:37:30 by tokazaki         ###   ########.fr       */
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
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (check_num(&argv[i][j], status) == 1)
				break ;
			count = 0;
			make_node(ps_atoi(&argv[i][j], status, &count), status);
			j += count;
			listsize++;
		}
		if (status->status != 0)
		{
			return ;
		}
		i++;
	}
	status->list_size = listsize;
	check_sort(status);
}

// int	check_args(t_node *a_node)
// {
// 	t_node	*tmp;
// 	int		prevvalue;

// 	if (a_node->next == a_node->prev)
// 		return (0);
// 	tmp = a_node->next;
// 	prevvalue = a_node->value;
// 	while (tmp->value != LONG_MAX)
// 	{
// 		if (prevvalue > tmp->value)
// 			return (1);
// 		prevvalue = tmp->value;
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
//引数が１の場合と順番通りに並んでいた場合の処理
//それ以外の場合は処理を継続

void	make_dummy_node(t_info *status)
{
	t_node	*tmp_node;

	status->a_node = (t_node *)malloc(sizeof(t_node));
	status->b_node = (t_node *)malloc(sizeof(t_node));
	if (status->a_node == NULL && status->b_node == NULL)
		status->status = 1;
	if (status->a_node == NULL)
		status->status = 2;
	if (status->b_node == NULL)
		status->status = 3;
	tmp_node = status->a_node;
	tmp_node->value = LONG_MAX;
	tmp_node->next = status->a_node;
	tmp_node->prev = status->a_node;
	tmp_node = status->b_node;
	tmp_node->value = LONG_MAX;
	tmp_node->next = status->b_node;
	tmp_node->prev = status->b_node;
}

void	make_node(int value, t_info *status)
{
	t_node	*node;
	t_node	*dummy;
	t_node	*tmp_node;

	dummy = status->a_node;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->next = dummy;
	tmp_node = dummy->prev;
	dummy->prev = node;
	tmp_node->next = node;
	node->prev = tmp_node;
}