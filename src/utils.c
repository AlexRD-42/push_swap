/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:34:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/15 11:53:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
// Prevent overflows? Checking number length would require a pre processing step
int64_t	ft_atoi(const char *num_str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	sign = -1;
	while (*num_str == ' ' || (*num_str >= '\t' && *num_str <= '\v'))
		num_str++;
	if (*num_str == '-')
	{
		num_str++;
		sign = -sign;
	}
	else if (*num_str == '+')
		num_str++;
	while (*num_str >= '0' && *num_str <= '9')
		number = number * 10 - (*num_str++ - '0');
	return (sign * number);
}

static void	*ft_memrcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = ((const char *) src_void) + length;

	dst = ((char *) dst_void) + length;
	while (length > sizeof(int *) && ((uintptr_t)dst & (sizeof(int *) - 1)))
	{
		*--dst = *--src;
		length--;
	}
	while (length >= sizeof(int *))
	{
		dst -= sizeof(int *);
		src -= sizeof(int *);
		length -= sizeof(int *);
		*((uintptr_t *)dst) = *((uintptr_t *)src);
	}
	while (length > 0)
		*--dst = *--src;
	return (dst_void);
}

void	*ft_memcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void > (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src_void, length));
	else if ((uintptr_t) dst_void < (uintptr_t) src_void)
	{
		dst = (char *) dst_void;
		while (length > sizeof(int *) && ((uintptr_t)dst & (sizeof(int *) - 1)))
		{
			*dst++ = *src++;
			length--;
		}
		while (length >= sizeof(int *))
		{
			*((uintptr_t *)dst) = *((uintptr_t *)src);
			dst += sizeof(int *);
			src += sizeof(int *);
			length -= sizeof(int *);
		}
		while (length-- > 0)
			*dst++ = *src++;
	}
	return (dst_void);
}

void	ft_putnbr(int64_t n, int fd)
{
	const int8_t	sign = (n >= 0) - (n < 0);
	char			array[21];
	char			*ptr;

	if (fd == -1)
		return ;
	ptr = array + 20;
	*ptr = 0;
	*(--ptr) = sign * (n % 10) + '0';
	n = sign * (n / 10);
	while (n != 0)
	{
		*(--ptr) = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*(--ptr) = '-';
	write(fd, ptr, array + 20 - ptr);
}
