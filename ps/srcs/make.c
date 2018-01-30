/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_makestr(char *str, int argc, char **argv)
{
	int		i;
	int		j;
	int		x;

	i = 1;
	x = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			str[x] = argv[i][j];
			j++;
			x++;
		}
		i++;
		str[x] = ' ';
		x++;
	}
	str[x] = 0;
}

void	ft_makelst(t_ps **a, t_ps **b, char **str)
{
	ft_list_free(a);
	ft_list_free(b);
	*a = ft_list(str);
	*b = NULL;
}

t_ps	*ft_list(char **str)
{
	int		i;
	t_ps	*new;
	t_ps	*previous;
	t_ps	*start;

	if ((start = (t_ps*)malloc(sizeof(t_ps))) == NULL)
		ft_error("Error");
	start->x = ft_atoi(str[0]);
	previous = start;
	i = 1;
	while (str[i])
	{
		if ((new = (t_ps*)malloc(sizeof(t_ps))) == NULL)
			ft_error("Error");
		new->x = ft_atoi(str[i]);
		new->previous = previous;
		previous->next = new;
		previous = new;
		i++;
	}
	start->previous = previous;
	previous->next = start;
	return (start);
}

void	ft_list_free(t_ps **lst)
{
	t_ps *next;

	if (*lst != NULL)
		(*lst)->previous->next = NULL;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
