/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:10:48 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 16:35:27 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_sl	sl;

	ft_check_input(argc, argv[1], &sl);
	ft_chek_map(&sl);
	ft_init_win(&sl);
	return (0);
}

void	ft_check_input(int argc, char *str, t_sl *sl)
{
	if (argc < 2)
		ft_error_input(1);
	if (argc > 2)
		ft_error_input(2);
	if (ft_strncmp(&str[ft_strlen(str) - 4], D_EXT_MAP, 4))
		ft_error_input(3);
	sl->fd = open(str, O_RDONLY);
	if (sl->fd == -1)
		ft_error_input(4);
	ft_printf("\n	▥ valid arguments ✓\n");
}
