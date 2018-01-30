/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

char	*ft_read(void)
{
	char	*str;
	char	*tmp;
	char	buf[2];
	int		ret;

	if ((str = ft_strnew(1)) == NULL)
		ft_error("Error");
	while ((ret = read(0, buf, sizeof(char))) > 0)
	{
		buf[1] = 0;
		if ((tmp = ft_strdup(str)) == NULL)
			ft_error("Error");
		free(str);
		if ((str = ft_strjoin(tmp, buf)) == NULL)
			ft_error("Error");
		free(tmp);
	}
	if (ret == -1)
		ft_error("Error");
	return (str);
}

void	ft_exe_next(char *str, int i, t_ps **a, t_ps **b)
{
	if (ft_strncmp(str + i, "pa\n", 3) == 0)
		ft_push(b, a);
	else if (ft_strncmp(str + i, "pb\n", 3) == 0)
		ft_push(a, b);
	else if (ft_strncmp(str + i, "ra\n", 3) == 0)
		ft_rotate(a);
	else if (ft_strncmp(str + i, "rb\n", 3) == 0)
		ft_rotate(b);
	else if (ft_strncmp(str + i, "rr\n", 3) == 0)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (ft_strncmp(str + i, "rra\n", 4) == 0)
		ft_reverse_rotate(a);
	else if (ft_strncmp(str + i, "rrb\n", 4) == 0)
		ft_reverse_rotate(b);
	else if (ft_strncmp(str + i, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else
		ft_error("Error");
}

void	ft_exe(t_ps **a, t_ps **b)
{
	char	*str;
	int		i;

	if ((str = ft_read()) == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, "sa\n", 3) == 0)
			ft_swap(a);
		else if (ft_strncmp(str + i, "sb\n", 3) == 0)
			ft_swap(b);
		else if (ft_strncmp(str + i, "ss\n", 3) == 0)
		{
			ft_swap(a);
			ft_swap(b);
		}
		else
			ft_exe_next(str, i, a, b);
		if (ft_char_index(str + i, '\n') == -1)
			ft_error("Error");
		i += ft_char_index(str + i, '\n') + 1;
	}
	free(str);
}
