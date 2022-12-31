/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:19:33 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 19:10:32 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"
/*------------------helpers------------------*/
void	ft_lstadd_front(t_nvr **lst, t_nvr *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/*------------------instructions------------------*/
void	rotate_a_b(t_nvr **a)
{
	t_nvr	*tmp;
	t_nvr	*stmp;
	int		k;

	tmp = *a;
	k = (*a)-> stack;
	tmp = tmp -> next;
	stmp = tmp;
	free(*a);
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = ft_newlst(&k);
	*a = stmp;
}

void	push_a_b(t_nvr **a, t_nvr **b)
{
	t_nvr	*temp;
	t_nvr	*tab;

	temp = (*a)-> next;
	tab = *a;
	tab -> next = *(b);
	*a = temp;
	*b = tab;
}

void	swap_a_b(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reverse_rotate_a_b(t_nvr **a)
{
	t_nvr	*tmp;
	int		k;

	tmp = *a;
	while (tmp-> next)
		tmp = tmp-> next;
	k = tmp-> stack;
	free(tmp);
	tmp = *a;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = NULL;
	ft_lstadd_front(&*a, ft_newlst(&k));
}
