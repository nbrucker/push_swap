/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_sort(t_ps **a, t_ps **b, t_op **algo, int max)
{
	while (ft_issort(*a) != 1 && ft_algolen(*algo) <= max)
	{
		if (ft_index(*a, ft_min(*a)) == 1 && ft_index(*a, ft_next_min(*a)) == 0)
			ft_swap(a, 'a', algo);
		else if (ft_index(*a, ft_min(*a)) == 0)
			ft_push(a, b, 'b', algo);
		else if (ft_index(*a, ft_min(*a)) <= ft_len(*a) -
			ft_index(*a, ft_min(*a)))
			ft_rotate(a, 'a', algo);
		else
			ft_reverse_rotate(a, 'a', algo);
	}
	while (*b)
		ft_push(b, a, 'a', algo);
	ft_rotate_sort(a, algo);
}
