/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:24:54 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:44:29 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putendl_ops("sa");
	boss->ops->sa++;
	boss->ops->sum++;
}

void	sb(t_boss *boss)
{
	swap_nodes(boss->stack_b);
	ft_putendl_ops("sb");
	boss->ops->sb++;
	boss->ops->sum++;
}

void	ss(t_boss *boss)
{
	swap_nodes(boss->stack_a);
	swap_nodes(boss->stack_b);
	ft_putendl_ops("ss");
	boss->ops->ss++;
	boss->ops->sum++;
}
