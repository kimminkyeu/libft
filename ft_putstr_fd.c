/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:20:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/22 15:53:14 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern size_t	ft_strlen(const char *str);

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
