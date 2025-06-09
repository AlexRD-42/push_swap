/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:07:58 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 11:51:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

static
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	const char	*osrc = src;

	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src != 0)
		src++;
	return (src - osrc);
}

static
void	*ft_bytecpy(void *dst_void, const void *src_void, size_t size)
{
	char		*dst;
	const char	*src;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (dst == src)
		return (dst_void);
	while (size > 0)
	{
		*dst++ = *src++;
		size--;
	}
	return (dst_void);
}

static
void	*ft_realloc(void *src, size_t src_size, size_t dst_size)
{
	void	*dst;

	dst = (void *) malloc (dst_size);
	if (dst != NULL)
	{
		*((unsigned char *) dst) = 0;
		if (src != NULL)
			ft_bytecpy(dst, src, src_size);
	}
	free(src);
	return (dst);
}

static
ssize_t	ft_read(int fd, char *buffer, size_t *end, char **str)
{
	ssize_t	bytes_read;

	if (fd < 0 || 1024 <= 0)
		return (0);
	if (*buffer == 0)
	{
		bytes_read = read(fd, buffer, 1024);
		if (bytes_read < 0)
		{
			free(*str);
			*str = NULL;
		}
		else
			*end = (size_t) bytes_read;
	}
	else
	{
		bytes_read = 0;
		while (buffer[bytes_read] != 0)
			bytes_read++;
		*end = bytes_read;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024] = {0};
	char		*str;
	size_t		i;
	size_t		end;
	size_t		len;

	str = NULL;
	len = 0;
	while (ft_read(fd, buffer, &end, &str) > 0)
	{
		i = 0;
		while (i < end && buffer[i] != 0 && buffer[i] != '\n')
			i++;
		i += (i < end && buffer[i] == '\n');
		str = ft_realloc(str, len, len + i + 1);
		if (str == NULL)
			break ;
		ft_strlcpy(str + len, buffer, i + 1);
		len += i;
		end -= i;
		ft_strlcpy(buffer, buffer + i, end + 1);
		if (str[len - 1] == '\n')
			break ;
	}
	return (str);
}
