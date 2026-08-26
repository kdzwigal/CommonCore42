/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:30:26 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 17:47:49 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boss	*get_boss(void)
{
	static t_boss	boss;

	return (&boss);
}

int	main(int argc, char **argv)
{
	t_boss	*boss;
	t_flags	flags_struct;
	int		start_index;

	boss = get_boss();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		handle_error();
	boss->stack_a = init_stack();
	boss->stack_b = init_stack();
	boss->flags = &flags_struct;
	start_index = parse_flags(argc, argv, boss->flags);
	parse_input(argc, argv, start_index, boss->stack_a);
	boss->ops = init_ops();
	if (compute_disorder(boss, boss->stack_a->size, 0, 0))
		choose_sort(boss);
	if (boss->flags->bench)
		print_benchmark(boss);
	free_stack(boss->stack_a);
	free_stack(boss->stack_b);
	free(boss->ops);
	return (0);
}
