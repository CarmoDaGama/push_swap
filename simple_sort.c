/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:58:55 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 16:05:11 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest_item;
	int		highest;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_item = stack;
		}
		stack = stack->next;
	}
	return (highest_item);
}

void	simple_sort(t_stack **a)
{
	t_stack	*highest_item;

	highest_item = find_highest(*a);
	if (*a == highest_item)
		ra(a, false);
	else if ((*a)->next == highest_item)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		update_items(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
