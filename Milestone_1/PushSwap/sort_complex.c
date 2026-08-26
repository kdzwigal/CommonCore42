/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:11:02 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:23:57 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_cheapest(t_boss *boss)
{
	t_list	*current;
	t_list	*target;
	int		a_above;
	int		b_above;

	current = boss->cheapest;
	if (!current || !current->target)
		handle_error();
	target = current->target;
	a_above = (current->index <= boss->stack_a->size / 2);
	b_above = (target->index <= boss->stack_b->size / 2);
	if (a_above && b_above)
		rotate_both(boss);
	else if (!a_above && !b_above)
		rev_rotate_both(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
	finish_cheapest(boss);
}

void	find_target(t_list *current_a, t_list *head_b, t_boss *boss)
{
	t_list	*current_b;
	int		val_a;
	int		val_b;
	int		diff;

	diff = INT_MAX;
	while (current_a)
	{
		diff = INT_MAX;
		val_a = current_a->val_idx;
		current_b = head_b;
		while (current_b)
		{
			val_b = current_b->val_idx;
			if (val_a > val_b && (val_a - val_b) < diff)
			{
				diff = val_a - val_b;
				current_a->target = current_b;
			}
			if (current_a->target == NULL)
				current_a->target = get_min_node(boss->stack_b);
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
}

void	find_cheapest(t_boss *boss)
{
	find_target(boss->stack_a->head, boss->stack_b->head, boss);
	calc_cost(boss);
}

void	turk_sort(t_boss *boss)
{
	pb(boss);
	pb(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
	while (boss->stack_a->size > 3)
	{
		find_cheapest(boss);
		process_cheapest(boss);
		set_index(boss->stack_a);
		set_index(boss->stack_b);
	}
	sort_three(boss);
	turk_back(boss);
}

void	complex_sort(t_boss *boss)
{
	if (boss->stack_a->size <= 5)
		sort_five(boss);
	else
		turk_sort(boss);
}
