/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_pk
{
	int			x;
	struct s_pk	*next;
}				t_pk;

typedef struct	s_ps
{
	int			x;
	struct s_ps	*next;
	struct s_ps	*previous;
}				t_ps;

typedef	struct	s_op
{
	char		*str;
	struct s_op	*next;
	struct s_op	*previous;
}				t_op;

void			ft_swap(t_ps **lst, char c, t_op **algo);
void			ft_rotate(t_ps **lst, char c, t_op **algo);
void			ft_reverse_rotate(t_ps **lst, char c, t_op **algo);
void			ft_push(t_ps **src, t_ps **dst, char c, t_op **algo);
void			ft_sort(t_ps **a, t_ps **b, char **str);
void			ft_makelst(t_ps **a, t_ps **b, char **str);
t_ps			*ft_list(char **str);
void			ft_list_free(t_ps **lst);
int				ft_min(t_ps *lst);
int				ft_max(t_ps *lst);
int				ft_issort(t_ps *lst);
int				ft_len(t_ps *lst);
int				ft_index(t_ps *lst, int x);
void			ft_print_pile(t_ps *lst);
void			ft_print_algo(t_op *algo);
int				ft_issort(t_ps *lst);
void			ft_bubble_sort(t_ps **a, t_ps **b, t_op **algo, int max);
int				ft_atindex(t_ps *lst, int index);
void			ft_rotate_sort(t_ps **a, t_op **algo);
void			ft_quick_sort(t_ps **a, t_ps **b, t_op **algo);
void			ft_select_sort(t_ps **a, t_ps **b, t_op **algo, int max);
void			ft_qsort(t_ps **a, t_ps **b, t_op **algo, int len);
int				ft_next_max(t_ps *lst);
int				ft_next_min(t_ps *lst);
int				ft_algolen(t_op *algo);
int				ft_issortlen(t_ps *lst, int len);
int				ft_middle_value(t_ps *lst);
void			ft_addpkt(t_pk **pkt, int i);
void			ft_free_pkt(t_pk **pkt);
void			ft_rotate_sort_reverse(t_ps **b, t_op **algo);
int				ft_middle_value_len(t_ps *lst, int len);
int				ft_minlen(t_ps *lst, int len);
int				ft_looksup(t_ps *lst, int x);
int				ft_lookinfsup(t_ps *lst, int x, int n);
int				ft_lookinf(t_ps *lst, int x);
void			ft_call(t_ps **a, t_ps **b, t_op **algo, t_pk **pkt);
void			ft_rotateback(t_ps **a, t_op **algo, int i);
void			ft_rushb(t_ps **a, t_ps **b, t_op **algo, int len);
int				ft_return(t_ps **a, t_ps **b, t_op **algo, int len);
int				ft_selectsortb(t_ps **a, t_ps **b, t_op **algo);
void			ft_empty(t_ps **a, t_ps **b, t_op **algo, t_pk **pkt);
int				ft_selectsortb(t_ps **a, t_ps **b, t_op **algo);
void			ft_makestr(char *str, int argc, char **argv);
void			ft_opti(t_op *algo);
void			ft_remove(t_op **algo, int n);

#endif
