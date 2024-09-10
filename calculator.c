/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:56:45 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 15:56:47 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_item(t_stack *a,
							t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_item;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_item = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_item = find_smallest(a);
		else
			b->target_item = target_item;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_item->above_median)
			b->push_price += b->target_item->current_position;
		else
			b->push_price += len_a - (b->target_item->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_item;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_item = b;
		}
		b = b->next;
	}
	best_match_item->cheapest = true;
}

void	update_items(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_item(a, b);
	set_price(a, b);
	set_cheapest(b);
}
