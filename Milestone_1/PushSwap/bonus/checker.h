/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:23:15 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 12:45:49 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				val_idx;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		size;
}				t_stack;

typedef struct s_boss
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_boss;

t_boss	*get_boss(void);

void	checker(t_boss *boss);

char	*get_next_instruction(void);

void	instruction_r(t_boss *boss, char *instruction);

int		is_sorted(t_boss *boss);

void	free_stack(t_stack *stack);

void	handle_error(void);

t_stack	*init_stack(void);

void	add_node_back(t_stack *stack, t_list *new);

void	fill_stack_from_array(t_stack *a, char **str_arr);

t_list	*ft_lstnew(int content);

void	parse_input(int argc, char **argv, int i, t_stack *a);

void	sort_arr(int *arr, int size);

void	val_index(t_boss *boss);

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

char	**ft_split(char const *s, char c);

void	push_node(t_stack *dest, t_stack *src);

void	pa(t_boss *boss);

void	pb(t_boss *boss);

void	swap_nodes(t_stack *stack);

void	sa(t_boss *boss);

void	sb(t_boss *boss);

void	ss(t_boss *boss);

void	rotate(t_stack *stack);

void	ra(t_boss *boss);

void	rb(t_boss *boss);

void	rr(t_boss *boss);

void	rev_rotate(t_stack *stack);

void	rra(t_boss *boss);

void	rrb(t_boss *boss);

void	rrr(t_boss *boss);

long	ft_atoi_safe(const char *str);

#endif
