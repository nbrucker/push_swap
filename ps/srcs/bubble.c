/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_misplaced(t_ps *lst)
{
	t_ps	*start;

	start = lst;
	if ((ft_max(lst) == lst->x || ft_min(lst) == lst->x)
		&& lst->previous->x < lst->next->x)
		return (ft_index(start, lst->x));
	else if (ft_min(lst) != lst->x && ft_max(lst) != lst->x
		&& (lst->previous->x > lst->x || lst->next->x < lst->x))
		return (ft_index(start, lst->x));
	lst = lst->next;
	while (lst->x != start->x)
	{
		if ((ft_max(lst) == lst->x || ft_min(lst) == lst->x)
			&& lst->previous->x < lst->next->x)
			return (ft_index(start, lst->x));
		else if (ft_min(lst) != lst->x && ft_max(lst) != lst->x
			&& (lst->previous->x > lst->x || lst->next->x < lst->x))
			return (ft_index(start, lst->x));
		lst = lst->next;
	}
	return (-1);
}

int		ft_direction(t_ps *lst, int x)
{
	t_ps	*start;
	int		left;
	int		right;

	start = lst;
	lst = lst->next;
	right = 1;
	while (lst->x < lst->next->x || x == lst->next->x)
	{
		lst = lst->next;
		right++;
	}
	lst = start;
	lst = lst->previous->previous;
	left = 2;
	while (lst->x < lst->next->x || x == lst->next->x)
	{
		lst = lst->previous;
		left++;
	}
	if (left <= right)
		return (-1);
	return (1);
}

void	ft_rotate_sort(t_ps **a, t_op **algo)
{
	while (ft_issort(*a) == 0)
		ft_rotate(a, 'a', algo);
	while (ft_issort(*a) == 2)
		ft_reverse_rotate(a, 'a', algo);
}

void	ft_bubble_sort(t_ps **a, t_ps **b, t_op **algo, int max)
{
	int x;

	x = (*a)->x;
	(void)b;
	while (ft_issort(*a) == -1 && ft_algolen(*algo) <= max)
	{
		if ((*a)->x > (*a)->next->x && ft_index(*a, (*a)->next->x) != 0)
		{
			ft_swap(a, 'a', algo);
			if (x == (*a)->next->x)
				x = (*a)->x;
		}
		if (ft_issort(*a) == -1)
		{
			if (ft_direction(*a, x) == 1)
				while ((*a)->x < (*a)->next->x || x == (*a)->next->x)
					ft_rotate(a, 'a', algo);
			else
				while ((*a)->x < (*a)->next->x || x == (*a)->next->x)
					ft_reverse_rotate(a, 'a', algo);
		}
	}
	ft_rotate_sort(a, algo);
}
