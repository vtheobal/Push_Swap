/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:06:50 by wroyal            #+#    #+#             */
/*   Updated: 2021/10/03 16:42:26 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_data
{
	int				num;
	int				index;
	int				seq;
	bool			boll;
	int				range;
	bool			rotate;
	struct s_data	*next;
}				t_data;

typedef struct s_info
{
	t_data		*buff;
	int			best_sum;
	int			range_sum;
	int			index_a;
	int			rotate_bool_a;
	int			rotate_bool_b;
	int			index_b;
	int			best_index_a;
	int			best_index_b;
}				t_info;

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
t_data	*ft_lstlast(t_data *lst);
void	ft_lstadd_back(t_data **lst, t_data *new);
void	ft_lstadd_front(t_data **lst, t_data *new);
t_data	*ft_lstnew(int num);
void	ft_swap(t_data **a, t_data **b);
int		ft_lstsize(t_data *lst);
void	ft_swap(t_data **a, t_data **b);
void	ft_rev_rotate(t_data **stack);
void	ft_rotate(t_data **stack);
void	ft_sa(t_data **a_stack);
void	ft_sb(t_data **b_stack);
void	ft_ss(t_data **a_stack, t_data **b_stack);
void	ft_pa(t_data **a_stack, t_data **b_stack);
void	ft_pb(t_data **a_stack, t_data **b_stack);
void	ft_ra(t_data **a_stack, int a);
void	ft_rb(t_data **b_stack, int a);
void	ft_rr(t_data **a_stack, t_data **b_stack, int a);
void	ft_rra(t_data **a_stack, int a);
void	ft_rrb(t_data **b_stack, int a);
void	ft_rrr(t_data **a_stack, t_data **b_stack, int a);
void	sa_bonus(t_data **a_stack);
void	sb_bonus(t_data **b_stack);
void	ss_bonus(t_data **a_stack, t_data **b_stack);
void	pa_bonus(t_data **a_stack, t_data **b_stack);
void	pb_bonus(t_data **a_stack, t_data **b_stack);
void	ra_bonus(t_data **a_stack);
void	rb_bonus(t_data **b_stack);
void	rr_bonus(t_data **a_stack, t_data **b_stack);
void	rra_bonus(t_data **a_stack);
void	rrb_bonus(t_data **b_stack);
void	rrr_bonus(t_data **a_stack, t_data **b_stack);
void	r_check(char *buf, t_data **a_stack, t_data **b_stack);
void	s_check(char *buf, t_data **a_stack, t_data **b_stack);
void	p_check(char *buf, t_data **a_stack, t_data **b_stack);
void	parsing(char *buf, t_data **a_stack, t_data **b_stack);
void	reader(t_data **a_stack, t_data **b_stack);
void	ft_buf_null(char *buf);
void	parser(t_data **a_stack, char *argv);
void	indexing(t_data **stack);
void	ft_sort(t_data **stack);
void	sequence(t_data **stack);
int		sort_check(t_data **a_stack);
void	ft_nulling_bull(t_data **a_stack);
void	sort_boll_1_dop(t_data **a_stack, t_data **tmmp, int i);
void	sort_boll_1(t_data **a_stack);
void	ft_algo(t_data **a_stack, t_data **b_stack);
void	ft_nulling_booling(t_data **a_stack);
void	sort_big(t_data **a_stack, t_data **b_stack);
void	ft_sort_three(t_data **a_stack);
void	ft_sort_five(t_data **a_stack, t_data **b_stack);
void	sort_osnov(t_data **a_stack, t_data **b_stack);
int		midpoint(int a);
void	ranging(t_data **stack);
t_info	*info_init(void);
void	rotating(t_data **a_stack);
void	osnova(t_data **a_stack, t_data **b_stack, t_info *info);
void	best_way(t_data **a_stack, t_data **b_stack, t_info *info);
void	find_next(t_data **a_stack, t_data **b_stack, t_info *info);
void	find_uzel(t_data **a_stack, t_data **b_stack, t_info *info);
void	rotating(t_data **a_stack);
int		ft_isdigit(char	*c);
void	check_dup(int dup, int a);

#endif
