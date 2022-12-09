/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:46:54 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/09 19:03:25 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void arraylen(int *tab)
// {
// 	printf("%lu", sizeof(tab)/sizeof(tab[0]));
// }
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

// t_nvr *stack_b(int n)
// {
// 	ft_lstadd_back(newlst(n), n);
// }

void push_swap(char **sot, int cnt)
{
	t_var	x;
	t_nvr	*t;
	
	t = NULL;
	x.a = 0;
	x.b = 0;
	x.x = 0;
	x.str = ft_strjoin(cnt, sot, " ");
	sot = ft_split(x.str, ' ');
	check_case(sot);
	while(x.a < cnt - 1)
		insert(&t,ft_atoi(sot[x.a++]));
	// check_sort(t);
	// ft_lstdelone(t);
	//sortadd(x.tab, x.a);
	while(t != NULL)
	{
		printf("%d\n", t -> stack);
		t = t -> next;
	}
}
int main(int ac, char **av)
{
    if(ac >= 2)
        push_swap(av, ac);
}