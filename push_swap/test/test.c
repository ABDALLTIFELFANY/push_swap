/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:06:51 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/09 15:11:53 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void insert(t_nvr **root, int item)
{
//    t_nvr	*temp = malloc(sizeof(t_nvr));
//     t_nvr	*ptr;
//     temp->stack = item;
//     temp->next = NULL;
//     if (*root == NULL)
//         *root = temp;
    // else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    // }
}
// t_nvr	*ft_lstnew(int val)
// {
// 	t_nvr	*hel;

// 	hel = malloc(sizeof(t_nvr));
// 	if (!hel)
// 		return (0);
// 	hel -> stack = val;
// 	return (hel);
// }
int main()
{
	int *tab = malloc(5 * sizeof(int));
	int a = 0;
	while(a < 5)
	{
		tab[a] = a + 1;
		a++;
	}
	a = 0;
	t_nvr *t = NULL;
	while(a < 5)
		printf("%d\n", tab[a++]);
	printf("------------------------");
	a = 0;
	while(a < 5)
	{
		insert(&t,tab[a]);
		a++;
	}
	while(t != NULL){
		printf("%d\n", t -> stack);
		t = t -> next;
	}
}
