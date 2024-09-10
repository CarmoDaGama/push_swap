/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:00:46 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 16:00:48 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack	**a, bool checker)
{
	swap(a);
	if (!checker)
		ft_putstr("sa\n");
}

void	sb(t_stack **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_putstr("ss\n");
}
