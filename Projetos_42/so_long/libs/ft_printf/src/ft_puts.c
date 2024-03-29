/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:17:44 by lucasmar          #+#    #+#             */
/*   Updated: 2021/11/14 16:22:31 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts(const char *s)
{
	int	count;

	if (s == NULL)
		return (ft_puts("(null)"));
	count = 0;
	while (s[count] != '\0')
	{
		ft_putc(s[count]);
		count++;
	}
	return (count);
}
