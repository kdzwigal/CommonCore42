/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:30:26 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:43:02 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_boss	*get_boss(void)
{
	static t_boss	boss;

	return (&boss);
}

char	*get_next_instruction(void)
{
	char	*line;
	int		i;
	int		bytes_read;
	char	c;

	line = malloc(10 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	bytes_read = read(0, &c, 1);
	while (bytes_read > 0)
	{
		line[i++] = c;
		if (c == '\n' || i >= 9)
			break ;
		bytes_read = read(0, &c, 1);
	}
	if (bytes_read == -1 || (bytes_read == 0 && i == 0))
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

void	instruction_r(t_boss *boss, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", 4) == 0)
		ra(boss);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		rb(boss);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
		rr(boss);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		rra(boss);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		rrb(boss);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		rrr(boss);
	else
	{
		free(instruction);
		handle_error();
	}
}

void	checker(t_boss *boss)
{
	char	*instruction;

	instruction = get_next_instruction();
	while (instruction != NULL)
	{
		if (ft_strncmp(instruction, "sa\n", 4) == 0)
			sa(boss);
		else if (ft_strncmp(instruction, "sb\n", 4) == 0)
			sb(boss);
		else if (ft_strncmp(instruction, "ss\n", 4) == 0)
			ss(boss);
		else if (ft_strncmp(instruction, "pa\n", 4) == 0)
			pa(boss);
		else if (ft_strncmp(instruction, "pb\n", 4) == 0)
			pb(boss);
		else if (ft_strncmp(instruction, "r", 1) == 0)
			instruction_r(boss, instruction);
		else
		{
			free(instruction);
			handle_error();
		}
		free(instruction);
		instruction = get_next_instruction();
	}
}

int	main(int argc, char **argv)
{
	t_boss	*boss;

	boss = get_boss();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	boss->stack_a = init_stack();
	boss->stack_b = init_stack();
	parse_input(argc, argv, 1, boss->stack_a);
	val_index(boss);
	compute_disorder(boss, boss->stack_a->size, 0, 0);
	checker(boss);
	if (is_sorted(boss) && boss->stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(boss->stack_a);
	free_stack(boss->stack_b);
	return (0);
}
