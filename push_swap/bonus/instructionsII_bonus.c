/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionsII.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:24:38 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/25 14:20:46 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sw_ss(int *a, int *b, int *x, int *y)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	temp = *y;
	*y = *x;
	*x = temp;
	write(1, "ss\n", 3);
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
	while (tmp-> next != NULL)
		tmp = tmp -> next;
	tmp -> next = ft_lstnew(&k);
	*a = stmp;
	tmp = *b;
	k = (*b)-> stack;
	tmp = tmp -> next;
	stmp = tmp;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = ft_lstnew(&k);
	*b = stmp;
	write(1, "rr\n", 3);
}

void	reverse_rotate_rrr(t_nvr **a, t_nvr **b)
{
	t_nvr	*tmp;
	int		k;

	tmp = *a;
	while (tmp -> next)
		tmp = tmp -> next;
	k = tmp -> stack;
	tmp = *a;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = NULL;
	ft_lstadd_front(&*a, ft_lstnew(&k));
	tmp = *b;
	while (tmp -> next)
		tmp = tmp -> next;
	k = tmp -> stack;
	tmp = *b;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = NULL;
	ft_lstadd_front(&*b, ft_lstnew(&k));
	write(1, "rrr\n", 4);
}
