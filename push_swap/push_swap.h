/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:50:43 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/07 17:30:36 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type));

typedef struct s_var
{
    int a;
    int b;
	int x;
	char *str;
    int *tab;
}	t_var;

typedef struct s_nvr
{
    int *stack;
    struct s_nvr *next;
}   t_nvr;

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

long long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
t_nvr	*newlst(int *val);
int	    ft_strcmp(char *s1, char *s2);
void    push_swap(char **sot, int cnt);
void    check_case(char **tar);
void	sortadd(int *tab, int size);
void  check_sort(int *tab, int size);
char	*ft_strjoin(int size, char **strs, char *sep);

#endif