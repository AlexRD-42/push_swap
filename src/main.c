/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:34:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/14 12:16:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

int64_t	ft_atoi(const char *num_str);
void	ft_putnbr(int64_t n, int fd);

static void	ft_stackswap(int32_t *a, int32_t *b)
{
	int32_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_error(int32_t a, int32_t b, uint_fast8_t code, size_t index)
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

// Maybe add a 1024 buffer
int	main(int argc, char **argv)
{
	int32_t	*stack_a;
	int32_t	*stack_b;
	int64_t	number;

	if (argc <= 1)
		return (0);
	stack_a = (int32_t *) malloc(sizeof(int32_t) * (argc - 1));
	stack_b = (int32_t *) malloc(sizeof(int32_t) * (argc - 1));
	if (stack_a == NULL || stack_b == NULL)
		return (ft_error(stack_a, stack_b, 0, 0));
	else if (ft_parse_input(argv, argc, stack_a, stack_b))
		return (1);

	free(stack_a);
	free(stack_b);
}
