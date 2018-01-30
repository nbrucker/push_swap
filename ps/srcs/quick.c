/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_empty(t_ps **a, t_ps **b, t_op **algo, t_pk **pkt)
{
	int mid;
	int i;

	while (ft_len(*b) > 25)
	{
		mid = ft_middle_value(*b);
		i = 0;
		while (ft_looksup(*b, mid) == 1)
		{
			if ((*b)->x >= mid)
			{
				ft_push(b, a, 'a', algo);
				i++;
			}
			else
				ft_rotate(b, 'b', algo);
		}
		ft_addpkt(pkt, i);
	}
	ft_rotate_sort_reverse(b, algo);
	ft_addpkt(pkt, ft_selectsortb(a, b, algo));
}

void	ft_qsort(t_ps **a, t_ps **b, t_op **algo, int len)
{
	t_pk	*pkt;
	int		i;
	int		mid;
	int		min;

	pkt = NULL;
	if (ft_return(a, b, algo, len) == 1)
		return ;
	mid = ft_middle_value_len(*a, len);
	min = ft_minlen(*a, len);
	i = 0;
	while (ft_lookinfsup(*a, mid, min) == 1)
	{
		if ((*a)->x < mid)
			ft_push(a, b, 'b', algo);
		else
		{
			ft_rotate(a, 'a', algo);
			i++;
		}
	}
	ft_rotateback(a, algo, i);
	i = len - ft_len(*b);
	ft_call(a, b, algo, &pkt);
	ft_qsort(a, b, algo, i);
}

void	ft_quick_sort(t_ps **a, t_ps **b, t_op **algo)
{
	int		mid;
	t_pk	*pkt;
	int		i;

	pkt = NULL;
	ft_rotate_sort(a, algo);
	if (ft_issort(*a) == 1)
		return ;
	mid = ft_middle_value(*a);
	while (ft_lookinf(*a, mid) == 1)
	{
		if ((*a)->x < mid)
			ft_push(a, b, 'b', algo);
		else
			ft_rotate(a, 'a', algo);
	}
	i = ft_len(*a);
	ft_call(a, b, algo, &pkt);
	ft_qsort(a, b, algo, i);
	ft_rotate_sort(a, algo);
}
