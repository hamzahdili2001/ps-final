/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:48:58 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 10:28:27 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// DEBUGGING
# include <stdio.h>
// ENDDEBUGGNIG
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT,
}			t_op;

typedef enum e_flags
{
	MODE_NONE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
}			t_flags;

typedef struct s_stack
{
	int		*data;
	int		head;
	size_t	size;
	size_t	cap;
}			t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		mode;
	int		bench;
	int		adaptive;
	size_t	ops_count;
	size_t	op_counts[OP_COUNT];
	int		silent;
	double	disorder;
}			t_ps;
// init
void		ps_init(t_ps *ps);
void		free_ps(t_ps *ps);
// output
void		ft_putchar_fd(int c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(long n, int fd);

// utils
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(int c);
int			ft_issign(int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
char		*ft_substr(char *str, unsigned int start, size_t len);
int			*ft_split(char *str, size_t *count_out);
int			ft_isflag(char *s);
int			ft_sqrt(int n);

// utils extra
size_t		token_count(const char *s);

// ops utils
void		pushes(t_stack *from, t_stack *to);
void		stack_pushes(t_ps *ps, t_op code);
void		stack_swaps(t_ps *ps, t_op code);
void		stack_rotations(t_ps *ps, t_op code);
void		stack_rrotations(t_ps *ps, t_op code);
// op function
void		op(t_ps *ps, t_op code);
// parsing
int			parse_flags(int ac, char **av, t_ps *ps);
int			parse_string(int ac, char **av, t_ps *ps);
int			ft_atoi(const char *s, int *out);
int			parse_args(int ac, char **av, t_ps *ps);
char		**normalize_args(int ac, char **av, int *new_ac);
void		free_partial(char **args, int count);
void		free_normalized_args(char **args);
// stack
void		stack_push(t_stack *s, int v);
int			stack_get(t_stack *s, int index);
int			stack_allocate(t_stack *s, size_t cap);
int			stack_pop(t_stack *s);
void		stack_swap(t_stack *s);
void		stack_rotate(t_stack *s);
void		stack_rrotate(t_stack *s);
// algo
double		compute_disorder(t_ps *ps);
int			is_sorted(t_ps *ps);
int			assign_ranks(t_stack *a);
void		sort_simple(t_ps *ps);
int			sort_medium(t_ps *ps);
int			sort_complex(t_ps *ps);
void		sort_3(t_ps *ps);
void		sort_2(t_ps *ps);
void		sort_small(t_ps *ps);
int			mode_adaptive(t_ps *ps);
void		print_bench(t_ps *ps);
int			sort_dispatch(t_ps *ps);
#endif
