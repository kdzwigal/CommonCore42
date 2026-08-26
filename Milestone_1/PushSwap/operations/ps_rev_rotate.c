/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:23:00 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 12:12:25 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *stack)
{
	t_list	*last_node;
	t_list	*second_last;

	if (!stack || !stack->head || stack->head == stack->tail)
		return ;
	last_node = stack->tail;
	second_last = last_node->prev;
	stack->tail = second_last;
	stack->tail->next = NULL;
	last_node->prev = NULL;
	last_node->next = stack->head;
	stack->head->prev = last_node;
	stack->head = last_node;
}

void	rra(t_boss *boss)
{
	rev_rotate(boss->stack_a);
	ft_putendl_ops("rra");
	boss->ops->rra++;
	boss->ops->sum++;
}

void	rrb(t_boss *boss)
{
	rev_rotate(boss->stack_b);
	ft_putendl_ops("rrb");
	boss->ops->rrb++;
	boss->ops->sum++;
}

void	rrr(t_boss *boss)
{
	rev_rotate(boss->stack_a);
	rev_rotate(boss->stack_b);
	ft_putendl_ops("rrr");
	boss->ops->rrr++;
	boss->ops->sum++;
}

void	rev_rotate_both(t_boss *boss)
{
	while (boss->stack_a->head != boss->cheapest
		&& boss->stack_b->head != boss->cheapest->target)
		rrr(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
}
