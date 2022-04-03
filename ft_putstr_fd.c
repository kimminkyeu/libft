/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:20:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/03 10:32:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> /* for exit() */

/* NOTE : Dangerous if write() error occures!! */
extern size_t	ft_strlen(const char *str);

/** void	ft_putstr_fd(char *s, int fd)
  * {
  *     write(fd, s, ft_strlen(s));
  * } */

/* NOTE : Paritial write && write() error handling */
void	ft_putstr_fd(char *string, int fd)
{
	size_t	idx;
	size_t	len;
	ssize_t	writed_bytes;

	idx = 0;
	len = ft_strlen(string);
	while (idx < len)
	{
		writed_bytes = write(fd, &string[idx], len);
		if (writed_bytes < 0)
			exit(EXIT_FAILURE);
		idx += writed_bytes;
	}
}
