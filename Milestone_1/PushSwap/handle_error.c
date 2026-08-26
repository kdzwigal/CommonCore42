/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:54:55 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/05 17:58:19 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (boss->ops)
		free(boss->ops);
	write(2, "Error\n", 6);
	exit(1);
}

int	gnl_strlen(const char *str)
{
	int	src_len;

	if (!str)
		return (0);
	src_len = 0;
	while (str[src_len] != '\0')
	{
		src_len++;
	}
	return (src_len);
}

void	ft_putendl_ops(char *s)
{
	if (!s)
		return ;
	write(OPS_FD, s, gnl_strlen(s));
	write(OPS_FD, "\n", 1);
	return ;
}

void	print_benchmark(t_boss *boss)
{
	int	dec;

	dec = (int)(100 * ((100 * boss->disorder) - ((int)(100 * boss->disorder))));
	ft_printf("[bench] disorder:  %d.", (int)(100 * boss->disorder));
	if (dec < 10 && boss->disorder)
		ft_printf("0");
	ft_printf("%d%%\n", dec);
	ft_printf("[bench] strategy:  %s\n", boss->ops->strategy);
	ft_printf("[bench] total_ops:  %d\n", boss->ops->sum);
	ft_printf("[bench] sa:  %d sb:  %d ss:  %d pa:  %d pb:  %d\n",
		boss->ops->sa, boss->ops->sb, boss->ops->ss, boss->ops->pa,
		boss->ops->pb);
	ft_printf("[bench] ra:  %d rb:  %d rr:  %d rra:  %d rrb:  %d rrr:  %d\n",
		boss->ops->ra, boss->ops->rb, boss->ops->rr, boss->ops->rra,
		boss->ops->rrb, boss->ops->rrr);
}
