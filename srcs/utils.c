/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:44:59 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 18:56:09 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance(int nbr, int size)
{
	if (size / 2 < nbr)
		return (-size + nbr);
	return (nbr);
}

int	abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}
