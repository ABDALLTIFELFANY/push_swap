/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:08:35 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/26 11:34:14 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

int	ft_lenstrs(char **strs)
{
	int	x;

	x = 0;
	while (strs[x])
		x++;
	return (x);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] && s1[a] == s2[a])
		a++;
	return (s1[a] - s2[a]);
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
	return (res * nb);
}

void	checker(char **av, int cnt)
{
	t_var	x;
	t_nvr	*a;
	t_nvr	*b;

	x.a = -1;
	x.b = 0;
	x.x = 0;
	a = NULL;
	b = NULL;
	x.str = ft_strjoin(cnt, av, " ");
	av = ft_split(x.str, ' ');
	check_case(av);
	while (++x.a < ft_lenstrs(av))
		insert(&a, get_next_line(1));
	printf("%d", a -> stack);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		checker(av, ac);
}
