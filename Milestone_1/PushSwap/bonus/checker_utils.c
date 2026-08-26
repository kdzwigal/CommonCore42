/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:49:12 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:43:14 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	is_sorted(t_boss *boss)
{
	t_list	*curr;

	curr = boss->stack_a->head;
	if (curr == NULL)
		return (1);
	while (curr->next)
	{
		if (curr->val_idx > curr->next->val_idx)
			return (0);
		curr = curr->next;
	}
	return (1);
}
