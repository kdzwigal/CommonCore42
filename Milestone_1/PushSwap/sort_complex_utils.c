/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:24:27 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:25:45 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_back(t_boss *boss)
{
	t_list	*current;
	int		stack_size;

	pb(boss);
	pb(boss);
	pb(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
	stack_size = boss->stack_b->size;
	while (stack_size)
	{
		current = get_max_node(boss->stack_b);
		while (boss->stack_b->head != current)
		{
			if (current->above_median)
				rb(boss);
			else
				rrb(boss);
		}
		pa(boss);
		set_index(boss->stack_b);
		stack_size = boss->stack_b->size;
	}
	set_index(boss->stack_a);
}

void	finish_cheapest(t_boss *boss)
{
	while (boss->stack_a->head != boss->cheapest)
	{
		if (boss->cheapest->above_median)
			ra(boss);
		else
			rra(boss);
	}
	while (boss->stack_b->head != boss->cheapest->target)
	{
		if (boss->cheapest->target->above_median)
			rb(boss);
		else
			rrb(boss);
	}
	pb(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
}

t_list	*get_min_node(t_stack *stack)
{
	t_list	*current;
	t_list	*min_node;
	long	min_val;

	current = stack->head;
	min_val = INT_MAX;
	while (current)
	{
		if (current->content < min_val)
		{
			min_val = current->content;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	set_index(t_stack *stack)
{
	t_list	*current;
	int		i;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	i = 0;
	while (current)
	{
		if (current->index <= (stack->size / 2))
			current->above_median = 1;
		if (current->index > (stack->size / 2))
			current->above_median = 0;
		current->index = i;
		current = current->next;
		i++;
	}
}
