/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_len(t_ps *lst)
{
	int x;
	int i;

	if (lst == NULL)
		return (0);
	x = lst->x;
	lst = lst->next;
	i = 1;
	while (lst->x != x)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_index(t_ps *lst, int x)
{
	int i;

	i = 0;
	while (lst->x != x)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
