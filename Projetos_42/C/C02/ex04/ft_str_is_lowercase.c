int	ft_str_is_lowercase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 66 || str[c] > 122))
		{
			return (0);
		}
		c++;
	}
	return (1);
}
