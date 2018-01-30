/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lookformin(t_ps **a, t_ps **b, t_op **algo)
{
	if (ft_index(*b, ft_min(*b)) == 1 && ft_index(*b, ft_next_min(*b)) == 0)
	{
		ft_push(b, a, 'a', algo);
		ft_push(b, a, 'a', algo);
		ft_rotate(a, 'a', algo);
		ft_rotate(a, 'a', algo);
		return (1);
	}
	else if (ft_index(*b, ft_min(*b)) <= ft_len(*b) -
		ft_index(*b, ft_min(*b)) && ft_index(*b, ft_min(*b))
		<= ft_index(*b, ft_max(*b)) && ft_index(*b, ft_min(*b))
		<= ft_len(*b) - ft_index(*b, ft_max(*b)))
	{
		ft_rotate(b, 'b', algo);
		return (1);
	}
	else if (ft_len(*b) - ft_index(*b, ft_min(*b)) <=
		ft_index(*b, ft_max(*b)) && ft_len(*b) -
		ft_index(*b, ft_min(*b)) <= ft_len(*b) -
		ft_index(*b, ft_max(*b)))
	{
		ft_reverse_rotate(b, 'b', algo);
		return (1);
	}
	return (0);
}

void	ft_push_incr(t_ps **a, t_ps **b, t_op **algo, int *x)
{
	ft_push(b, a, 'a', algo);
	*x += 1;
}

void	ft_push_rotate(t_ps **a, t_ps **b, t_op **algo)
{
	ft_push(b, a, 'a', algo);
	ft_rotate(a, 'a', algo);
}

int		ft_selectsortb(t_ps **a, t_ps **b, t_op **algo)
{
	int x;

	x = 0;
	while (*b)
	{
		if (ft_index(*b, ft_max(*b)) == 1 &&
			ft_index(*b, ft_next_max(*b)) == 0)
			ft_swap(b, 'b', algo);
		else if (ft_index(*b, ft_max(*b)) == 0)
			ft_push_incr(a, b, algo, &x);
		else if (ft_index(*b, ft_min(*b)) == 0)
			ft_push_rotate(a, b, algo);
		else if (ft_lookformin(a, b, algo) == 1)
			continue ;
		else if (ft_index(*b, ft_max(*b)) <= ft_len(*b) -
			ft_index(*b, ft_max(*b)))
			ft_rotate(b, 'b', algo);
		else
			ft_reverse_rotate(b, 'b', algo);
	}
	return (x);
}
