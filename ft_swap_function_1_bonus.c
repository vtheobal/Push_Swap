/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_function_1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:37:11 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/02 17:51:09 by vtheobal         ###   ########.fr       */
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

void	sa_bonus(t_data **a_stack)
{
	if (!a_stack)
		return ;
	if ((*a_stack)->next)
		ft_swap(a_stack, &(*a_stack)->next);
}

void	sb_bonus(t_data **b_stack)
{
	if (!b_stack)
		return ;
	if ((*b_stack)->next)
		ft_swap(b_stack, &(*b_stack)->next);
}

void	ss_bonus(t_data **a_stack, t_data **b_stack)
{
	sa_bonus(a_stack);
	sb_bonus(b_stack);
}

void	pa_bonus(t_data **a_stack, t_data **b_stack)
{
	t_data	*tmp;

	tmp = *b_stack;
	*b_stack = tmp->next;
	tmp->next = *a_stack;
	*a_stack = tmp;
}
