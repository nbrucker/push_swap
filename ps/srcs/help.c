/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call(t_ps **a, t_ps **b, t_op **algo, t_pk **pkt)
{
	t_pk *start;

	ft_empty(a, b, algo, pkt);
	start = *pkt;
	while (*pkt)
	{
		ft_qsort(a, b, algo, (*pkt)->x);
		*pkt = (*pkt)->next;
	}
	ft_free_pkt(&start);
}

void	ft_rotateback(t_ps **a, t_op **algo, int i)
{
	int x;

	x = 0;
	while (x < i)
	{
		ft_reverse_rotate(a, 'a', algo);
		x++;
	}
}

void	ft_rushb(t_ps **a, t_ps **b, t_op **algo, int len)
{
	t_pk	*pkt;
	int		i;

	pkt = NULL;
	i = 0;
	while (i < len)
	{
		ft_push(a, b, 'b', algo);
		i++;
	}
	ft_call(a, b, algo, &pkt);
}

int		ft_return(t_ps **a, t_ps **b, t_op **algo, int len)
{
	if (ft_issort(*a) != -1 || len == 0)
		return (1);
	if (ft_index(*a, ft_minlen(*a, len)) == 0)
	{
		ft_rotate(a, 'a', algo);
		ft_qsort(a, b, algo, len - 1);
		return (1);
	}
	if (len < 25)
	{
		ft_rushb(a, b, algo, len);
		return (1);
	}
	return (0);
}
