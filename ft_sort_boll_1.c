/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_boll_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:31:26 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:18:55 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_data **a_stack)
{
	t_data	*tmp;
	int		a;

	a = 0;
	tmp = *a_stack;
	if (tmp->index != 0)
		return (1);
	while (tmp->next)
	{
		if (tmp->index != a)
			return (1);
		a++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_nulling_bull(t_data **a_stack)
{
	int		cnt;
	t_data	*buff;

	buff = *a_stack;
	cnt = ft_lstsize(*a_stack);
	while (cnt)
	{
		buff->boll = 0;
		buff = buff->next;
		cnt--;
	}
}

void	sort_boll_1_dop(t_data **a_stack, t_data **tmmp, int i)
{
	int		cnt;
	t_data	*tmp;

	tmp = *tmmp;
	cnt = ft_lstsize(*a_stack);
	tmp->boll = 1;
	while (cnt)
	{
		if (i < tmp->num)
		{
			i = tmp->num;
			tmp->boll = 1;
		}
		if (tmp->next == NULL)
			tmp = *a_stack;
		else
			tmp = tmp->next;
		cnt--;
	}
}

void	sort_boll_1(t_data **a_stack)
{
	t_data	*tmp;
	t_data	*buff_1;
	int		cnt;

	tmp = *a_stack;
	buff_1 = *a_stack;
	cnt = ft_lstsize(*a_stack);
	while (cnt)
	{
		if (buff_1->seq == tmp->seq)
		{
			if (tmp->num < buff_1->num)
				buff_1 = tmp;
		}
		if (buff_1->seq < tmp->seq)
			buff_1 = tmp;
		if (tmp->next == NULL)
			tmp = *a_stack;
		else
			tmp = tmp->next;
		cnt--;
	}
	ft_nulling_bull(a_stack);
	sort_boll_1_dop(a_stack, &buff_1, buff_1->num);
}
