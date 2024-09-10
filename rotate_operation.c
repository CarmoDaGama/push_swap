/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:58:44 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 15:58:45 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_item;
	int		len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_item = find_last_item(*stack);
	last_item->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_item->next->prev = last_item;
	last_item->next->next = NULL;
}	

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_putstr("ra\n");
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_putstr("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_putstr("rr\n");
}
