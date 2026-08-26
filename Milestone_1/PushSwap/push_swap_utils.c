/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:49:12 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 19:57:54 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (n == 0)
		return (0);
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

long	ft_atoi_safe(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (!str[i])
		return (3000000000);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (3000000000);
		result = (result * 10) + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (3000000000);
		i++;
	}
	return ((result * sign));
}

void	save_cost(t_list *current, int a, int b, int same_half)
{
	if (same_half)
	{
		if (a > b)
			current->push_cost = a;
		else
			current->push_cost = b;
	}
	else
		current->push_cost = a + b;
	if (current->push_cost > (current->val_idx - current->target->val_idx))
		current->push_cost += (current->val_idx - current->target->val_idx) / 4;
}

void	calc_cost(t_boss *boss)
{
	t_list	*current;
	int		cost_a;
	int		cost_b;
	int		a_above;
	int		b_above;

	current = boss->stack_a->head;
	boss->cheapest = NULL;
	while (current)
	{
		cost_a = current->index;
		a_above = (cost_a <= (boss->stack_a->size / 2));
		if (!a_above)
			cost_a = boss->stack_a->size - current->index;
		cost_b = current->target->index;
		b_above = (cost_b <= (boss->stack_b->size / 2));
		if (!b_above)
			cost_b = boss->stack_b->size - current->target->index;
		save_cost (current, cost_a, cost_b, (a_above == b_above));
		if (!boss->cheapest || current->push_cost < boss->cheapest->push_cost)
			boss->cheapest = current;
		current = current->next;
	}
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
