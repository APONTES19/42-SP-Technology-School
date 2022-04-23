/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:27:18 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/22 14:24:29 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

void	ft_error_arg(int n)
{
	char	*msg;

	msg = NULL;
	if (n == 1)
		msg = "	Argument number other than 4!";
	if (n == 2)
		msg = "	Error the infile!";
	if (n == 3)
		msg = "	Error the outfile!";
	if (n == 4)
		msg = "	Error in argument 2 command 1 'cmd1'";
	if (n == 5)
		msg = "	Error in system PATH not found!";
	write(1,"\033[0;31m \n       (error x",24);
	ft_printf("%d",n);
	write(1,") Argument error!\n\n",20);
	ft_printf("%s", msg);
	write(1,"\033[0;31 \n	CCheck the argument and try again!\n\n\033[0m",45);
	exit(EXIT_FAILURE);
}
