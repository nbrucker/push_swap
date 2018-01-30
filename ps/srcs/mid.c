/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sup(t_ps *lst, int x)
{
	t_ps	*start;
	int		i;

	start = lst;
	i = 0;
	if (lst->x > x)
		i++;
	lst = lst->next;
	while (lst->x != start->x)
	{
		if (lst->x > x)
			i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_inf(t_ps *lst, int x)
{
	t_ps	*start;
	int		i;

	start = lst;
	i = 0;
	if (lst->x < x)
		i++;
	lst = lst->next;
	while (lst->x != start->x)
	{
		if (lst->x < x)
			i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_middle_value(t_ps *lst)
{
	t_ps	*start;
	int		inf;
	int		sup;
	int		x;

	start = lst;
	if (ft_len(lst) % 2 == 0)
		x = 1;
	else
		x = 0;
	inf = ft_inf(start, lst->x);
	sup = ft_sup(start, lst->x);
	if (inf == sup + x)
		return (lst->x);
	lst = lst->next;
	while (lst->x != start->x)
	{
		inf = ft_inf(start, lst->x);
		sup = ft_sup(start, lst->x);
		if (inf == sup + x)
			return (lst->x);
		lst = lst->next;
	}
	return (start->x);
}
