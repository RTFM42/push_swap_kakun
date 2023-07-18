/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:50:24 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/18 12:35:25 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_free(t_node *node);
void	all_free(t_info	*status);
void	debug(t_info *status);

int	main(int argc, char *argv[])
{
	t_info	*status;

	if (argc == 1)
		return (0);
	status = (t_info *)malloc(sizeof(t_info));
	if (!status)
		return (0);
	status->status = 0;
	process_args_and_make_structs(argc, argv, status);
	if (status->status)
		printf("\nERROR : %d\n\n",status->status);
	debug(status);
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
	node_free(status->a_node);
	node_free(status->b_node);
	free (status);
}

//ps_atoi
//error処理＆send errorメッセージ
//sort set sa スタックaの先頭の2つの要素を交換
//sort set sb スタックbの先頭の2つの要素を交換
//sort set ss saとsbを同時に実行
//sort set pa スタックbの先頭の要素をaの先頭に置く
//sort set pb スタックaの先頭の要素をbの先頭に置く
//sort set ra aのすべての要素を1つシフトアップ
//sort set rb bのすべての要素を1つシフトアップ
//sort set rr raとrbを同時に実行
//sort set rra aのすべての要素を1つシフトダウン
//sort set rrb スタックbのすべての要素を1つシフトダウン
//sort set rrr rraとrrbを同時に実行
//
