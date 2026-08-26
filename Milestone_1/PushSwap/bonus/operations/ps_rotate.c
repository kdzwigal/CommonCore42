/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:33:37 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:49:16 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack *stack)
{
	t_list	*first_node;

	if (!stack || !stack->head || stack->head == stack->tail)
		return ;
	first_node = stack->head;
	stack->head = first_node->next;
	stack->head->prev = NULL;
	first_node->prev = stack->tail;
	first_node->next = NULL;
	stack->tail->next = first_node;
	stack->tail = first_node;
}

void	ra(t_boss *boss)
{
	rotate(boss->stack_a);
}

void	rb(t_boss *boss)
{
	rotate(boss->stack_b);
}

void	rr(t_boss *boss)
{
	rotate(boss->stack_a);
	rotate(boss->stack_b);
}
