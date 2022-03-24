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

void	ft_chek_map(t_sl *sl)
{
	ft_create_string_map(sl);
	if (sl->map.line < 3)
		ft_error_map(6);
	if (sl->map.columns < 3)
		ft_error_map(7);
	if ((sl->map.columns * sl->map.line) != sl->map.len)
		ft_error_map(8);
	ft_count_char_map(sl);
	ft_valid_char_map(sl);
	//ft_valid_wall_map(sl);
	ft_printf("	▥ Valid map ✓\n");
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
	sl->map.len = ft_strlen(temp) - sl->map.line;
	//ft_printf("\nstring temp:\n%s",temp);
	sl->map.str = ft_split(temp,'\n');
	//ft_printf("linhas %d\n", sl->map.line);
	//ft_printf("colunas %d\n", sl->map.columns);
	//ft_printf("posição: %c\n",sl->map.str[0][4]);
	free(temp);
}

void	ft_count_char_map(t_sl *sl)
{
	size_t	x;
	size_t	y;
	sl->map.char_1 = 0;
	sl->map.char_0 = 0;
	sl->map.char_c = 0;
	sl->map.char_e = 0;
	sl->map.char_p = 0;

	y = 0;
	while (y < sl->map.line)
	{
		x = 0;
		while(x < sl->map.columns)
		{
			//ft_printf("%c", sl->map.str[y][x]);
			if (!(ft_strchr(D_VALID_CHAR, sl->map.str[y][x])))
					ft_error_map(10);
			if (sl->map.str[y][x] == '1')
				sl->map.char_1++;
			if (sl->map.str[y][x] == '0')
				sl->map.char_0++;
			if (sl->map.str[y][x] == 'C')
				sl->map.char_c++;
			if (sl->map.str[y][x] == 'E')
				sl->map.char_e++;
			if (sl->map.str[y][x] == 'P')
				sl->map.char_p++;
			x++;
		}
		//ft_printf("\n");
		y++;
	}
}

void	ft_valid_char_map(t_sl *sl)
{
	//ft_printf("1-%d | 0-%d | C %d | E %d | P %d",sl->map.char_1,sl->map.char_0,sl->map.char_c,sl->map.char_e,sl->map.char_p);
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
	size_t	count_line;
	size_t	count;

	count_line = 1;
	count = 0;
	while (count_line <= sl->map.line)
	{
		while ((count) < (sl->map.columns * count_line))
		{
			if ((count_line == 1) & (*sl->map.str[count] != '1'))
				ft_error_map(11);
			if ((count_line == sl->map.line) & (*sl->map.str[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line - sl->map.columns))
				& (*sl->map.str[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line -1))
				& (*sl->map.str[count] != '1'))
				ft_error_map(11);
			count ++;
		}
		count_line ++;
	}
}






















void	ft_valid_wall_map(t_sl *sl)
{
	size_t	count_line;
	size_t	count;

	count_line = 1;
	count = 0;
	while (count_line <= sl->map.line)
	{
		while ((count) < (sl->map.columns * count_line))
		{
			if ((count_line == 1) & (*sl->map.str[count] != '1'))
				ft_error_map(11);
			if ((count_line == sl->map.line) & (*sl->map.str[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line - sl->map.columns))
				& (*sl->map.str[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line -1))
				& (*sl->map.str[count] != '1'))
				ft_error_map(11);
			count ++;
		}
		count_line ++;
	}
}
