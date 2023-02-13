/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_function_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:19:37 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:19:38 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char	*c)
{
	int		a;

	if (*c == '-' && c[1] == '\0')
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	while (*c != '\0')
	{
		a = *c;
		if ((a < 48 || a > 57) && a != 45)
		{
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		c++;
	}
	return (1);
}

void	check_dup(int dup, int a)
{
	(void)dup;
	if (a == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
}
