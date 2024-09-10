/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:57:08 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 15:57:10 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*item_to_push;

	if (NULL == *src)
		return ;
	item_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	item_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = item_to_push;
		item_to_push->next = NULL;
	}
	else
	{
		item_to_push->next = *dest;
		item_to_push->next->prev = item_to_push;
		*dest = item_to_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_putstr("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		ft_putstr("pb\n");
}
