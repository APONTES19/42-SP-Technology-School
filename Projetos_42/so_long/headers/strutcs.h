/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 14:43:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	char	**str;
	size_t	line;
	size_t	columns;
	size_t		len;
	int		char_1;
	int		char_0;
	int		char_c;
	int		char_e;
	int		char_p;
	int		xp;
	int		yp;
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
	void	*mlx_img_1;
	void	*mlx_img_0;
	void	*mlx_img_C;
	void	*mlx_img_E;
	void	*mlx_img_P;
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
	int		fd;
	t_map		map;
	t_win		win;
	t_img		img;
	t_sprites	sprites;
	int			steps;
}	t_sl;
