/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:44:02 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 12:39:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

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
	while (i < sta->length && sta->bot[i - 1] < sta->bot[i])
		i++;
	return (i == sta->length);
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
			return (1);
		}
		cmd = get_next_line(STDIN_FILENO);
	}
	return (!is_sorted(sta, stb));
}

int checker(int argc, char **argv)
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
	if (read_commands(&sta, &stb))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}
