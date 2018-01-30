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

#include "libft.h"
#include "push_swap.h"

void	ft_add(char *str, t_op **algo)
{
	t_op *new;

	if ((new = (t_op*)malloc(sizeof(t_op))) == NULL)
		ft_error("Error");
	if ((new->str = ft_strdup(str)) == NULL)
		ft_error("Error");
	new->next = NULL;
	new->previous = NULL;
	if (*algo == NULL)
		*algo = new;
	else
	{
		while ((*algo)->next)
			*algo = (*algo)->next;
		(*algo)->next = new;
		new->previous = *algo;
	}
	while ((*algo)->previous)
		*algo = (*algo)->previous;
}

void	ft_push(t_ps **src, t_ps **dst, char c, t_op **algo)
{
	t_ps *lst;

	lst = *src;
	if (ft_len(*src) == 1)
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
	c == 'a' ? ft_add("pa", algo) : ft_add("pb", algo);
}

void	ft_swap(t_ps **lst, char c, t_op **algo)
{
	int tmp;

	tmp = (*lst)->x;
	(*lst)->x = (*lst)->next->x;
	(*lst)->next->x = tmp;
	if (c == 'a')
		ft_add("sa", algo);
	else if (c == 'b')
		ft_add("sb", algo);
}

void	ft_rotate(t_ps **lst, char c, t_op **algo)
{
	*lst = (*lst)->next;
	if (c == 'a')
		ft_add("ra", algo);
	else if (c == 'b')
		ft_add("rb", algo);
}

void	ft_reverse_rotate(t_ps **lst, char c, t_op **algo)
{
	*lst = (*lst)->previous;
	if (c == 'a')
		ft_add("rra", algo);
	else if (c == 'b')
		ft_add("rrb", algo);
}
