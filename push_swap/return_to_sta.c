/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_sta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:28:39 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/29 15:23:46 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hol(t_nvr *taa, int elem, int size)
{
	t_mix	m;
	m.reg = taa;
	m.a = -1;
	int ret;
	m.min = find_small(taa);
	m.big = find_big_one(taa);
	m.last = link_lst(&taa);
	while (++m.a < size)
	{
		if (elem < m.min || elem > m.big){
			d_link(&taa, m.last, m.reg);
			return m.min;
		}
		if (taa-> stack < elem && taa-> next -> stack > elem){
			// puts("\n");
			// printf("%d    %d     %d",taa->stack,elem,taa->next->stack);
			// puts("\n");
			ret = taa->next->stack;
			d_link(&taa, m.last, m.reg);
			return(ret);
		}
		taa = taa -> next;
	}
	if (m.a > size / 2)
		m.a = size - m.a;
	d_link(&taa, m.last, m.reg);
	return (m.a);
}

int	hi(t_nvr *sta, int kk)
{
	int		size;
	t_nvr	*head;
	int		a;
	// printf("kk = %d\n", kk);

	a = 0;
	head = sta;
	size = ft_lstsize(sta);
	while (a < size)
	{
		if (sta-> stack == kk)
			break ;
		a++;
		sta = sta-> next;
	}
	sta = head;
	if (a <= size / 2)
		return (1);
	else
		return (0);
}
// void push_utils(t_nvr **sta, t_nvr **stb, t_nvr *elem, int tout)
// {
// 	int	jbl;
// 	int	a;
// 	int	stl;

// 	if(elem -> mov_a < elem -> mov_b)
// 		jbl = elem -> mov_b;
// 	else
// 		jbl = elem -> mov_a;
// 	// printf("jbl = %d\n", jbl);
// 	// printf("mov_a = %d\n", elem -> mov_a);
// 	stl = tout;
// 	//printf("mov_b = %d\n", tout);
// 	if(jbl == elem -> mov_b)
// 	{
// 		a = hi(*stb,elem -> stack);
// 		while(--tout > -1)
// 		{
// 			if(a == 1)
// 				rotate_a_b(stb,'p');
// 			if(a == 0)
// 				reverse_rotate_a_b(stb,'p');
// 		}
// 	}
// 	if(elem -> mov_a == elem -> mov_b)
// 		tout = stl;
// 	if(jbl == elem -> mov_a)
// 	{
// 		int gg = hol(*sta,elem -> stack,ft_lstsize(*sta));
// 		// printf("gg %d\n", gg);
// 		// printf("stack %d\n", elem -> stack);
// 		jbl = hi(*sta,gg);
// 		while(--tout > -1)
// 		{
// 			if(jbl == 1)
// 				rotate_a_b(sta,'a');
// 			if(jbl == 0)
// 				reverse_rotate_a_b(sta,'a');
// 		}
// 		//push_a_b(stb,sta,'p');
// 	}
// 	push_a_b(stb,sta,'p');
// }
int count_stb(t_nvr *stb, int elem, int *mark)
{
	int	a;
	int	size;

	size = ft_lstsize(stb);
	a = 0;
	while (a < size)
	{
		if (stb-> stack == elem)
			break ;
		stb = stb-> next;
		a++;
	}
	if (a > size / 2)
    {
		a = size - a;
        *mark+=1;
    }
    return a;
}

