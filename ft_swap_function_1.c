/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_function_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:37:11 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:19:09 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_data **a, t_data **b)
{
	t_data	*tmp;

	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	ft_sa(t_data **a_stack)
{
	if (!a_stack)
		return ;
	if ((*a_stack)->next)
		ft_swap(a_stack, &(*a_stack)->next);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_data **b_stack)
{
	if (!b_stack)
		return ;
	if ((*b_stack)->next)
		ft_swap(b_stack, &(*b_stack)->next);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_data **a_stack, t_data **b_stack)
{
	ft_sa(a_stack);
	ft_sb(b_stack);
}

void	ft_pa(t_data **a_stack, t_data **b_stack)
{
	t_data	*tmp;

	tmp = *b_stack;
	*b_stack = tmp->next;
	tmp->next = *a_stack;
	*a_stack = tmp;
	ft_putstr_fd("pa\n", 1);
}
