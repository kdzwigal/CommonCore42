/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:52:35 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:40:36 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_adaptive(t_boss *boss)
{
	if (boss->disorder < 0.20f)
	{
		boss->ops->strategy = "Adaptive / O(n²)";
		simple_sort(boss);
	}
	else if (boss->disorder < 0.50f && boss->disorder >= 0.20f)
	{
		boss->ops->strategy = "Adaptive / O(n√n)";
		medium_sort(boss);
	}
	else if (boss->disorder >= 0.50f)
	{
		boss->ops->strategy = "Adaptive / O(n log n)";
		complex_sort(boss);
	}
	else
		handle_error();
}

void	choose_sort(t_boss *boss)
{
	val_index(boss);
	if (boss->flags->simple)
	{
		boss->ops->strategy = "Simple / O(n²)";
		simple_sort(boss);
	}
	else if (boss->flags->medium)
	{
		boss->ops->strategy = "Medium / O(n√n)";
		medium_sort(boss);
	}
	else if (boss->flags->complex)
	{
		boss->ops->strategy = "Complex / O(n log n)";
		complex_sort(boss);
	}
	else if (boss->flags->adaptive)
		sort_adaptive(boss);
	else
		sort_adaptive(boss);
}

void	sort_three(t_boss *boss)
{
	t_list	*highest_node;

	highest_node = get_max_node(boss->stack_a);
	if (boss->stack_a->head == highest_node)
		ra(boss);
	else if (boss->stack_a->head->next == highest_node)
		rra(boss);
	if (boss->stack_a->head->content > boss->stack_a->head->next->content)
		sa(boss);
}

void	finish_cheapest_three(t_boss *boss)
{
	while (boss->stack_a->head != boss->cheapest)
	{
		if (boss->cheapest->above_median)
			ra(boss);
		else
			rra(boss);
	}
	pb(boss);
	set_index(boss->stack_a);
	set_index(boss->stack_b);
}
