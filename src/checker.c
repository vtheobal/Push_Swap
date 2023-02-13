/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:17:16 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:33:28 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_buf_null(char *buf)
{
	buf[0] = '\0';
	buf[1] = '\0';
	buf[2] = '\0';
	buf[3] = '\0';
	buf[4] = '\0';
}

int	main(int argc, char **argv)
{
	t_data	*a_stack;
	t_data	*b_stack;
	int		i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			parser(&a_stack, argv[i]);
			i++;
		}
		indexing(&a_stack);
		reader(&a_stack, &b_stack);
		if (!sort_check(&a_stack))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
