/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_remove(t_op **algo, int n)
{
	int		i;
	t_op	*el;

	el = *algo;
	i = 0;
	while (i < n)
	{
		free(el->str);
		el->str = ft_strnew(1);
		if (el->str == NULL)
			ft_error("Error");
		el = el->next;
		i++;
	}
	while ((*algo)->previous)
		*algo = (*algo)->previous;
}

void	ft_print_algo(t_op *algo)
{
	while (algo)
	{
		if (algo->str && ft_strlen(algo->str) != 0)
			ft_putendl(algo->str);
		algo = algo->next;
	}
}
