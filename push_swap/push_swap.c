/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:46:54 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/07 18:57:31 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void arraylen(int *tab)
{
	printf("%lu", sizeof(tab)/sizeof(tab[0]));
}
int ft_strlen(char *str)
{
	int x = 0;
	while(str[x])
		x++;
	return (x);
}
long long	ft_atoi(const char *str)
{
	int		a;
	long long	res;
	int		nb;

	a = 0;
	nb = 1;
	res = 0;
	if(str[a] == '-' && str[a + 1] == '-')
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
t_nvr *stack_b(int a)
{
	t_nvr *x = malloc(sizeof(t_nvr));
	x = newlst(&a);
	return x;
}

void push_swap(char **sot, int cnt)
{
	t_var	x;
	
	x.a = 0;
	x.b = 0;
	x.x = 0;
	x.str = ft_strjoin(cnt, sot, " ");
	sot = ft_split(x.str, ' ');
	check_case(sot);
    x.tab = malloc(cnt * sizeof(int));
    while(sot[x.a])
        x.tab[x.b++] = ft_atoi(sot[x.a++]);
	check_sort(x.tab, cnt - 1);
	sortadd(x.tab, x.a);
	 //while(x.a < cnt - 1)
	// 	tab1 = (int *)stack_b(x.tab[a++]);
	// x.b = 0;
	// while(x.b < x.a)
	// 	printf("%d\n", x.tab[x.b++]);
	
}
int main(int ac, char **av)
{
    if(ac >= 2)
        push_swap(av, ac);
}