/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:02:05 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/09 17:54:23 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void del(t_nvr *kjm)
{
    free(kjm);    
}
void	ft_lstdelone(t_nvr *lst)
{
	if (!lst)
		return ;
	del(lst -> stack);
}
// int main()
// {
//     t_list *head = ft_lstne(ft_strdup("0"));
//     t_list *node1 = ft_lstne(ft_strdup("156"));
//     t_list *node2 = ft_lstne(ft_strdup("2"));
//     t_list *node3 = ft_lstne(ft_strdup("3"));
//     head -> next = node1;
//     node1 -> next = node2;
//     node2 -> next = node3;
//     t_list *tmp = node1 -> next;
//     t_list *tmp1 = head;
//     tmp1 -> next = tmp;
//     ft_lstdelone(node1,del);
//     while(tmp1)
//     {
//         printf("%s", tmp1 -> content);
//         tmp1 = tmp1 -> next;
//     }
// }