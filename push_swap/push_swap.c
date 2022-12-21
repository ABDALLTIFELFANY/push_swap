/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:46:54 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/21 22:39:33 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lenstrs(char **strs)
{
	int x = 0;
	while(strs[x])
		x++;
	return (x);
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

void push_swap(char **sot, int cnt)
{
	t_var	x;
	t_nvr	*a;
	t_nvr	*b;
	t_nvr	*indexs;
	
	x.a = -1;
	x.b = 0;
	x.x = 0;
	a = NULL;
	b = NULL;
	x.str = ft_strjoin(cnt, sot, " ");
	sot = ft_split(x.str, ' ');
	check_case(sot);
	while(++x.a < ft_lenstrs(sot))
		insert(&a,ft_atoi(sot[x.a]));
	check_sort(a);
	//printf("head = {%d}\n", x.lis);
	x.lis = find_longest(a);
	indexs = find_who_p_b(a,x.lis);
	sort_stacks(&a,&b,indexs);
	//sort_a(&a,&b,x.lis);
	// while(a)
    // {
    //     printf("%d\n", a -> stack);
    //     a = a -> next;
    // }
	// printf("----------\n");
	// while(b)
    // {
    //     printf("%d\n", b -> stack);
    //     b = b -> next;
    // }
}
int main(int ac, char **av)
{
    if(ac >= 2)
        push_swap(av, ac);
}