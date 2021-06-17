void	ft_rev_int_tab(int *tab, int size)
{	
	int	a[10];
	int	c;

	c = 0;
	while (c < size)
	{
		a[c] = *(tab + c);
		c++;
	}
	c = 0;
	while (c < size)
	{
		*(tab + c) = a[size - c - 1];
		c++;
	}
}
