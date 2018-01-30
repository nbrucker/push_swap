/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_issort(t_ps *lst)
{
	int x;

	x = lst->x;
	while (lst->next->x != x)
	{
		if (lst->x > lst->next->x)
			return (-1);
		lst = lst->next;
	}
	return (1);
}

void	ft_push(t_ps **src, t_ps **dst)
{
	t_ps *lst;

	if ((lst = *src) == NULL)
		return ;
	if (lst->x == lst->next->x)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->previous = lst->previous;
		lst->previous->next = *src;
	}
	if (*dst == NULL)
	{
		lst->next = lst;
		lst->previous = lst;
	}
	else
	{
		lst->next = *dst;
		lst->previous = (*dst)->previous;
		lst->next->previous = lst;
		lst->previous->next = lst;
	}
	*dst = lst;
}

void	ft_swap(t_ps **lst)
{
	int tmp;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->x;
	(*lst)->x = (*lst)->next->x;
	(*lst)->next->x = tmp;
}

void	ft_rotate(t_ps **lst)
{
	if (*lst == NULL)
		return ;
	*lst = (*lst)->next;
}

void	ft_reverse_rotate(t_ps **lst)
{
	if (*lst == NULL)
		return ;
	*lst = (*lst)->previous;
}
