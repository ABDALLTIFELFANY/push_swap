/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:26:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 11:08:36 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fil_list(t_nvr **lst, int inx)
{
	insert(lst, inx);
}

t_nvr	*longest_inc(int *tab, int *arr, int lis, t_nvr *head)
{
	t_var2	nb;

	nb.j = 0;
	nb.a = -1;
	nb.list = NULL;
	while (tab[nb.j] != lis)
		nb.j++;
	nb.art = malloc(sizeof(int) * lis);
	while (++nb.a < lis)
	{
		nb.art[nb.a] = nb.j;
		nb.j = arr[nb.j];
	}
	nb.j = 0;
	while (--nb.a > -1)
	{
		while (nb.j < nb.art[nb.a])
		{
			head = head-> next;
			nb.j++;
		}
		fil_list(&nb.list, head -> stack);
	}
	return (free(nb.art), nb.list);
}

void	ft_lis_utils(int *arr, int *tab, t_nvr *lis, int size)
{
	int		j;
	int		i;
	t_nvr	*head;
	t_nvr	*jbl;

	i = -1;
	head = lis;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (jbl -> stack < lis -> stack && tab[j] + 1 >= tab[i])
			{
				tab[i] = tab[j] + 1;
				arr[i] = j;
			}
			jbl = jbl -> next;
		}
		lis = lis -> next;
		jbl = head;
	}
}

t_nvr	*ft_lis(t_nvr *lng, int size, int min, t_nvr *last)
{
	t_lis	lis;
	t_nvr	*reg;
	t_nvr	*head;
	int		a;

	a = 0;
	lis.tab = malloc(sizeof(int) * size);
	lis.arr = malloc(sizeof(int) * size);
	reg = lng;
	while (a < size)
		lis.tab[a++] = 1;
	while (lng -> stack != min)
		lng = lng -> next;
	head = lng;
	ft_lis_utils(lis.arr, lis.tab, lng, size);
	lis.indxs = longest_inc(lis.tab, lis.arr, find_big(lis.tab, size), head);
	free(lis.tab);
	free(lis.arr);
	return (d_link(&lng, last, reg), lis.indxs);
}
