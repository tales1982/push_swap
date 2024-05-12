

#include "../push_swap.h"

static void	sort_tree(STACK **stack)
{
	while (is_sorted(stack) != 1)
	{
		if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index < (*stack)->next->next->index))
			sa(stack);
		else if (((*stack)->index > ((*stack)->next->index))
			&& ((*stack)->index > (*stack)->next->next->index))
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_four(STACK **a_stack, STACK **b_stack)
{
	if (is_order(a_stack, 4) == 1)
		return ;
	rotate_to_min(a_stack, 4);
	pb(a_stack, b_stack);
	reset_index(a_stack);
	sort_tree(a_stack);
	pa(a_stack, b_stack);
}

void	simple_sort(STACK **a_stack, STACK **b_stack)
{
	int	size;

	size = lst_size(*a_stack);
	if (size == 3)
		sort_tree(a_stack);
	else if (size == 4)
		sort_four(a_stack, b_stack);
	else
	{
		if (is_order(a_stack, 5) == 1)
			return ;
		rotate_to_min(a_stack, 5);
		pb(a_stack, b_stack);
		reset_index(a_stack);
		sort_four(a_stack, b_stack);
		pa(a_stack, b_stack);
	}
}
