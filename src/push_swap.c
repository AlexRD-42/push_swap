/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:34:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 20:52:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

static
int	parse_error(uint_fast8_t code, size_t index, size_t index2)
{
	static const size_t	msg_length[3] = {32, 40, 48};
	static const char	*error_msg[3] = {
		"Error: Not an integer at index: ",
		"Error: Integer exceeds limits at index: ",
		"Error: Duplicate integer was detected at index: "};

	write(2, error_msg[code], msg_length[code]);
	ft_putnbr(index - 1, 2);
	if (index2 != 0)
	{
		write(1, ", ", 2);
		ft_putnbr(index2 - 1, 2);
	}
	write(1, "\n", 1);
	return (1);
}

static
int	parse_duplicates(int32_t *array, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] == array[j])
				return (parse_error(2, i, j));
			j++;
		}
		i++;
	}
	return (0);
}

static
int	parse_input(char **argv, int argc, int32_t *array, size_t length)
{
	size_t	i;
	int64_t	number;
	char	*str;

	i = 0;
	while (--argc > 0)
	{
		str = argv[argc];
		if (*str == '-')
			str++;
		while (*str != 0)
		{
			if (*str < '0' || *str > '9')
				return (parse_error(0, argc, 0));
			str++;
		}
		if (str - argv[argc] > (10 + (argv[argc][0] == '-')))
			return (parse_error(1, argc, 0));
		number = ft_atoi(argv[argc]);
		if (number > INT32_MAX || number < INT32_MIN)
			return (parse_error(1, argc, 0));
		array[i++] = (int32_t) number;
	}
	return (parse_duplicates(array, length));
}

// int	main(int argc, char **argv)
// {
// 	int32_t	array_a[MAX_SIZE];
// 	int32_t	array_b[MAX_SIZE];
// 	t_stack	sta;
// 	t_stack	stb;

// 	if (argc <= 1)
// 		return (0);
// 	ft_memset(array_a, 0, MAX_SIZE * sizeof(int32_t));
// 	if (parse_input(argv, argc, array_a, (size_t) argc - 1))
// 		return (1);
// 	sta.bot = array_a;
// 	stb.bot = array_b;
// 	ft_initialize(&sta, &stb, argc - 1);
// 	ft_sort(&sta, &stb);
// 	ft_putnbr(ft_get_entropy(&sta, &stb), 1);
// }
