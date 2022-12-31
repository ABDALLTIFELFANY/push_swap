/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:40:19 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 21:08:05 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_nvr *t, char **strs)
{
	int	j;

	j = 0;
	while (t != NULL && t-> next)
	{
		if ((t-> stack) > (t-> next -> stack))
			j = 1;
		t = t-> next;
	}
	if (j == 0)
		exit(ft_free(strs));
	return (1);
}

int	ft_isalpha(char *c)
{
	int	a;

	a = -1;
	if (c[0] == '-')
		a++;
	while (c[a++])
	{
		if ((c[a] >= 32 && c[a] <= 47) || (c[a] >= 58 && c[a] <= 127))
			return (1);
	}
	return (0);
}

void	check_case(char **tar)
{
	long long	x;
	int			a;
	int			b;

	a = 0;
	while (tar[a])
	{
		b = a;
		while (tar[b++])
		{
			if ((tar[b] && ft_strcmp(tar[a], tar[b]) == 0) || tar[a][0] == '\0')
			{
				write(1, "Erorr!\n", 7);
				exit(ft_free(tar));
			}
			x = ft_atoi(tar[a]);
			if (ft_isalpha(tar[a]) == 1 || x > INT_MAX || x < INT_MIN)
			{
				write(1, "Erorr!\n", 7);
				exit(ft_free(tar));
			}
		}
		a++;
	}
}
