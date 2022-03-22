/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:59:09 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:16:46 by lucasmar         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_string_map(int fd, t_sl *sl)
{
	char	*line;
	char	*temp;

	sl->map.line = 0;
	sl->map.columns = 0;
	sl->map.string = ft_strdup("");
	if (sl->map.string == NULL)
		ft_error_map(5);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sl->map.line ++;
		if (sl->map.line == 1)
			sl->map.columns = ft_strlen(line) - 1;
		temp = sl->map.string;
		sl->map.string = *ft_split(ft_strjoin(temp, line), '\n');
		free (temp);
		temp = NULL;
		if (sl->map.string == NULL)
			ft_error_map(5);
	}
	ft_chek_map(sl);
}

void	ft_chek_map(t_sl *sl)
{
	if (sl->map.line < 3)
		ft_error_map(6);
	if (sl->map.columns < 3)
		ft_error_map(7);
	if ((sl->map.columns * sl->map.line) != ft_strlen(sl->map.string))
		ft_error_map(8);
	ft_char1_map(sl);
	ft_wall_map(sl);
	ft_printf("	▥ Valid map ✓\n\n");
}

void	ft_char1_map(t_sl *sl)
{
	int	count;

	count = 0;
	while (sl->map.string[count])
	{
		if (!(ft_strchr(D_VALID_CHAR, sl->map.string[count])))
					ft_error_map(10);
		if (sl->map.string[count] == '1')
			sl->map.char_1 ++;
		if (sl->map.string[count] == '0')
			sl->map.char_0 ++;
		if (sl->map.string[count] == 'C')
			sl->map.char_c ++;
		if (sl->map.string[count] == 'E')
			sl->map.char_e ++;
		if (sl->map.string[count] == 'P')
			sl->map.char_p ++;
		count++;
	}
	ft_char2_map(sl);
}

void	ft_char2_map(t_sl *sl)
{
	if (sl->map.char_1 < 1)
		ft_error_map(9);
	if (sl->map.char_0 < 1)
		ft_error_map(9);
	if (sl->map.char_c < 1)
		ft_error_map(9);
	if (sl->map.char_e < 1)
		ft_error_map(9);
	if (sl->map.char_p < 1)
		ft_error_map(9);
}

void	ft_wall_map(t_sl *sl)
{
	size_t	count_line;
	size_t	count;

	count_line = 1;
	count = 0;
	while (count_line <= sl->map.line)
	{
		while ((count) < (sl->map.columns * count_line))
		{
			if ((count_line == 1) & (sl->map.string[count] != '1'))
				ft_error_map(11);
			if ((count_line == sl->map.line) & (sl->map.string[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line - sl->map.columns))
				& (sl->map.string[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line -1))
				& (sl->map.string[count] != '1'))
				ft_error_map(11);
			count ++;
		}
		count_line ++;
	}
}
