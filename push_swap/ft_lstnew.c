/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:43:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/29 16:11:48 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_nvr *lst)
{
	int	a;

	a = 0;
	while (lst != NULL)
	{
		lst = lst-> next;
		a++;
	}
	return (a);
}

void	d_link(t_nvr **stack, t_nvr *last, t_nvr *reg)
{
	while ((*stack)-> stack != last-> stack)
		(*stack) = (*stack)-> next;
	(*stack)-> next = NULL;
	(*stack) = reg;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] && s1[a] == s2[a])
		a++;
	return (s1[a] - s2[a]);
}

t_nvr	*ft_lstnew(int *val)
{
	t_nvr	*hel;

	hel = malloc(sizeof(t_nvr));
	if (!hel)
		return (0);
	hel -> stack = *val;
	hel -> next = NULL;
	return (hel);
}

void	insert(t_nvr **root, int item)
{
	t_nvr	*temp;
	t_nvr	*ptr;

	temp = malloc(sizeof(t_nvr));
	temp -> stack = item;
	temp -> next = NULL;
	if (*root == NULL)
		*root = temp;
	else
	{
		ptr = *root;
		while (ptr-> next != NULL)
			ptr = ptr->next;
		ptr -> next = temp;
	}
}
