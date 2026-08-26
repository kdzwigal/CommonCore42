/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:23:00 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:49:38 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rrb(t_boss *boss)
{
	rev_rotate(boss->stack_b);
}

void	rrr(t_boss *boss)
{
	rev_rotate(boss->stack_a);
	rev_rotate(boss->stack_b);
}
