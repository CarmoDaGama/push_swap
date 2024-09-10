/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:56:57 by cgama             #+#    #+#             */
/*   Updated: 2024/09/06 15:56:59 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_item)
{
	while (*a != cheapest_item->target_item
		&& *b != cheapest_item)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_item)
{
	while (*a != cheapest_item->target_item
		&& *b != cheapest_item)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack **stack,
							t_stack *top_item,
							char stack_name)
{
	while (*stack != top_item)
	{
		if (stack_name == 'a')
		{
			if (top_item->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_item->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

static void	move_items(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_item;

	cheapest_item = return_cheapest(*b);
	if (cheapest_item->above_median
		&& cheapest_item->target_item->above_median)
		rotate_both(a, b, cheapest_item);
	else if (!(cheapest_item->above_median)
		&& !(cheapest_item->target_item->above_median))
		reverse_rotate_both(a, b, cheapest_item);
	finish_rotation(b, cheapest_item, 'b');
	finish_rotation(a, cheapest_item->target_item, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	simple_sort(a);
	while (*b)
	{
		update_items(*a, *b);
		move_items(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
