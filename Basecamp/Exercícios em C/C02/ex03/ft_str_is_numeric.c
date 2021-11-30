int	ft_str_is_numeric(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 48 || str[c] > 57))
		{
			return (0);
		}
		c++;
	}
	return (1);
}
