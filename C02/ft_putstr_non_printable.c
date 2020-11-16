#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int		is_printable(char c)
{
	return (c >= 32 && c < 127);
}

void	print_hexa(char c)
{
	int digit1;
	int digit2;

	ft_putchar('\\');
	digit1 = c / 16;
	ft_putchar((digit1 > 9) ? digit1 + 87 : digit1 + '0');
	digit2 = c % 16;
	ft_putchar((digit2 > 9) ? digit2 + 87 : digit2 + '0');
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
			ft_putchar(*str);
		else
			print_hexa(*str);
		str++;
	}
}
