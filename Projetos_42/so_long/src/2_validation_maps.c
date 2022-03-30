/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:59:09 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:16:46 by lucasmar         ###   ########->fr      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chek_map(t_sl *sl)
{
	ft_create_string_map(sl);
	if (sl->map.line < 3)
		ft_error_map(6);
	if (sl->map.columns < 3)
		ft_error_map(7);
	if ((sl->map.columns * sl->map.line) != sl->map.len)
		ft_error_map(8);
	sl->map.char_1 = 0;
	sl->map.char_0 = 0;
	sl->map.char_c = 0;
	sl->map.char_e = 0;
	sl->map.char_p = 0;
	ft_count_char_map(sl);
	ft_valid_char_map(sl);
	ft_valid_wall_map(sl);
	ft_check_p(sl);
	ft_printf("	Valid map ✓\n");
	close(sl->fd);
}

void	ft_create_string_map(t_sl *sl)
{
	char	*line;
	char	*temp;

	sl->map.line = 0;
	sl->map.columns = 0;
	temp = ft_strdup("");
	if (temp == NULL)
		ft_error_map(5);
	while (1)
	{
		line = get_next_line(sl->fd);
		if (line == NULL)
			break ;
		sl->map.line ++;
		if (sl->map.line == 1)
			sl->map.columns = ft_strlen(line) - 1;
		temp = ft_strjoin(temp, line);
		free (line);
		if (temp == NULL)
			ft_error_map(5);
	}
	sl->map.len = (sl->map.line * sl->map.columns);
	sl->map.str = ft_split(temp, '\n');
	free (temp);
}

void	ft_count_char_map(t_sl *sl)
{
	sl->ay = 0;
	while (sl->ay < sl->map.line)
	{
		sl->ax = 0;
		while (sl->ax < sl->map.columns)
		{
			if (!(ft_strchr(D_VALID_CHAR, sl->map.str[sl->ay][sl->ax])))
				ft_error_map (10);
			if (sl->map.str[sl->ay][sl->ax] == '1')
				sl->map.char_1++;
			if (sl->map.str[sl->ay][sl->ax] == '0')
				sl->map.char_0++;
			if (sl->map.str[sl->ay][sl->ax] == 'C')
				sl->map.char_c++;
			if (sl->map.str[sl->ay][sl->ax] == 'E')
				sl->map.char_e++;
			if (sl->map.str[sl->ay][sl->ax] == 'P')
				sl->map.char_p++;
			sl->ax++;
		}
		sl->ay++;
	}
}

void	ft_valid_char_map(t_sl *sl)
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

void	ft_valid_wall_map(t_sl *sl)
{
	sl->ay = 0;
	while (sl->ay < sl->map.line)
	{
		sl->ax = 0;
		while (sl->ax < sl->map.columns)
		{
			if ((sl->ay == 0 || sl->ay == (sl->map.line -1))
				& (sl->map.str[sl->ay][sl->ax] != '1'))
				ft_error_map(11);
			else if ((sl->ax == 0 || sl->ax == (sl->map.columns -1))
				& (sl->map.str[sl->ay][sl->ax] != '1'))
				ft_error_map(11);
			sl->ax++;
		}
		sl->ay++;
	}
}

void	ft_check_p(t_sl *sl)
{
	sl->ay = 0;
	while (sl->ay < sl->map.line)
	{
		sl->ax = 0;
		while (sl->ax < sl->map.columns)
		{
			if (sl->map.str[sl->ay][sl->ax] == 'P')
			{
				sl->map.xp = sl->ax;
				sl->map.yp = sl->ay;
			}
			sl->ax++;
		}
		sl->ay++;
	}
}