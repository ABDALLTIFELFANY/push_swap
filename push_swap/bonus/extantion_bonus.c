/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extantion_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:12:12 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/26 10:58:52 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

t_list	*ft_lstnew(char *val)
{
	t_list	*hel;

	hel = malloc(sizeof(t_nvr));
	if (!hel)
		return (0);
	hel -> content = *val;
	hel -> next = NULL;
	return (hel);
}

void	new_node(t_list **root, char *str)
{
	t_list	*temp;
	t_list	*ptr;

	temp = malloc(sizeof(t_list));
	temp -> content = str;
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
