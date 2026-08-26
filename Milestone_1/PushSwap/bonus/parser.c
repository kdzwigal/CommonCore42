/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:40:12 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:47:00 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		handle_error();
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	add_node_back(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		return ;
	}
	if (stack->tail == NULL)
	{
		stack->tail = new;
		new->prev = stack->head;
		new->index = new->prev->index + 1;
		stack->head->next = new;
		return ;
	}
	stack->tail->next = new;
	new->prev = stack->tail;
	new->index = new->prev->index + 1;
	stack->tail = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->val_idx = 0;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	fill_stack_from_array(t_stack *a, char **str_arr)
{
	int		i;
	long	value;
	t_list	*new_node;

	i = 0;
	while (str_arr[i] != NULL)
	{
		value = ft_atoi_safe(str_arr[i]);
		if (value > 2147483647 || value < -2147483648)
		{
			while (str_arr[i] != NULL)
				free(str_arr[i++]);
			free(str_arr);
			handle_error();
		}
		new_node = ft_lstnew(value);
		free(str_arr[i]);
		if (!new_node)
			handle_error();
		add_node_back(a, new_node);
		a->size++;
		i++;
	}
	free(str_arr);
}

void	parse_input(int argc, char **argv, int i, t_stack *a)
{
	char	**str_arr;

	while (i < argc)
	{
		str_arr = ft_split(argv[i], ' ');
		if (!str_arr || !str_arr[0])
		{
			if (str_arr)
				free(str_arr);
			handle_error();
		}
		fill_stack_from_array(a, str_arr);
		i++;
	}
}
