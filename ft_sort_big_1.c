/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:46:11 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/02 17:45:45 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	midpoint(int a)
{
	if (a % 2)
		a = (a / 2) + 1;
	else
		a = a / 2;
	return (a);
}

void	ranging_dop(t_data **stack, t_data **tmp, int *i, int *a)
{
	if (ft_lstsize(*stack) % 2)
	{
		while (*i < *a)
		{
			(*tmp)->range = *i;
			(*tmp)->rotate = 1;
			*tmp = (*tmp)->next;
			(*i)++;
		}
		(*i)--;
	}
	else
	{
		while (*i < *a)
		{
			(*tmp)->range = *i;
			(*tmp)->rotate = 1;
			*tmp = (*tmp)->next;
			(*i)++;
		}
	}
}

void	ranging(t_data **stack)
{
	t_data	*tmp;
	int		i;
	int		a;

	i = 0;
	tmp = *stack;
	a = ft_lstsize(*stack);
	a = midpoint(a);
	ranging_dop(stack, &tmp, &i, &a);
	while (tmp)
	{
		tmp->range = i;
		tmp->rotate = 0;
		tmp = tmp->next;
		i--;
	}
}

t_info	*info_init(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->best_sum = 0;
	info->range_sum = 0;
	info->index_a = 0;
	info->rotate_bool_a = 0;
	info->rotate_bool_b = 0;
	info->index_b = 0;
	info->best_index_a = 0;
	info->best_index_b = 0;
	return (info);
}

void	sort_big(t_data **a_stack, t_data **b_stack)
{
	t_info	*info;
	int		cnt;
	int		a;

	a = 3;
	info = info_init();
	cnt = ft_lstsize(*a_stack);
	while (cnt)
	{
		if ((*a_stack)->boll == 1)
			ft_ra(a_stack, 0);
		else
			ft_pb(a_stack, b_stack);
		cnt--;
	}
	while (*b_stack)
	{
		ranging(a_stack);
		ranging(b_stack);
		best_way(a_stack, b_stack, info);
		osnova(a_stack, b_stack, info);
	}
	rotating(a_stack);
	free(info);
}
