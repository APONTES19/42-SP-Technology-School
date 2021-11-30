int	ft_str_is_uppercase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 65 || str[c] > 90 ))
		{
			return (0);
		}
		c++;
	}
	return (1);
}
