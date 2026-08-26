/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:37:48 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:44:46 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	val_index(t_boss *boss)
{
	t_list	*current;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * (boss->stack_a->size));
	if (!arr)
		handle_error();
	current = boss->stack_a->head;
	i = 0;
	while (current)
	{
		arr[i++] = current->content;
		current = current->next;
	}
	sort_arr(arr, boss->stack_a->size);
	current = boss->stack_a->head;
	while (current)
	{
		i = 0;
		while (arr[i] != current->content)
			i++;
		current->val_idx = i;
		current = current->next;
	}
	free(arr);
}
