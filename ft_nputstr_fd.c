/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:33:21 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/12 20:40:39 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_nputstr_fd(const char *string, int fd, size_t n)
{
	size_t	idx;
	ssize_t	writed_bytes;

	idx = 0;
	while (idx < n)
	{
		writed_bytes = write(fd, &string[idx], n);
		if (writed_bytes < 0)
			return ;
		idx += writed_bytes;
	}
}
