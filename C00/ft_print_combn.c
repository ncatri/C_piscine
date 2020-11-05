#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	print(int *tab, int size)
{
	int i;

	i = -1;
	while (i++ < size - 1)
		ft_putchar(tab[i] + '0');
	if (tab[0] != 10 - size)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}	

void	combn(int n)
{
	int comb[9];
	int i;

	i = -1;
	while (i++ < n - 1)
		comb[i] = i;
	while (i >= 0)
	{
		print(comb, n);
		i = n - 1;
		while (i >= 0 && comb[i] == 10 - n + i)
			i--;
		if (i >= 0)
		{
			comb[i]++;
			while (i < n - 1)
			{
				comb[i + 1] = comb[i] + 1;
				i++;
			}
		}
	}
}

void	ft_print_combn(int n)
{
	if (n < 1 || n > 9)
		return ;
	else
		combn(n);
}
