char	upcase(char c)
{
	return ((c >= 'a' && c <= 'z') ? c - 32 : c);
}

char	lowcase(char c)
{
	return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

int		is_upcase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_lowcase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			str[i] = upcase(str[i]);
		else if (str[i - 1] == ' ' || str[i - 1] == '+' || str[i - 1] == '-')
			str[i] = upcase(str[i]);
		else
			str[i] = lowcase(str[i]);
		i++;
	}
	return (str);
}
