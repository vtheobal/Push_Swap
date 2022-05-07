/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_three_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:36:21 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:32:37 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_data **a_stack, t_data **b_stack)
{
	int		a;

	a = ft_lstsize(*a_stack);
	ft_nulling_booling(a_stack);
	if (a == 3)
		ft_sort_three(a_stack);
	else if (a == 5)
		ft_sort_five(a_stack, b_stack);
	else
		sort_big(a_stack, b_stack);
}

void	ft_nulling_booling(t_data **a_stack)
{
	t_data	*tmp;

	tmp = *a_stack;
	while (tmp)
	{
		tmp->range = 0;
		tmp->rotate = 0;
		tmp = tmp->next;
	}
}

void	ft_sort_three(t_data **a_stack)
{
	int	one;
	int	two;
	int	three;

	one = (*a_stack)->index;
	two = (*a_stack)->next->index;
	three = (*a_stack)->next->next->index;
	if (one < two && two > three && one < three)
	{
		ft_rra(a_stack, 0);
		ft_sa(a_stack);
	}
	else if (one < two && two > three && one > three)
		ft_rra(a_stack, 0);
	else if (one > two && two < three && one < three)
		ft_sa(a_stack);
	else if (one > two && two < three && one > three)
		ft_ra(a_stack, 0);
	else if (one > two && two > three && one > three)
	{
		ft_sa(a_stack);
		ft_rra(a_stack, 0);
	}
	else
		return ;
}

void	ft_sort_five(t_data **a_stack, t_data **b_stack)
{
	int	cnt;

	cnt = 2;
	while (cnt)
	{
		if ((*a_stack)->index == 1 || (*a_stack)->index == 0)
		{
			ft_pb(a_stack, b_stack);
			cnt--;
		}
		else
			ft_ra(a_stack, 0);
	}
	ft_sort_three(a_stack);
	if ((*b_stack)->index < (*b_stack)->next->index)
		ft_sb(b_stack);
	ft_pa(a_stack, b_stack);
	ft_pa(a_stack, b_stack);
}
