/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_dop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:23:37 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/02 18:24:59 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_check(char *buf, t_data **a_stack, t_data **b_stack)
{
	if (*buf == 'r')
	{
		buf++;
		if (*buf == 'a')
			ra_bonus(a_stack);
		if (*buf == 'b')
			rb_bonus(b_stack);
		if (*buf == 'r')
		{
			buf++;
			if (*buf == 'a')
				rra_bonus(a_stack);
			else if (*buf == 'b')
				rrb_bonus(b_stack);
			else if (*buf == 'r')
				rrr_bonus(a_stack, b_stack);
			else
				rr_bonus(a_stack, b_stack);
		}
		buf[0] = '\0';
		buf[1] = '\0';
		buf[2] = '\0';
		buf[3] = '\0';
		buf[4] = '\0';
	}
}

void	s_check(char *buf, t_data **a_stack, t_data **b_stack)
{
	if (*buf == 's')
	{
		buf++;
		if (*buf == 'a')
			sa_bonus(a_stack);
		else
			sb_bonus(b_stack);
	}
}

void	p_check(char *buf, t_data **a_stack, t_data **b_stack)
{
	if (*buf == 'p')
	{
		buf++;
		if (*buf == 'a')
			pa_bonus(a_stack, b_stack);
		else
			pb_bonus(a_stack, b_stack);
	}
}

void	parsing(char *buf, t_data **a_stack, t_data **b_stack)
{
	while (*buf != '\0')
	{
		r_check(buf, a_stack, b_stack);
		s_check(buf, a_stack, b_stack);
		p_check(buf, a_stack, b_stack);
		buf++;
	}
}

void	reader(t_data **a_stack, t_data **b_stack)
{
	int		ret;
	char	ch;
	char	buf[5];
	int		i;

	ret = 0;
	i = 0;
	ch = '\0';
	ft_buf_null(buf);
	ret = read(0, &ch, 1);
	while (ret && ch != '\0')
	{
		buf[i++] = ch;
		if (ch == '\n')
		{
			parsing(buf, a_stack, b_stack);
			i = 0;
			ft_buf_null(buf);
		}
		ret = read(0, &ch, 1);
	}
}
