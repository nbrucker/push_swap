/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		ft_issort(t_ps *lst)
{
	int		min;
	t_ps	*start;

	start = lst;
	min = ft_min(lst);
	while (lst->x != min)
		lst = lst->next;
	while (lst->next->x != min)
	{
		if (lst->x > lst->next->x)
			return (-1);
		lst = lst->next;
	}
	lst = start;
	if (ft_index(lst, min) == 0)
		return (1);
	else if (ft_index(lst, min) <= ft_len(lst) - ft_index(lst, min))
		return (0);
	return (2);
}

int		ft_issortlen(t_ps *lst, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (lst->x > lst->next->x)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

int		ft_algolen(t_op *algo)
{
	int i;

	i = 0;
	while (algo)
	{
		if (algo->str && ft_strlen(algo->str) != 0)
			i++;
		algo = algo->next;
	}
	return (i);
}

void	ft_free_algo(t_op *algo)
{
	t_op *next;

	if (algo == NULL)
		return ;
	while (algo)
	{
		next = algo->next;
		free(algo->str);
		free(algo);
		algo = next;
	}
}

void	ft_sort(t_ps **a, t_ps **b, char **str)
{
	t_op	*select;
	t_op	*bubble;
	t_op	*quick;

	select = NULL;
	bubble = NULL;
	quick = NULL;
	ft_quick_sort(a, b, &quick);
	ft_opti(quick);
	ft_makelst(a, b, str);
	ft_select_sort(a, b, &select, ft_algolen(quick));
	ft_opti(select);
	ft_makelst(a, b, str);
	ft_bubble_sort(a, b, &bubble, ft_algolen(quick));
	ft_opti(bubble);
	if (ft_algolen(quick) < ft_algolen(select) &&
		ft_algolen(quick) < ft_algolen(bubble))
		ft_print_algo(quick);
	else if (ft_algolen(select) < ft_algolen(bubble))
		ft_print_algo(select);
	else
		ft_print_algo(bubble);
	ft_free_algo(quick);
	ft_free_algo(select);
	ft_free_algo(bubble);
}
