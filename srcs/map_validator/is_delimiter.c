
int		is_delimiter(char c)
{
	if (c == ' ' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}