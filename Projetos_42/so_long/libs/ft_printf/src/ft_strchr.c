/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:53:03 by lucasmar          #+#    #+#             */
/*   Updated: 2021/11/10 15:40:40 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != (unsigned char)ch)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
