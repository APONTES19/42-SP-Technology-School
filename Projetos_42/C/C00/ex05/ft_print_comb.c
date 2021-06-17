#include <unistd.h>
void	print(int p_1, int p_2, int p_3);

void	ft_print_comb(void)
{
	int	position[3];

	position[0] = '0';
	position[1] = '1';
	position[2] = '2';
	while (position[0] <= '7')
	{	
		while (position[1] <= '8')
		{
			while (position[2] <= '9')
			{
				print(position[0], position[1], position[2]);
				position[2]++;
			}
			position[1]++;
			position[2] = position[1] + 1;
		}
		position[0]++;
		position[1] = position[0] + 1;
		position[2] = position[1] + 1;
	}
}

void	print(int p_1, int p_2, int p_3)
{	
	if (p_1 != '7')
	{
		write(1, &p_1, 1);
		write(1, &p_2, 1);
		write(1, &p_3, 1);
		write(1, ", ", 2);
	}
	else
	{
		write(1, &p_1, 1);
		write(1, &p_2, 1);
		write(1, &p_3, 1);
	}
}
