/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:12:47 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 19:33:57 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LINE_H
# define GET_LINE_H

# include<unistd.h>
# include<limits.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_nvr
{
	int				stack;
	struct s_nvr	*next;
}	t_nvr;

typedef struct s_get
{
	char	*buff;
	char	*hold;
	char	*s2;
	char	*s1;
	int		a;
	int		x;
	int		b;
}	t_get;

# define BUFFER_SIZE 5

char		*get_line(int fd);
int			ft_strcmp(char *s1, char *s2);
void		insert(t_nvr **root, int item);
int			ft_free(char **strs);
void		ft_lstadd_front(t_nvr **lst, t_nvr *new);
void		check_case(char **tar);
t_nvr		*ft_newlst(int *val);
void		new_node(t_list **root, char *str);
char		*ft_join(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*ft_ft_save(char *str);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(int size, char **strs, char *sep);
char		*check(char *str);
void		reverse_rotate_rrr(t_nvr **a, t_nvr **b);
void		sw_ss(int *a, int *b, int *x, int *y);
void		rotate_rr(t_nvr **a, t_nvr **b);
void		reverse_rotate_a_b(t_nvr **a);
void		rotate_a_b(t_nvr **a);
void		swap_a_b(int *a, int *b);
void		push_a_b(t_nvr **a, t_nvr **b);


#endif
