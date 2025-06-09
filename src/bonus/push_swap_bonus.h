/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 17:20:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define MAX_SIZE 512
# include <stdint.h>
# include <stddef.h>

typedef struct s_stack
{
	int32_t	*bot;
	int32_t	*top;
	size_t	length;
}	t_stack;

typedef struct s_rots
{
	int64_t	src;
	int64_t	dst;
	int64_t	sum;
}	t_rots;

typedef struct s_median
{
	int32_t	upper;
	int32_t	middle;
	int32_t	lower;
}	t_med;

int64_t	ft_atoi(const char *num_str);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	*ft_memset(void *dst_void, const uint8_t byte, size_t length);
char	*get_next_line(int fd);
void	ft_command(const char *cmd, t_stack *a, t_stack *b);
int		parse_duplicates(int32_t *array, size_t length);
int		parse_input(char **argv, int argc, int32_t *array, size_t length);
#endif