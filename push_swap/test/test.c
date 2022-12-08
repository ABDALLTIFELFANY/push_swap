/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:06:51 by abelfany          #+#    #+#             */
/*   Updated: 2022/11/27 11:42:52 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nvr	*ft_lstnew(int *val)
{
	t_nvr	*hel;

	hel = malloc(sizeof(t_nvr));
	if (!hel)
		return (0);
	hel -> stack = val;
	return (hel);
}
int main()
{
	int tab[2] = {1, 8};
	printf("%d", ft_lstnew(tab) -> stack[1]);
}
