/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:19:20 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/26 16:59:01 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_info *status, int argc, char **argv)
{
	check_args(status, argc, argv);
	if (status->status != 0)
		return ;
	check_make_compression(status);
	if (status->status != 0)
		return ;
	if (status->list_size == 1)
		return ;
	else if (status->list_size == 2)
		sort_2args(status->a_node);
	else if (status->list_size == 3)
		sort_3args(status);
	else
	{
		sort_over4(status);
		rev_args(status);
	}
}

void	check_args(t_info *status, int argc, char *argv[])
{
	int	i;
	int	j;
	int	check;

	i = 1;
	while (i < argc)
	{
		j = 0;
		check = 0;
		while (argv[i][j] != '\0')
		{
			check += ft_isdigit(argv[i][j]);
			j++;
		}
		if (check == 0)
			status->status = NO_ARGS;
		i++;
	}
}
