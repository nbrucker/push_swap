/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issort_reverse(t_ps *lst)
{
	int		max;
	t_ps	*start;

	start = lst;
	max = ft_max(lst);
	while (lst->x != max)
		lst = lst->next;
	while (lst->next->x != max)
	{
		if (lst->x < lst->next->x)
			return (-1);
		lst = lst->next;
	}
	lst = start;
	if (ft_index(lst, max) == 0)
		return (1);
	else if (ft_index(lst, max) <= ft_len(lst) - ft_index(lst, max))
		return (0);
	return (2);
}

void	ft_rotate_sort_reverse(t_ps **b, t_op **algo)
{
	while (ft_issort_reverse(*b) == 0)
		ft_rotate(b, 'b', algo);
	while (ft_issort_reverse(*b) == 2)
		ft_reverse_rotate(b, 'b', algo);
}
