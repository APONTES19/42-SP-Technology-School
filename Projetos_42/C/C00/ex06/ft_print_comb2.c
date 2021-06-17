#include <unistd.h>
void	ft_putchar_2(int b, int a);
void	ft_putchar_1(int a);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_putchar_1(a);
			ft_putchar_2(b, a);
			b++;
		}
		a++;
		b = a + 1;
	}
}

void	ft_putchar_1(int a)
{
	char	x;
	char	y;

	if (a <= 9)
	{
		x = 48;
		y = a + 48;
	}
	else
	{
		x = (a / 10) + 48;
		y = (a % 10) + 48;
	}
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, " ", 1);
}

void	ft_putchar_2(int b, int a)
{
	char	x;
	char	y;

	if (b <= 9)
	{
		x = 48;
		y = b + 48;
	}
	else
	{
		x = (b / 10) + 48;
		y = (b % 10) + 48;
	}
	if (a == 98 && b == 99)
	{
		write(1, &x, 1);
		write(1, &y, 1);
	}
	else
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, ", ", 2);
	}
}
