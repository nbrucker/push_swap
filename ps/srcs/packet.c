/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_addpkt(t_pk **pkt, int i)
{
	t_pk *new;

	if ((new = (t_pk*)malloc(sizeof(t_pk))) == NULL)
		ft_error("Error");
	new->x = i;
	new->next = *pkt;
	*pkt = new;
}

void	ft_free_pkt(t_pk **pkt)
{
	t_pk *next;

	if (*pkt == NULL)
		return ;
	while (*pkt)
	{
		next = (*pkt)->next;
		free(*pkt);
		*pkt = next;
	}
	*pkt = NULL;
}
