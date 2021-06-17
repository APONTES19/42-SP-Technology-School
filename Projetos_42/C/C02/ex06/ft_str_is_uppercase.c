#include <unistd.h>
#include <stdio.h>

void	ft_str_is_uppercase(void)
{
	char	b;

	b = '0';
	while (b <= 255)
	{
		printf ("%d", b);
		write (1, &b, 1);
		write (1,"\n", 1);
		b++;
	}
}

int main()
{
	ft_str_is_uppercase();
	return(0);
}
