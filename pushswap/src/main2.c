#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

static void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
    if (stack_size == 2 && !is_sorted(*a))
        do_sa(a);
    else if (stack_size == 3)
        tiny_sort(a);
    else if (stack_size > 3 && !is_sorted(*a))
        sort(a, b);
}

void	initialize_stack(int ac, char **av, t_stack **stack_a, int *is_one_str)
{
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        ac = get_av_len(av);
        if (ac == 0)
            ft_free_av(av, ac);
        *is_one_str = 1;
    }
    *stack_a = fill_stack_values(ac, av, *is_one_str);
}

void	check_and_free_input(int ac, char **av, int is_one_str)
{
    if (is_one_str)
        ft_free_av(av, ac);
}

void	check_input_and_exit(char **av, int is_one_str)
{
    if (!is_correct_input(av))
    {
        if (is_one_str)
            ft_free_av(av, ac);
        exit_error(NULL, NULL);
    }
}

int	main(int ac, char **av)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    int		stack_size;
    int		is_one_str;

    if (ac < 2)
        return (0);
    is_one_str = 0;
    initialize_stack(ac, av, &stack_a, &is_one_str);
    check_input_and_exit(av, is_one_str);
    stack_b = NULL;
    stack_size = get_stack_size(stack_a);
    assign_index(stack_a, stack_size + 1);
    push_swap(&stack_a, &stack_b, stack_size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    check_and_free_input(ac, av, is_one_str);
    return (0);
}
