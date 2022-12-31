/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionsII_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:24:38 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 19:09:30 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

int	find_big(int *arr, int size)
{
	int	big;
	int	x;

	big = arr[0];
	x = 1;
	while (x < size)
	{
		if (arr[x] > big)
			big = arr[x];
		x++;
	}
	return (big);
}

void	sw_ss(int *a, int *b, int *x, int *y)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void	rotate_rr(t_nvr **a, t_nvr **b)
{
	t_nvr	*tmp;
	t_nvr	*stmp;
	int		k;

	tmp = *a;
	k = (*a)-> stack;
	tmp = tmp-> next;
	stmp = tmp;
	free(*a);
	while (tmp-> next != NULL)
		tmp = tmp -> next;
	tmp -> next = ft_newlst(&k);
	*a = stmp;
	tmp = *b;
	k = (*b)-> stack;
	tmp = tmp -> next;
	stmp = tmp;
	free(*b);
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = ft_newlst(&k);
	*b = stmp;
}

void	reverse_rotate_rrr(t_nvr **a, t_nvr **b)
{
	t_nvr	*tmp;
	int		k;

	tmp = *a;
	while (tmp -> next)
		tmp = tmp -> next;
	k = tmp -> stack;
	free(tmp);
	tmp = *a;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = NULL;
	ft_lstadd_front(&*a, ft_newlst(&k));
	tmp = *b;
	while (tmp -> next)
		tmp = tmp -> next;
	k = tmp -> stack;
	free(tmp);
	tmp = *b;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = NULL;
	ft_lstadd_front(&*b, ft_newlst(&k));
}
