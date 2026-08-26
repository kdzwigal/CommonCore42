/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:33:37 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:44:26 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putendl_ops("ra");
	boss->ops->ra++;
	boss->ops->sum++;
}

void	rb(t_boss *boss)
{
	rotate(boss->stack_b);
	ft_putendl_ops("rb");
	boss->ops->rb++;
	boss->ops->sum++;
}

void	rr(t_boss *boss)
{
	rotate(boss->stack_a);
	rotate(boss->stack_b);
	ft_putendl_ops("rr");
	boss->ops->rr++;
	boss->ops->sum++;
}

void	rotate_both(t_boss *boss)
{
	while (boss->stack_a->head != boss->cheapest
		&& boss->stack_b->head != boss->cheapest->target)
		rr(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
}
