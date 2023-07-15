/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:07:50 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/15 21:05:36 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_node(int arg, t_info *status);
void	make_dummy_node(t_info *status);

void	process_args_and_make_structs(int argc,char *argv[], t_info *status)
{
	int	i;
	t_node *tmp;

	i = 0;
//	(void)argc;
//	(void)status;
	make_dummy_node(status);
	while (i < argc)
	{
		printf("argc : %d\n",i);
		make_node(ft_atoi(argv[i]), status);
		i++;
	}
	tmp = status->a_node;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->prev;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->prev;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->prev;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->prev;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->prev;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->next;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->next;
//	printf("%ld\n",tmp->value);
//	tmp = tmp->next;
//	printf("%ld\n",tmp->value);
//	while (tmp->value == INT_MAX)
//	{
//		printf("%ld\n",tmp->value);
//		tmp = tmp->next;
//	}
}

void	make_dummy_node(t_info *status)
{
	t_node *tmp_node;

	status->a_node = (t_node *)malloc(sizeof(t_node));
	status->b_node = (t_node *)malloc(sizeof(t_node));
	if (status->a_node == NULL && status->b_node == NULL)
		status->status = 1;
	if (status->a_node == NULL)
		status->status = 2;
	if (status->b_node == NULL)
		status->status = 3;
	tmp_node = status->a_node;
	tmp_node->value = INT_MAX;
	tmp_node->next = status->a_node;
	tmp_node->prev = status->a_node;
		printf("a_node : %ld\n",tmp_node->value);
	tmp_node = status->b_node;
	tmp_node->value = INT_MAX;
	tmp_node->next = status->b_node;
	tmp_node->prev = status->b_node;
		printf("b_node : %ld\n",tmp_node->value);
}

void	make_node(int arg, t_info *status)
{
	t_node *node;
	t_node *dummy;
	t_node *tmp_node;

	dummy = status->a_node;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = arg;
	node->next = dummy;
	dummy->next = node;
	tmp_node = dummy->next;
		printf("%p:%p\n",tmp_node->next, dummy);
	while (tmp_node->next != dummy)
	{
		printf("%ld\n",tmp_node->value);
		tmp_node = tmp_node->next;
	}
	tmp_node->next = node;
	node->prev = tmp_node;
}

//int	ft_atoi(const char *str)
//{
//	size_t			i;
//	int				flag;
//	long long int	nbr;
//
//	i = 0;
//	nbr = 0;
//	flag = 0;
//	while (ft_isspace(*str))
//		str++;
//	if (*str == '-')
//	{
//		str++;
//		return ((int)minus_atoi(str));
//	}
//	else if (*str == '+')
//		str++;
//	return ((int)plus_atoi(str));
//}
//
//static int	ft_isspace(int c)
//{
//	if (c == ' ' || c == '\n'
//		|| c == '\t' || c == '\r'
//		|| c == '\f' || c == '\v')
//		return (1);
//	return (0);
//}
//
//static long long int	plus_atoi(const char *str)
//{
//	long long int	result;
//	long long int	l_divis;
//	char			l_remain;
//
//	result = 0;
//	l_divis = LONG_MAX / 10;
//	l_remain = LONG_MAX % 10 + '0';
//	while (ft_isdigit(*str))
//	{
//		if ((l_divis == result && l_remain < *str)
//			|| l_divis < result)
//			return (LONG_MAX);
//		result = result * 10 + (*str - '0');
//		str++;
//	}
//	return (result);
//}
//
//static long long int	minus_atoi(const char *str)
//{
//	long long int	result;
//	long long int	l_divis;
//	char			l_remain;
//
//	result = 0;
//	l_divis = LONG_MIN / 10;
//	l_remain = (LONG_MIN % 10 * -1) + '0';
//	while (ft_isdigit(*str))
//	{
//		if ((l_divis == result && l_remain < *str)
//			|| l_divis > result)
//			return (LONG_MIN);
//		result = result * 10 - (*str - '0');
//		str++;
//	}
//	return (result);
//}
