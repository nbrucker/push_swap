/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_minlen(t_ps *lst, int len)
{
	int i;
	int min;

	min = lst->x;
	i = 0;
	while (i < len)
	{
		if (lst->x < min)
			min = lst->x;
		i++;
		lst = lst->next;
	}
	return (min);
}

int		ft_suplen(t_ps *lst, int x, int len)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (n < len)
	{
		if (lst->x > x)
			i++;
		lst = lst->next;
		n++;
	}
	return (i);
}

int		ft_inflen(t_ps *lst, int x, int len)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (n < len)
	{
		if (lst->x < x)
			i++;
		lst = lst->next;
		n++;
	}
	return (i);
}

int		ft_middle_value_len(t_ps *lst, int len)
{
	int		inf;
	int		sup;
	int		x;
	t_ps	*start;
	int		i;

	start = lst;
	if (len % 2 == 0)
		x = 1;
	else
		x = 0;
	i = 0;
	while (i < len)
	{
		inf = ft_inflen(start, lst->x, len);
		sup = ft_suplen(start, lst->x, len);
		if (inf == sup + x)
			return (lst->x);
		lst = lst->next;
		i++;
	}
	return (start->x);
}
