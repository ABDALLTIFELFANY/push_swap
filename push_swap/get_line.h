/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:12:47 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/26 10:57:05 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LINE_H
# define GET_LINE_H

# include "push_swap.h"
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_get
{
	char	*buff;
	char	*hold;
	char	*s2;
	char	*s1;
	int		a;
}	t_get;

# define BUFFER_SIZE 5

char		*get_next_line(int fd);
t_list		*ft_lstnew(char *val);
void		new_node(t_list **root, char *str);
char		*ft_join(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*ft_save(char *str);
char		**ft_split(char const *s, char c);
char		*check(char *str);

#endif
