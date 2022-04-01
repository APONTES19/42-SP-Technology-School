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

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct s_map
{
	char	**str;
	size_t	line;
	size_t	columns;
	size_t	len;
	char	*map;
	char	*aux;
	char	*temp;
	int		char_1;
	int		char_0;
	int		char_c;
	int		char_e;
	int		char_p;
	int		xp;
	int		yp;
}			t_map;

typedef struct s_win
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
	void	*mlx_img_c;
	void	*mlx_img_e;
	void	*mlx_img_p;
	void	*mlx_img_b;
	int		x;
	int		y;
}	t_img;

typedef struct s_so_long
{
	int		fd;
	int		steps;
	size_t	ax;
	size_t	ay;
	int		aux;
	int		n;
	t_map	map;
	t_win	win;
	t_img	img;
}	t_sl;

#endif
