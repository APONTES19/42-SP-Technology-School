char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	size;

	size = 0;
	while ((src[size] != '\0') && (size < n))
	{
		dest[size] = src[size];
		size++;
	}
	while (size < n)
	{
		dest[size] = '\0';
		size++;
	}
	return (dest);
}
