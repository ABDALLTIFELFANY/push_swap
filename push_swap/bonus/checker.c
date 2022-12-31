/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:08:35 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 20:28:55 by abelfany         ###   ########.fr       */
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

int ft_free(char **strs)
{
	int x;
	
	x = 0;
	while(strs[x])
		free(strs[x++]);
	free(strs);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

void sort_ch(t_list *ins, t_nvr **a, t_nvr **b)
{
	while(ins)
	{
		if(ft_strcmp(ins -> content,"sa\n") == 0)
			swap_a_b(&(*a) -> stack, &(*a) -> next -> stack);
		else if (ft_strcmp(ins -> content,"sb\n") == 0)
			swap_a_b(&(*b) -> stack, &(*b) -> next -> stack);
		else if (ft_strcmp(ins -> content,"pa\n") == 0)
			push_a_b(b,a);
		else if (ft_strcmp(ins -> content,"pb\n") == 0)
			push_a_b(a,b);
		else if (ft_strcmp(ins -> content,"ra\n") == 0)
			rotate_a_b(a);
		else if (ft_strcmp(ins -> content,"rra\n") == 0)
			reverse_rotate_a_b(a);
		else if (ft_strcmp(ins -> content,"rb\n") == 0)
			rotate_a_b(b);
		else if (ft_strcmp(ins -> content,"rrb\n") == 0)
			reverse_rotate_a_b(b);
		else if (ft_strcmp(ins -> content,"rrr\n") == 0)
			reverse_rotate_rrr(a,b);
		else if (ft_strcmp(ins -> content,"rr\n") == 0)
			rotate_rr(a,b);
		ins = ins -> next;
	}
}
void	checker(char **av, int cnt)
{
	t_get	x;
	t_nvr	*a;
	t_nvr	*b;
	t_list	*ins;
	char	*str;
	char	*line;

	x.b = -1;
	x.x = 0;
	a = NULL;
	b = NULL;
	ins = NULL;
	str = ft_strjoin(cnt, av, " ");
	av = ft_split(str, ' ');
	check_case(av);
	line = get_line(0);
	while (++x.b < ft_lenstrs(av))
		insert(&a, ft_atoi(av[x.b]));
	while(line)
	{
		new_node(&ins, line);
		line = get_line(0);	
	}
	sort_ch(ins,&a,&b);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		checker(av, ac);
}
