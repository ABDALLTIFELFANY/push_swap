/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:25:36 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 21:39:35 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_nvr **lst)
{
	if (!lst)
		return ;
	while (*lst)
	{
		free(*lst);
		(*lst) = (*lst)-> next;
	}
}

long long	ft_atoi(const char *str)
{
	int			a;
	long long	res;
	int			nb;

	a = 0;
	nb = 1;
	res = 0;
	if (str[a] == '-' && str[a + 1] == '-')
	{
		printf("Erorr!\n");
		exit(0);
	}
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '-')
		nb *= -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		res *= 10;
		res = res + str[a] - 48;
		a++;
	}
	if (res > INT_MAX)
		return (4294967295);
	if (res < INT_MIN)
		return (-4294967295);
	return (res * nb);
}
