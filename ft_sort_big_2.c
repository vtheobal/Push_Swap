/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:29:49 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:18:51 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_way(t_data **a_stack, t_data **b_stack, t_info *info)
{
	t_data	*a;
	t_data	*b;

	a = *a_stack;
	b = *b_stack;
	info->best_sum = 21000000;
	while (b)
	{
		find_next(&a, &b, info);
		if (info->range_sum < info->best_sum)
		{
			info->best_sum = info->range_sum;
			info->best_index_a = info->index_a;
			info->best_index_b = info->index_b;
		}
		b = b->next;
	}
	find_uzel(a_stack, b_stack, info);
}

void	osnova(t_data **a_stack, t_data **b_stack, t_info *info)
{
	while ((*a_stack)->index != info->best_index_a && (*b_stack)->index != \
	info->best_index_b && info->rotate_bool_a == 0 && info->rotate_bool_b == 0)
		ft_rrr(a_stack, b_stack, 1);
	while ((*a_stack)->index != info->best_index_a && (*b_stack)->index != \
	info->best_index_b && info->rotate_bool_a == 1 && info->rotate_bool_b == 1)
		ft_rr(a_stack, b_stack, 1);
	while ((*a_stack)->index != info->best_index_a)
	{
		if (info->rotate_bool_a == 0)
			ft_rra(a_stack, 0);
		if (info->rotate_bool_a == 1)
			ft_ra(a_stack, 0);
	}
	while ((*b_stack)->index != info->best_index_b)
	{
		if (info->rotate_bool_b == 0)
			ft_rrb(b_stack, 0);
		if (info->rotate_bool_b == 1)
			ft_rb(b_stack, 0);
	}
	ft_pa(a_stack, b_stack);
}

void	find_next(t_data **a_stack, t_data **b_stack, t_info *info)
{
	t_data	*tmp;

	tmp = *a_stack;
	info->index_b = (*b_stack)->index;
	info->index_a = 2147483647;
	while (tmp)
	{
		if (info->index_b < tmp->index && info->index_a > tmp->index)
		{
			info->index_a = tmp->index;
			info->range_sum = (*b_stack)->range + tmp->range;
		}
		tmp = tmp->next;
	}
}

void	find_uzel(t_data **a_stack, t_data **b_stack, t_info *info)
{
	t_data	*a;
	t_data	*b;

	a = *a_stack;
	b = *b_stack;
	while (a->index != info->best_index_a)
	{
		a = a->next;
	}
	info->rotate_bool_a = a->rotate;
	while (b->index != info->best_index_b)
	{
		b = b->next;
	}
	info->rotate_bool_b = b->rotate;
}

void	rotating(t_data **a_stack)
{
	t_data	*tmp;

	tmp = *a_stack;
	ranging(a_stack);
	while (tmp->index != 0)
		tmp = tmp->next;
	while ((*a_stack)->index != 0)
	{
		if (tmp->rotate == 1)
			ft_ra(a_stack, 0);
		if (tmp->rotate == 0)
			ft_rra(a_stack, 0);
	}
}
