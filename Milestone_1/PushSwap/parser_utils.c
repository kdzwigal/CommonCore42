/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:54:31 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 14:36:24 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_ops	*init_ops(void)
{
	t_ops	*new_ops;

	new_ops = (t_ops *)malloc(sizeof(t_ops));
	if (!new_ops)
		handle_error();
	new_ops->sa = 0;
	new_ops->sb = 0;
	new_ops->ss = 0;
	new_ops->pa = 0;
	new_ops->pb = 0;
	new_ops->ra = 0;
	new_ops->rb = 0;
	new_ops->rr = 0;
	new_ops->rra = 0;
	new_ops->rrb = 0;
	new_ops->rrr = 0;
	new_ops->sum = 0;
	new_ops->strategy = "No strategy for 0 disorder";
	return (new_ops);
}

int	set_flag(char *arg, t_flags *flags)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		flags->simple = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		flags->medium = 1;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		flags->complex = 1;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		flags->adaptive = 1;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		flags->bench = 1;
		return (2);
	}
	else
		return (0);
	return (1);
}

void	init_flags(t_flags *flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	flags->adaptive = 0;
	flags->bench = 0;
}

int	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	init_flags(flags);
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if ((flags->simple == 1 || flags->medium == 1 || flags->complex == 1
				|| flags->adaptive == 1) && set_flag(argv[i], flags) == 1)
			handle_error();
		else if (argv[i][2] == '\0')
		{
			i++;
			handle_error();
		}
		else if (!set_flag(argv[i], flags))
			handle_error();
		i++;
	}
	if (!argv[i])
		handle_error();
	return (i);
}
