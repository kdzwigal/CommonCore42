/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:24:54 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:48:55 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_nodes(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	else
		stack->tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	sa(t_boss *boss)
{
	swap_nodes(boss->stack_a);
}

void	sb(t_boss *boss)
{
	swap_nodes(boss->stack_b);
}

void	ss(t_boss *boss)
{
	swap_nodes(boss->stack_a);
	swap_nodes(boss->stack_b);
}
