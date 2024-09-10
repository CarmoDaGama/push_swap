/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:00:09 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 16:08:28 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_item(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_item(t_stack **stack, int nbr)
{
	t_stack	*item;
	t_stack	*last_item;

	if (NULL == stack)
		return ;
	item = malloc(sizeof(t_stack));
	if (NULL == item)
		return ;
	item->next = NULL;
	item->value = nbr;
	if (NULL == *stack)
	{
		*stack = item;
		item->prev = NULL;
	}
	else
	{
		last_item = find_last_item(*stack);
		last_item->next = item;
		item->prev = last_item;
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_item;
	long	smallest;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_item = stack;
		}
		stack = stack->next;
	}
	return (smallest_item);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
