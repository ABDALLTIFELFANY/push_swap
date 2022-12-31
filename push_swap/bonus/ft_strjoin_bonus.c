/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:08:43 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 17:09:00 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

static int	ft_countlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

void	jwan(int size, char **strs, char *sep, char *ar)
{
	int	a;
	int	z;
	int	ab;

	a = 1;
	z = 0;
	ab = 0;
	while (a < size)
	{
		while (strs[a][z])
			ar[ab++] = strs[a][z++];
		z = 0;
		while (sep[z] && a < (size - 1))
			ar[ab++] = sep[z++];
		z = 0;
		a++;
	}
	ar[ab] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		x;
	int		y;
	int		a;
	char	*ar;

	a = 0;
	if (size < 0)
		return (0);
	if (size == 0)
	{
		ar = (char *)malloc(1 * sizeof(char));
		return (ar);
	}
	while (a < size)
		x = x + ft_countlen(strs[a++]);
	y = ft_countlen(sep) * (size - 1);
	y = x + y;
	ar = (char *)malloc(y * sizeof(char));
	jwan(size, strs, sep, ar);
	return (ar);
}
