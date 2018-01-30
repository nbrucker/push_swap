/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_looksup(t_ps *lst, int x)
{
	int i;

	if (lst == NULL)
		return (0);
	i = lst->previous->x;
	while (lst->x != i)
	{
		if (lst->x >= x)
			return (1);
		lst = lst->next;
	}
	if (lst->x >= x)
		return (1);
	return (0);
}

int		ft_lookinfsup(t_ps *lst, int x, int n)
{
	int i;

	i = lst->previous->x;
	while (lst->x != i)
	{
		if (lst->x < x && lst->x >= n)
			return (1);
		lst = lst->next;
	}
	if (lst->x < x && lst->x >= n)
		return (1);
	return (0);
}

int		ft_lookinf(t_ps *lst, int x)
{
	int i;

	i = lst->previous->x;
	while (lst->x != i)
	{
		if (lst->x < x)
			return (1);
		lst = lst->next;
	}
	if (lst->x < x)
		return (1);
	return (0);
}
