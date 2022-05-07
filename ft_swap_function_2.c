/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_function_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:37:29 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:19:16 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_data **a_stack, t_data **b_stack)
{
	t_data	*tmp;

	tmp = *a_stack;
	*a_stack = tmp->next;
	tmp->next = *b_stack;
	*b_stack = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	ft_rev_rotate(t_data **stack)
{
	t_data	*tmp;
	t_data	*pmp;

	tmp = *stack;
	pmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->next->next != NULL)
			pmp = pmp->next;
		tmp = tmp->next;
	}
	pmp->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_rotate(t_data **stack)
{
	t_data	*tmp;
	t_data	*pmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	pmp = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next = NULL;
	*stack = pmp;
}

void	ft_ra(t_data **a_stack, int a)
{
	if (!a_stack)
		return ;
	ft_rotate(a_stack);
	if (a == 0)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_data **b_stack, int a)
{
	if (!b_stack)
		return ;
	ft_rotate(b_stack);
	if (a == 0)
		ft_putstr_fd("rb\n", 1);
}
