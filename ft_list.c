/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:30:49 by vtheobal          #+#    #+#             */
/*   Updated: 2021/10/03 16:18:27 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_data *lst)
{
	int	cont;

	cont = 0;
	while (lst != NULL)
	{
		cont++;
		lst = lst->next;
	}
	return (cont);
}

t_data	*ft_lstlast(t_data *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*data;

	data = ft_lstlast(*lst);
	if (data)
		data->next = new;
	else
		*lst = new;
}

void	ft_lstadd_front(t_data **lst, t_data *new)
{
	new->next = *lst;
	*lst = new;
}

t_data	*ft_lstnew(int num)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}
