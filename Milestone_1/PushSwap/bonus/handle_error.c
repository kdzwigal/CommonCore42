/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:54:55 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:43:26 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *stack)
{
	t_list	*curr;
	t_list	*tmp;

	curr = stack->head;
	tmp = NULL;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(stack);
}

void	handle_error(void)
{
	t_boss	*boss;

	boss = get_boss();
	if (boss->stack_a)
		free_stack(boss->stack_a);
	if (boss->stack_b)
		free_stack(boss->stack_b);
	write(2, "Error\n", 6);
	exit(1);
}


float	compute_disorder(t_boss *boss, int size, int mistakes, int total_pairs)
{
	t_list	*tmp;
	t_list	*curr;

	tmp = boss->stack_a->head;
	while (tmp)
	{
		curr = tmp->next;
		while (curr)
		{
			total_pairs++;
			if (tmp->content > curr->content)
				mistakes++;
			if (tmp->content == curr->content)
				handle_error ();
			curr = curr->next;
		}
		tmp = tmp->next;
	}
	if (total_pairs == 0 || (total_pairs != (size * (size - 1) / 2)))
		return (-1);
	boss->disorder = ((float)mistakes / (float)total_pairs);
	return ((float)mistakes / (float)total_pairs);
}
