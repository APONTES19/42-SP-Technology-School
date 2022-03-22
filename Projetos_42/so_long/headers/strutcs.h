/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/17 10:17:01 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	char	*string;
	size_t	line;
	size_t	columns;
	int		char_1;
	int		char_0;
	int		char_c;
	int		char_e;
	int		char_p;
}			t_map;

typedef	struct s_win
{
	void	*ptr;
	void	*scr;
	int		x;
	int		y;
}	t_win;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_sprites
{
	t_img	back;
	t_img	wall;
	t_img	exit;

}	t_sprites;


typedef struct s_so_long
{
	t_map		map;
	t_win		win;
	t_img		img;
	t_sprites	sprites;
}	t_sl;
