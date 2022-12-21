/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:19:33 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/18 15:30:27 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*------------------helpers------------------*/
void	ft_lstadd_front(t_nvr **lst, t_nvr *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*------------------instructions------------------*/
void rotate_a_b(t_nvr **a, char c) // --rotate a - rotate b-- //
{
	t_nvr	*tmp;
	t_nvr	*stmp;
	int		k;

	tmp = *a; 
	k = (*a) -> stack;
	tmp = tmp -> next;
	stmp = tmp;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = ft_lstnew(&k);
	*a = stmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	push_a_b(t_nvr **a, t_nvr **b, char c) // --push a -push b-- //
{
    t_nvr	*temp;
    t_nvr	*tab;

    temp = (*a) -> next;
    tab = *a; 
    tab -> next = *(b);
    *a = temp;
    *b = tab;
    if (c == 'a')
        write(1, "pb\n", 3);
    if (c == 'b')
        write(1, "pa\n", 3);
}

void	swap_a_b(int *a, int *b, char c) // --swap a - swap b-- //
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	reverse_rotate_a_b(t_nvr **a, char c) // --reverse_rotate a - reverse_rotate a-- //
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
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}