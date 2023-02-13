/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_function_3_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:38:46 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:19:20 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr_bonus(t_data **a_stack, t_data **b_stack)
{
	ra_bonus(a_stack);
	rb_bonus(b_stack);
}

void	rra_bonus(t_data **a_stack)
{
	if (!a_stack)
		return ;
	ft_rev_rotate(a_stack);
}

void	rrb_bonus(t_data **b_stack)
{
	if (!b_stack)
		return ;
	ft_rev_rotate(b_stack);
}

void	rrr_bonus(t_data **a_stack, t_data **b_stack)
{
	rra_bonus(a_stack);
	rrb_bonus(b_stack);
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
