/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:26:10 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:49:48 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_node(t_stack *dest, t_stack *src)
{
	t_list	*tmp_node;

	if (!src || !src->head)
		return ;
	tmp_node = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	tmp_node->next = dest->head;
	if (dest->head)
		dest->head->prev = tmp_node;
	else
		dest->tail = tmp_node;
	dest->head = tmp_node;
	dest->size++;
}

void	pa(t_boss *boss)
{
	push_node(boss->stack_a, boss->stack_b);
}

void	pb(t_boss *boss)
{
	push_node(boss->stack_b, boss->stack_a);
}
