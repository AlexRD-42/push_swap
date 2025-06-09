/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 17:55:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

size_t	ft_command(const char *cmd, t_stack *a, t_stack *b);
size_t	ft_sort(t_stack *sta, t_stack *stb);
void	ft_initialize(t_stack *sta, t_stack *stb, size_t length);
void	ft_binary_push(t_stack *dst, t_stack *src, t_med med, uint8_t *lut);
void	ft_push_cheapest(t_stack *sta, t_stack *stb);
int		parse_duplicates(int32_t *array, size_t length);
int		parse_input(char **argv, int argc, int32_t *array, size_t length);

void	ft_insertion_sort(int32_t *array, size_t length);
t_med	ft_get_median(int32_t *array, size_t length, uint8_t *lut);
size_t	ft_find_lis(t_stack *sta, uint8_t *lis_out);
void	ft_sort_five(t_stack *sta, t_stack *stb);

int64_t	i64_min(int64_t number1, int64_t number2);
int64_t	i64_max(int64_t number1, int64_t number2);
int64_t	i64_abs(int64_t number);
int64_t	i64_absdiff(int64_t number1, int64_t number2);
size_t	ft_get_max_index(int32_t *array, size_t length);
#endif