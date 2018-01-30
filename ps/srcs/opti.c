/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:21:44 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/10 18:21:44 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_op	*ft_opti_last(t_op *algo)
{
	if (algo->next && !ft_strcmp("sb", algo->str) &&
		!ft_strcmp("sa", algo->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("ss")) == NULL)
			ft_error("Error");
		algo = algo->next;
		ft_remove(&algo, 1);
	}
	else
		algo = algo->next;
	return (algo);
}

t_op	*ft_opti_next_next_next(t_op *algo)
{
	if (algo->next && !ft_strcmp("rra", algo->str) &&
		!ft_strcmp("rrb", algo->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("rrr")) == NULL)
			ft_error("Error");
		algo = algo->next;
		ft_remove(&algo, 1);
	}
	else if (algo->next && !ft_strcmp("sa", algo->str) &&
		!ft_strcmp("sb", algo->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("ss")) == NULL)
			ft_error("Error");
		algo = algo->next;
		ft_remove(&algo, 1);
	}
	else
		algo = ft_opti_last(algo);
	return (algo);
}

t_op	*ft_opti_next_next(t_op *algo)
{
	if (algo->next && !ft_strcmp("rb", algo->str) &&
		!ft_strcmp("ra", algo->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("rr")) == NULL)
			ft_error("Error");
		algo = algo->next;
		ft_remove(&algo, 1);
	}
	else if (algo->next && !ft_strcmp("rrb", algo->str) &&
		!ft_strcmp("rra", algo->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("rrr")) == NULL)
			ft_error("Error");
		algo = algo->next;
		ft_remove(&algo, 1);
	}
	else
		algo = ft_opti_next_next_next(algo);
	return (algo);
}

t_op	*ft_opti_next(t_op *algo)
{
	if (algo->next && algo->next->next && !ft_strcmp("pb", algo->str)
		&& !ft_strcmp("rra", algo->next->str) &&
		!ft_strcmp("pa", algo->next->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("rra")) == NULL)
			ft_error("Error");
		free(algo->next->str);
		if ((algo->next->str = ft_strdup("sa")) == NULL)
			ft_error("Error");
		algo = algo->next->next;
		ft_remove(&algo, 1);
	}
	else if (algo->next && !ft_strcmp("ra", algo->str) &&
		!ft_strcmp("rb", algo->next->str))
	{
		free(algo->str);
		if ((algo->str = ft_strdup("rr")) == NULL)
			ft_error("Error");
		algo = algo->next;
		ft_remove(&algo, 1);
	}
	else
		algo = ft_opti_next_next(algo);
	return (algo);
}

void	ft_opti(t_op *algo)
{
	while (algo)
	{
		if (algo->next && !ft_strcmp("pa", algo->str) &&
			!ft_strcmp("pb", algo->next->str))
			ft_remove(&algo, 2);
		else if (algo->next && !ft_strcmp("pb", algo->str) &&
			!ft_strcmp("pa", algo->next->str))
			ft_remove(&algo, 2);
		else if (algo->next && algo->next->next && !ft_strcmp("pb", algo->str)
			&& !ft_strcmp("ra", algo->next->str) &&
			!ft_strcmp("pa", algo->next->next->str))
		{
			free(algo->str);
			if ((algo->str = ft_strdup("sa")) == NULL)
				ft_error("Error");
			free(algo->next->str);
			if ((algo->next->str = ft_strdup("ra")) == NULL)
				ft_error("Error");
			algo = algo->next->next;
			ft_remove(&algo, 1);
		}
		else
			algo = ft_opti_next(algo);
	}
}
