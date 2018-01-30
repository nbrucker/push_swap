/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_ps
{
	int			x;
	int			index;
	struct s_ps	*next;
	struct s_ps	*previous;
}				t_ps;

void			ft_exe(t_ps **a, t_ps **b);
int				ft_issort(t_ps *lst);
void			ft_reverse_rotate(t_ps **lst);
void			ft_rotate(t_ps **lst);
void			ft_push(t_ps **src, t_ps **dst);
void			ft_swap(t_ps **lst);
void			ft_makestr(char *str, int argc, char **argv);
t_ps			*ft_list(char **str);
void			ft_list_free(t_ps **lst);

#endif
