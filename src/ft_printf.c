/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:58:36 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/01 20:46:54 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	int		done;

	va_start(argp, fmt);
	done = ft_vprintf(fmt, argp);
	va_end(argp);
	return (done);
}
