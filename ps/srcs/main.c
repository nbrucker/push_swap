/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ft_length(int argc, char **argv)
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
			j++;
			x++;
		}
		i++;
		x++;
	}
	return (x);
}

char	**ft_join(int argc, char **argv)
{
	char	*str;
	char	**split;

	if ((str = ft_strnew(ft_length(argc, argv))) == NULL)
		ft_error("Error");
	ft_makestr(str, argc, argv);
	if ((split = ft_strsplit(str, ' ')) == NULL)
		ft_error("Error");
	free(str);
	return (split);
}

void	ft_check_error(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_itoa(ft_atoi(str[i]));
		if (ft_strcmp(str[i], tmp) != 0)
			ft_error("Error");
		free(tmp);
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				ft_error("Error");
			j++;
		}
		i++;
	}
}

void	ft_free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	char	**str;

	if (argc < 2)
		return (0);
	str = ft_join(argc, argv);
	ft_check_error(str);
	ft_makelst(&a, &b, str);
	ft_sort(&a, &b, str);
	ft_list_free(&a);
	ft_list_free(&b);
	ft_free_str(str);
	return (0);
}