int	count_sta(t_nvr *taa, int elem, int size, int *mark)
{
	t_mix	m;

	m.reg = taa;
	m.a = -1;
	m.min = find_small(taa);
	m.big = find_big_one(taa);
	m.last = link_lst(&taa);
	while (++m.a < size)
	{
		if (taa-> stack == m.min && elem < m.min)
			break ;
		if (taa -> stack == m.big && elem > m.big)
		{
			m.a++;
			break ;
		}
		if (taa-> stack < elem && taa-> next -> stack > elem)
		{
			m.a++;
			break ;
		}
		taa = taa -> next;
	}
	if (m.a > size / 2)
    {
		m.a = size - m.a;
        *mark+=1;
    }
	d_link(&taa, m.last, m.reg);
	return (m.a);
}
void prepar_a(t_nvr **sta, t_nvr *elem)
{
	int a;
	int x;
	elem -> mov_a = count_sta(*sta, elem -> stack, ft_lstsize(*sta),&a);
	if(elem -> mov_a == 0)
		return ;
	else
	{
		int gg = hol(*sta,elem -> stack,ft_lstsize(*sta));
		a = hi(*sta,gg);
		x = elem -> mov_a;
		while(--x > -1)
		{
			if(a == 1)
				rotate_a_b(sta,'a');
			if(a == 0)
				reverse_rotate_a_b(sta,'a');
		}
	}
}
void prepar_b(t_nvr **stb, t_nvr *elem)
{
	int a;
	int x;
	elem -> mov_b = count_stb(*stb, elem -> stack,&a);
	if(elem -> mov_b == 0)
		return ;
	else
	{
		a = hi(*stb,elem -> stack);
		x = elem -> mov_b;
		while(--x > -1)
		{
			if(a == 1)
				rotate_a_b(stb,'b');
			if(a == 0)
				reverse_rotate_a_b(stb,'b');
		}
	}
}
void	push(t_nvr **sta, t_nvr **stb, t_nvr *elem)
{
	int	jbl;
	int	tout;

	if(elem -> mov_a < elem -> mov_b)
		jbl = elem -> mov_a;
	else
		jbl = elem -> mov_b;
	if(elem -> mov_a < elem -> mov_b)
		tout = elem -> mov_b;
	else
		tout = elem -> mov_a;
	if(elem -> mark == 0 || elem -> mark == 2)
	{
		tout = tout - jbl;
		while (--jbl > -1)
		{
			if(elem -> mark == 0)
				rotate_rr(sta,stb);
			if(elem -> mark == 2)
				reverse_rotate_rrr(sta,stb);
		}
	}
	prepar_a(sta,elem);
	prepar_b(stb,elem);
	push_a_b(stb,sta,'b');
}
// void min_mov(t_nvr *elem, t_nvr **sta, t_nvr **stb)
// {
// 	int a;
// 	if(elem -> mov_a > elem -> mov_b)
// 		a = elem -> mov_b;
// 	else
// 		a = elem -> mov_a;
// 	while(--a > -1)
// 	{
// 		if(elem -> mark == 0)
// 			rotate_rr(sta, stb);
// 		if(elem -> mark == 2)
// 			reverse_rotate_rrr(sta,stb);
// 	}
// }
// void	final_push(t_nvr **sta, t_nvr **stb, t_nvr *elem, char c)
// {
// 	int	jbl;
// 	if(elem -> mark == 0 || elem -> stack == 2)
// 		min_mov(elem,sta,stb);
// 	jbl = hi(*sta, elem);
// 	while (1)
// 	{
// 		if ((*sta)-> stack == elem)
// 			break ;
// 		// if (jbl == 1)
// 			rotate_a_b(&*sta, c);
// 		// if (jbl == 0)
// 		// 	reverse_rotate_a_b(&*sta, c);
// 	}
// 	push_a_b(&*stb, &*sta, 'b');
// }


void	ft_save(t_nvr **root, int *item, int mark, int elem)
{
	t_nvr	*temp;
	t_nvr	*ptr;

	temp = malloc(sizeof(t_nvr));
	temp -> mov_a = item[0];
	temp -> mov_b = item[1];
	temp -> mark = mark;
	temp -> stack = elem;
	temp -> next = NULL;
	if (*root == NULL)
		*root = temp;
	else
	{
		ptr = *root;
		while (ptr-> next != NULL)
			ptr = ptr->next;
		ptr -> next = temp;
	}
}

t_nvr *final_mov(t_nvr **sta, t_nvr **stb)
{
    int mark;
    t_nvr *head;
    t_nvr *save;
    int a[2];

    mark = 0;
    head = *stb;
	save = NULL;
	while(head)
	{
    	a[0] = count_sta(*sta,head-> stack, ft_lstsize(*sta), &mark);
    	a[1] = count_stb(*stb,head-> stack,&mark);
		ft_save(&save,a,mark,head -> stack);
		mark = 0;
		head = head -> next;
	}
	return (save);
}
// void rrr_and_push(t_nvr **sta, t_nvr **stb, t_nvr *elem)
// {
	
// }
void	return_to_sta(t_nvr **sta, t_nvr **stb)
{
	t_nvr	*final;
	t_nvr 	*elem;
	//int		he;
	
	final = NULL;
	//int a = 0;
	// head = stb;
	while (*stb)
	{
		final = final_mov(sta,stb);
		elem = find_best_mov(final);
		push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// printf("a ->%d\n", elem -> mov_a);
		// printf("b ->%d\n", elem -> mov_b);
		// printf("mark ->%d\n", elem -> mark);
		// printf("stack ->%d\n", elem -> stack);
		// push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// push(sta,stb,elem);
		// final = final_mov(sta,stb);
		// elem = find_best_mov(final);
		// // // while(final){
		//push(sta,stb,elem);
		// push(sta,stb,elem);
		// 	final = final -> next;
		// }
		//find_best_elem(elem);
		// rrr_and_push();
		
	// 	final_push(&*sta, &*stb, elem, 'a');
	// //a++;
	}
}
// int find_best_elem(t_nvr *final)
// {
// 	//int a;
// 	t_nvr *head = NULL;
// 	t_nvr *save = final;
// 	while(head -> next -> next)
// 	{
// 		head = final;
// 		if(head -> next -> next -> stack < final -> stack)
// 		{
// 			save = head;
// 			final = head;
// 		}
// 		head = head -> next -> next;
// 	}
// 	return 0;
// }
// int find_elem_a(t_nvr *sta, int min, int big, int elem)
// {
// 	t_nvr *last;
// 	t_nvr *reg;
// 	int a;
// 	int size;

// 	reg = sta;
// 	size = ft_lstsize(sta);
// 	last = link_lst(&sta);
// 	a = 0;
// 	while (++a < size)
// 	{
// 		if (sta-> stack < elem && sta-> next -> stack > elem)
// 		{
// 			a = sta-> next -> stack;
// 			break ;
// 		}
// 		if (elem < min || elem > big)
// 		{
//  			a = min;
// 			break ;
// 		}
// 		sta = sta -> next;
// 	}
// 	d_link(&sta, last, reg);
// 	return (a);
// }

