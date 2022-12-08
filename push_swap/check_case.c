/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:40:19 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/07 21:15:30 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(char *c)
{
    while(*c)
    {
        if(*c >= 48 && *c <= 57)
		    return (0);
        c++;
    }
	return (1);
}
void check_case(char **tar)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while(tar[a])
    {
        b = a;
        while(tar[b++])
        {
            if((tar[b] && ft_strcmp(tar[a], tar[b]) == 0) || tar[a][0] == '\0')
            {
                write(1, "Erorr!\n", 7);
                exit(0);
            }
            long long x = atoi(tar[a]);
            if(ft_isalpha(tar[b]) == 1 || x > INT_MAX || x < INT_MIN)
            {
                write(1, "Erorr!\n", 7);
                exit(0);
            }
        }
        a++;
    }
}
int main(int ac, char **av)
{
    check_case(av+1);   
}