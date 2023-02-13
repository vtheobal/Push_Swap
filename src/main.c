/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:41:06 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:21:23 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (!sort_check(&a_stack))
			exit(0);
		sequence(&a_stack);
		sort_boll_1(&a_stack);
		ft_algo(&a_stack, &b_stack);
	}
	return (0);
}
