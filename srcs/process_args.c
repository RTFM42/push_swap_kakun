/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosess_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:42:12 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/25 17:39:54 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long int	plus_atoi(const char *str, t_info *status, int *count);
static long long int	minus_atoi(const char *str, t_info *status, int *count);

int	check_num(char *str, t_info *status)
{
	int	i;

	i = 0;
	(void)status;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
	{
		status->status = ARGS_ERROR;
		return (1);
	}
	if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
	{
		status->status = ARGS_ERROR;
		return (1);
	}
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n'
		|| c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

static long long int	plus_atoi(const char *str, t_info *status, int *count)
{
	long long int	result;
	long long int	l_divis;
	char			l_remain;
	int				i;

	i = 0;
	result = 0;
	l_divis = LONG_MAX / 10;
	l_remain = LONG_MAX % 10 + '0';
	if (!ft_isdigit(str[i]))
	{
		return (0);
	}
	while (ft_isdigit(str[i]))
	{
		if ((l_divis == result && l_remain < str[i])
			|| l_divis < result)
			return (LONG_MAX);
		result = result * 10 + (str[i] - '0');
		if (INT_MAX < result)
			status->status = ARGS_ERROR;
		i++;
	}
	*count = *count + i;
	return (result);
}

static long long int	minus_atoi(const char *str, t_info *status, int *count)
{
	long long int	result;
	long long int	l_divis;
	char			l_remain;
	int				i;

	i = 0;
	result = 0;
	l_divis = LONG_MIN / 10;
	l_remain = (LONG_MIN % 10 * -1) + '0';
	while (ft_isdigit(str[i]))
	{
		if ((l_divis == result && l_remain < str[i])
			|| l_divis > result)
			return (LONG_MIN);
		result = result * 10 - (str[i] - '0');
		if (result < INT_MIN)
			status->status = ARGS_ERROR;
		i++;
	}
	*count = *count + i;
	return (result);
}

int	ps_atoi(const char *str, t_info *status, int *count)
{
	while (ft_isspace(str[*count]))
		*count = *count + 1;
	if (str[*count] == '-')
	{
		*count = *count + 1;
		return ((int)minus_atoi(&str[*count], status, count));
	}
	else if (str[*count] == '+')
			*count = *count + 1;
	return ((int)plus_atoi(&str[*count], status, count));
}
