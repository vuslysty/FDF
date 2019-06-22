int		ft_count_char(char *str, char c)
{
	int		i = 0;

	while (*str != '\0')
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}