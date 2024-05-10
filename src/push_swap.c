

#include "../push_swap.h"


static int	ps_check_dup(t_lst *stack)
{
	int		tmp;
	t_lst	*dup;

	while (stack && stack->next)
	{
		tmp = stack->content;
		dup = stack;
		while (dup->next)
		{
			dup = dup->next;
			if (dup->content == tmp)
				return (-1);
		}
		stack = stack->next;
	}
	return (1);
}

static void	ps_stackclear(t_lst **stack)
{
	if (!stack || !(*stack))
		return ;
	ps_stackclear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}


static int	ps_initstack(int ac, char **av, t_lst **a_stack)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (0);
		while (split[j])
		{
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				return (0);
			lst_addback(a_stack, lst_new(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

#include "../push_swap.h"

int main(int ac, char **av) {
    t_lst *a_stack;
    t_lst *b_stack;

    if (ac == 1)
        return (ft_putstr_fd("Error\n", 1));

    a_stack = NULL;
    b_stack = NULL;

    // Inicializando e verificando pilha
    if (ps_initstack(ac, av, &a_stack) == 0 || ps_check_dup(a_stack) == -1)
        return (ft_putstr_fd("Error\n", 1));

    // Imprime a pilha antes de qualquer operação de ordenação
    printf("Pilha A antes da ordenação:\n");
    print_stack(a_stack);

    // Indexa e ordena se necessário
    ps_index(&a_stack);
    if (is_sorted(&a_stack) != 1) {
        if (lst_size(a_stack) <= 5) {
            simple_sort(&a_stack, &b_stack);
        } else {
            radix_sort(&a_stack, &b_stack);
        }
        // Imprime a pilha após a ordenação
        printf("Pilha A após ordenação:\n");
        print_stack(a_stack);
        printf("Pilha B (auxiliar) após ordenação:\n");
        print_stack(b_stack);
    }

    // Limpeza final das pilhas
    ps_stackclear(&a_stack);
    ps_stackclear(&b_stack);

    return 0;
}
