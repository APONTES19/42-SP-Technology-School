/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:43:21 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/16 10:59:36 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		c ;
	int		len_str;
	char	*pointer;

	pointer = NULL;
	c = 0;
	len_str = ft_strlen((char *)str);
	if (ch == '\0')
		return ((char *)str + len_str);
	while (*str != '\0')
	{
		if (*str == ch)
			pointer = ((char *)str);
		str++;
	}
	return (pointer);
}
