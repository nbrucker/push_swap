/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_min(t_ps *lst)
{
	int x;
	int min;

	x = lst->x;
	min = x;
	lst = lst->next;
	while (lst->x != x)
	{
		if (lst->x < min)
			min = lst->x;
		lst = lst->next;
	}
	return (min);
}

int		ft_max(t_ps *lst)
{
	int x;
	int max;

	x = lst->x;
	max = x;
	lst = lst->next;
	while (lst->x != x)
	{
		if (lst->x > max)
			max = lst->x;
		lst = lst->next;
	}
	return (max);
}

int		ft_next_min(t_ps *lst)
{
	int min;
	int x;
	int start;

	x = ft_min(lst);
	start = lst->x;
	min = lst->x;
	lst = lst->next;
	while (lst->x != start)
	{
		if ((lst->x < min && lst->x != x) || min == x)
			min = lst->x;
		lst = lst->next;
	}
	return (min);
}

int		ft_next_max(t_ps *lst)
{
	int max;
	int x;
	int start;

	x = ft_max(lst);
	start = lst->x;
	max = lst->x;
	lst = lst->next;
	while (lst->x != start)
	{
		if ((lst->x > max && lst->x != x) || max == x)
			max = lst->x;
		lst = lst->next;
	}
	return (max);
}
