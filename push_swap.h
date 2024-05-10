
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // para limts
# include <stddef.h> // Para o tipo size_t
#include <stdio.h> // excluir!!!!!!!
# include <stdlib.h>
# include <unistd.h>
typedef struct s_lst
{
	int				content;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

// SIMPLE_SORT_C
int					is_sorted(t_lst **stack);
void				simple_sort(t_lst **a_stack, t_lst **b_stack);

// SIMPLE_SORT_UTLIS_C
int					is_sorted(t_lst **stack);
int					is_order(t_lst **stack, int size);
void				reset_index(t_lst **stack);
void				rotate_to_min(t_lst **stack, int size);

// INDEX_C
void				ps_index(t_lst **stack);

// RADIX_C
int					lst_size(t_lst *lst);
void				radix_sort(t_lst **a_stack, t_lst **b_stack);

// LST_UTILS_C
void				lst_addfront(t_lst **stack, t_lst *news);
void				lst_addback(t_lst **stack, t_lst *news);
t_lst				*lst_new(int content);
t_lst				*lst_last(t_lst *stack);

// SWAP_C
void				do_sa(t_lst **stack);
void				do_sb(t_lst **stack);
void				do_ss(t_lst **a_stack, t_lst **b_stack);

// PUSH_C
void				do_pa(t_lst **a_stack, t_lst **b_stack);
void				do_pb(t_lst **a_stack, t_lst **b_stack);

// ROTATE_C
void				rotate(t_lst **stack);
void				do_ra(t_lst **stack);
void				do_rb(t_lst **stack);
void				do_rr(t_lst **a_stack, t_lst **b_stack);

// REVERSE_C
void				reverse(t_lst **stack);
void				do_rra(t_lst **stack);
void				do_rrb(t_lst **stack);
void				do_rrr(t_lst **a_stack, t_lst **b_stack);

// utils
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_putstr_fd(char *s, int fd);
void				free_split(char **split);
size_t				ft_strlen(const char *str);
void	print_stack(t_lst *stack);
// split
char				**ft_split(char const *s, char c);

#endif
