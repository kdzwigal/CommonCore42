/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:32:18 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 09:55:29 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max_node(t_stack *stack)
{
	t_list	*current;
	t_list	*max_node;
	long	max_val;

	current = stack->head;
	max_val = -2147483649;
	while (current)
	{
		if (current->content > max_val)
		{
			max_val = current->content;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

void	chunk_sort_pa(t_boss *boss)
{
	while (boss->stack_b->size)
	{
		set_index(boss->stack_a);
		set_index(boss->stack_b);
		boss->cheapest = get_max_node(boss->stack_b);
		while (boss->stack_b->head != boss->cheapest)
		{
			if (boss->cheapest->above_median)
				rb(boss);
			else
				rrb(boss);
		}
		pa(boss);
		boss->cheapest = NULL;
		set_index(boss->stack_a);
		set_index(boss->stack_b);
	}
}

void	chunk_sort(t_boss *boss)
{
	t_list	*current;
	int		chunk;
	int		pushed;

	chunk = ft_sqrt(boss->stack_a->size) * 1.4;
	pushed = 0;
	current = boss->stack_a->head;
	while (current)
	{
		if (current->val_idx <= pushed)
		{
			pb(boss);
			rb(boss);
			pushed++;
		}
		else if (current->val_idx < pushed + chunk)
		{
			pb(boss);
			pushed++;
		}
		else
			ra(boss);
		current = boss->stack_a->head;
	}
	chunk_sort_pa(boss);
}

void	medium_sort(t_boss *boss)
{
	if (boss->stack_a->size <= 5)
		sort_five(boss);
	else
		chunk_sort(boss);
}
