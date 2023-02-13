/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_function_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:38:46 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:19:28 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_data **a_stack, t_data **b_stack, int a)
{
	ft_putstr_fd("rr\n", 1);
	ft_ra(a_stack, a);
	ft_rb(b_stack, a);
}

void	ft_rra(t_data **a_stack, int a)
{
	if (!a_stack)
		return ;
	ft_rev_rotate(a_stack);
	if (a == 0)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_data **b_stack, int a)
{
	if (!b_stack)
		return ;
	ft_rev_rotate(b_stack);
	if (a == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_data **a_stack, t_data **b_stack, int a)
{
	ft_putstr_fd("rrr\n", 1);
	ft_rra(a_stack, a);
	ft_rrb(b_stack, a);
}

void	parser(t_data **a_stack, char *argv)
{
	char	**buf;
	int		i;
	int		dup;
	t_data	*tmp;

	i = 0;
	buf = ft_split(argv, ' ');
	while (buf[i] != NULL)
	{
		ft_isdigit(buf[i]);
		ft_lstadd_back(a_stack, ft_lstnew(ft_atoi(buf[i])));
		dup = ft_atoi(buf[i]);
		free(buf[i]);
		i++;
	}
	free(buf);
	tmp = *a_stack;
	while (tmp->next)
	{
		if (dup == tmp->num)
			check_dup(dup, 1);
		tmp = tmp->next;
	}
}
