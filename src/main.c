/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:34:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/20 11:03:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"

static int	ft_error(int32_t *a, int32_t *b, uint_fast8_t code, size_t index)
{
	static const size_t	msg_length[4] = {31, 21, 29, 39};
	static const char	*error_msg[4] = {
		"Error: Memory Allocation Failed",
		"Error: Not an integer at index: ",
		"Error: Integer exceeds limits at index: ",
		"Error: Duplicate integer was detected at index: "};

	write(2, error_msg[code], msg_length[code]);
	if (code != 0)
		ft_putnbr(index, 2);
	free(a);
	free(b);
	return (1);
}

static int	ft_parse_input(char **argv, int argc, int32_t *sta, int32_t *stb)
{
	int64_t	number;
	size_t	i;
	char	*str;

	i = 0;
	while (argc > 0)
	{
		str = argv[argc];
		if (*str == '-')
			str++;
		while (*str != 0)
		{
			if (*str < '0' || *str > '9')
				return (ft_error(NULL, NULL, 1, argc));
			str++;
		}
		if (str - argv[argc] > (10 + argv[argc][0] == '-'))
			return (ft_error(NULL, NULL, 2, argc));
		number = ft_atoi(argv[argc]);
		if (number > INT32_MAX || number < INT32_MIN)
			return (ft_error(sta, stb, 0, argc));
		sta[i++] = (int32_t) number;
		argc--;
	}
	return (0);
}

// // Can receive array a and b, and return stack a, b and s
// static int	ft_sort(t_stack *a, t_stack *b)
// {

// }

// Maybe add a 1024 buffer
// int	main(int argc, char **argv)
// {
// 	int32_t	*array_a;
// 	int32_t	*array_b;
// 	t_stack	stack_a;
// 	t_stack	stack_b;

// 	if (argc <= 1)
// 		return (0);
// 	array_a = (int32_t *) malloc(sizeof(int32_t) * (argc - 1));
// 	array_b = (int32_t *) malloc(sizeof(int32_t) * (argc - 1));
// 	if (array_a == NULL || array_b == NULL)
// 		return (ft_error(array_a, array_b, 0, 0));
// 	else if (ft_parse_input(argv, argc, array_a, array_b))
// 		return (1);
// 	stack_a.array = array_a;
// 	stack_a.length = argc - 1;
// 	stack_b.array = array_b;
// 	stack_b.length = argc - 1;

// 	free(stack_a.array);
// 	free(stack_b.array);
// }

// int main()
// {
// 	int32_t array[5] = {1, 2, 3, 4, 5};
// 	int32_t array0[5] = {0, 0, 0, 0, 0};
// 	t_stack	stack_a = {array, array + 4, 5};
// 	t_stack	stack_b = {array0, array0, 0};

// 	ft_command("PB", &stack_a, &stack_b);
// 	ft_command("PB", &stack_a, &stack_b);
// 	ft_command("RA", &stack_a, &stack_b);
// 	ft_command("RB", &stack_a, &stack_b);
// 	ft_command("RR", &stack_a, &stack_b);
// 	ft_command("RRA", &stack_a, &stack_b);
// 	ft_command("RRB", &stack_a, &stack_b);
// 	ft_command("RRR", &stack_a, &stack_b);
// }