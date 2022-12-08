/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:43:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/11/27 11:46:03 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nvr	*newlst(int *val)
{
	t_nvr	*hel;

	hel = malloc(sizeof(t_nvr));
	if (!hel)
		return (0);
	hel -> stack = val;
	return (hel);
}