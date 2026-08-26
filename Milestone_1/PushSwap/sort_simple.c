/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:43:03 by pwarda            #+#    #+#             */
/*   Updated: 2026/08/06 14:45:55 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_boss *boss)
{
	set_index(boss->stack_a);
	set_index(boss->stack_b);
	if (boss->stack_a->size == 1)
		return ;
	if (boss->stack_a->size == 2)
	{
		if (boss->stack_a->head->content > boss->stack_a->head->next->content)
			sa(boss);
	}
	if (boss->stack_a->size == 3)
		sort_three(boss);
	if (boss->stack_a->size > 3)
	{
		while (boss->stack_a->size > 3)
		{
			boss->cheapest = get_min_node(boss->stack_a);
			finish_cheapest_three(boss);
		}
		sort_three(boss);
		while (boss->stack_b->size > 0)
			pa(boss);
	}
}

int	find_min_pos(t_stack *a)
{
	t_list	*p;
	int		pos;
	int		min_pos;
	int		min_rank;

	p = a->head;
	min_rank = p->val_idx;
	min_pos = 0;
	pos = 0;
	while (p)
	{
		if (p->val_idx < min_rank)
		{
			min_rank = p->val_idx;
			min_pos = pos;
		}
		p = p->next;
		pos++;
	}
	return (min_pos);
}

void	bring_to_top(t_boss *boss, int pos)
{
	if (pos <= boss->stack_a->size / 2)
		while (pos-- > 0)
			ra(boss);
	else
	{
		pos = boss->stack_a->size - pos;
		while (pos-- > 0)
			rra(boss);
	}
}

void	sort_simple(t_boss *boss)
{
	t_stack	*a;
	t_stack	*b;

	a = boss->stack_a;
	b = boss->stack_b;
	while (a->head)
	{
		bring_to_top(boss, find_min_pos(a));
		pb(boss);
	}
	while (b->head)
		pa(boss);
}

void	simple_sort(t_boss *boss)
{
	if (boss->stack_a->size <= 5)
		sort_five(boss);
	else
		sort_simple(boss);
}
