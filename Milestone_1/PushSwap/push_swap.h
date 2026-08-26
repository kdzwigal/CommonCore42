/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:23:15 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/08/06 14:51:47 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

# ifndef OPS_FD
#  define OPS_FD 1
# endif

# ifndef BENCH_FD
#  define BENCH_FD 2
# endif

typedef struct s_ops
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		sum;
	char	*strategy;
}				t_ops;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}				t_flags;

typedef struct s_list
{
	int				content;
	int				val_idx;
	int				index;
	int				push_cost;
	int				above_median;
	struct s_list	*target;
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
	t_list		*cheapest;
	t_ops		*ops;
	t_flags		*flags;
	float		disorder;
}				t_boss;

t_boss	*get_boss(void);

void	free_stack(t_stack *stack);

int		find_min_pos(t_stack *a);

void	bring_to_top(t_boss *boss, int pos);

void	sort_simple(t_boss *boss);

t_ops	*init_ops(void);

void	complex_sort(t_boss *boss);

void	medium_sort(t_boss *boss);

void	simple_sort(t_boss *boss);

void	ft_putendl_ops(char *s);

int		gnl_strlen(const char *str);

void	sort_five(t_boss *boss);

void	chunk_sort_pa(t_boss *boss);

void	finish_cheapest_three(t_boss *boss);

int		ft_sqrt(int nb);

void	chunk_sort(t_boss *boss);

int		ft_printf(const char *str, ...);

int		ft_printf_parser(char type, va_list content);

int		ft_putstr(char *str);

int		ft_putchar(char c);

int		ft_putbase(unsigned long n, const char *base);

int		ft_putaddress(void *ptr);

int		ft_putnbr(int n);

void	choose_sort(t_boss *boss);

void	sort_adaptive(t_boss *boss);

void	turk_back(t_boss *boss);

void	find_cheapest(t_boss *boss);

void	find_target(t_list *current_a, t_list *current_b, t_boss *boss);

void	save_cost(t_list *current, int cost_a, int cost_b, int same_half);

void	calc_cost(t_boss *boss);

void	finish_cheapest(t_boss *boss);

void	turk_sort(t_boss *boss);

void	print_benchmark(t_boss *boss);

void	set_index(t_stack *stack);

void	handle_error(void);

t_stack	*init_stack(void);

int		parse_flags(int argc, char **argv, t_flags *flags);

void	init_flags(t_flags *flags);

int		set_flag(char *arg, t_flags *flags);

void	add_node_back(t_stack *stack, t_list *new);

void	fill_stack_from_array(t_stack *a, char **str_arr);

t_list	*ft_lstnew(int content);

void	parse_input(int argc, char **argv, int i, t_stack *a);

void	sort_arr(int *arr, int size);

void	val_index(t_boss *boss);

void	choose_sort(t_boss *boss);

void	sort_three(t_boss *boss);

t_list	*get_max_node(t_stack *stack);

t_list	*get_min_node(t_stack *stack);

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

void	rotate_both(t_boss *boss);

void	rev_rotate(t_stack *stack);

void	rra(t_boss *boss);

void	rrb(t_boss *boss);

void	rrr(t_boss *boss);

void	rev_rotate_both(t_boss *boss);

float	compute_disorder(t_boss *boss, int size, int mistakes, int total_pairs);

long	ft_atoi_safe(const char *str);

#endif
