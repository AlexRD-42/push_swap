/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:34:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 12:49:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

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
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

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
				return (write(2, "Error\n", 6));
			str++;
		}
		if (str - argv[argc] > (10 + (argv[argc][0] == '-')))
			return (write(2, "Error\n", 6));
		number = ft_atoi(argv[argc]);
		if (number > INT32_MAX || number < INT32_MIN)
			return (write(2, "Error\n", 6));
		array[i++] = (int32_t) number;
	}
	return (parse_duplicates(array, length));
}
