/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:44:02 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 17:17:42 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap_bonus.h"

// trust me
static inline
uint8_t	check_command(const char *cmd)
{
	return (((((cmd[0] == 's' || cmd[0] == 'r' || cmd[0] == 'p')
					&& (cmd[1] == 'a' || cmd[1] == 'b'))
				|| (cmd[0] == cmd[1] && (cmd[0] == 'r' || cmd[0] == 's')))
			&& (cmd[2] == '\n' || cmd[2] == 0))
		|| ((cmd[0] == 'r' && cmd[1] == 'r')
			&& (cmd[2] == 'r' || cmd[2] == 'a' || cmd[2] == 'b')
			&& (cmd[3] == '\n' || cmd[3] == 0)));
}

static
uint8_t	is_sorted(const t_stack *sta, const t_stack *stb)
{
	size_t	i;

	if (stb->length > 0)
		return (0);
	i = 1;
	while (i < sta->length)
	{
		if (sta->bot[i - 1] < sta->bot[i])
			return (0);
		i++;
	}
	return (1);
}

static
uint8_t	read_commands(t_stack *sta, t_stack *stb)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd != NULL)
	{
		if (cmd[0] != 0 && cmd[1] != 0 && check_command(cmd))
		{
			ft_command(cmd, sta, stb);
			free(cmd);
		}
		else
		{
			free(cmd);
			write(2, "Error\n", 6);
			return (1);
		}
		cmd = get_next_line(STDIN_FILENO);
	}
	return (0);
}

static
void	initialize(t_stack *sta, t_stack *stb, size_t length)
{
	ft_memset(stb->bot, 0, MAX_SIZE * sizeof(int32_t));
	sta->length = length;
	sta->top = sta->bot + length - 1;
	stb->length = 0;
	stb->top = stb->bot;
}

int	main(int argc, char **argv)
{
	int32_t	array_a[MAX_SIZE];
	int32_t	array_b[MAX_SIZE];
	t_stack	sta;
	t_stack	stb;

	if (argc <= 1 || argc >= MAX_SIZE)
		return (0);
	ft_memset(array_a, 0, MAX_SIZE * sizeof(int32_t));
	if (parse_input(argv, argc, array_a, (size_t) argc - 1))
		return (1);
	sta.bot = array_a;
	stb.bot = array_b;
	initialize(&sta, &stb, (size_t) argc - 1);
	if (read_commands(&sta, &stb))
		return (1);
	if (is_sorted(&sta, &stb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
