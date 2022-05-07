/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:10:52 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:18:21 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_data **stack)
{
	t_data	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	tmp->index = -1;
	tmp = *stack;
	ft_sort(&tmp);
}

void	ft_sort(t_data **stack)
{
	t_data	*tmp_buff;
	t_data	*tmp_count;
	int		cnt;
	int		i;

	tmp_buff = *stack;
	tmp_count = *stack;
	cnt = ft_lstsize(*stack);
	i = 0;
	while (cnt--)
	{
		while (tmp_count)
		{
			while (tmp_buff->index != -1)
				tmp_buff = tmp_buff->next;
			if ((tmp_buff->num > tmp_count->num) && (tmp_count->index == -1))
				tmp_buff = tmp_count;
			tmp_count = tmp_count->next;
		}
		tmp_buff->index = i++;
		tmp_buff = *stack;
		tmp_count = *stack;
	}
}

void	sequence_dop(t_data **stack, int s, int i, t_data **tmp)
{
	int	cnt_buff;

	cnt_buff = ft_lstsize(*stack);
	while (cnt_buff)
	{
		if (i < (*tmp)->num)
		{
			i = (*tmp)->num;
			s++;
		}
		if ((*tmp)->next == NULL)
			*tmp = *stack;
		else
			*tmp = (*tmp)->next;
		cnt_buff--;
	}
}

void	sequence(t_data **stack)
{
	t_data	*tmp;
	t_data	*buff;
	int		i;
	int		cnt_osnov;
	int		s;

	s = 1;
	tmp = *stack;
	buff = *stack;
	cnt_osnov = ft_lstsize(*stack);
	i = 0;
	while (cnt_osnov)
	{
		i = buff->num;
		sequence_dop(stack, s, i, &tmp);
		buff->seq = s;
		cnt_osnov--;
		i = 0;
		s = 1;
		buff = buff->next;
		tmp = buff;
	}
}
