#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 16

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void    print_hexa(char c, unsigned int i, char *str)
{
	int digit1;
	int digit2;

	digit1 = c / 16;
	ft_putchar((digit1 > 9) ? digit1 + 87 : digit1 + '0');
	digit2 = c % 16;
	ft_putchar((digit2 > 9) ? digit2 + 87 : digit2 + '0');
	if (i % 2 == 1)
		ft_putchar(' ');
	if (c > 31 && c < 127)
		str[i % LEN] = c;
	else
		str[i % LEN] = '.';
}

void	print_addr(unsigned long addr)
{
	if (addr < 16)
		ft_putchar(addr > 9 ? addr + 87 : addr + '0');
	else
	{
		print_addr(addr / 16);
		ft_putchar((addr % 16 > 9) ? addr % 16 + 87 : addr % 16 + '0');
	}
}

void	initialize_str(char *str, int n)
{
	while (n >= 0)
		str[n--] = 0;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			c;
	char			str[LEN + 1];
	unsigned int	count;

	i = -1;
	count = 0;
	while (++i < size)
	{
		if (i  % LEN == 0)
		{
			print_addr((unsigned long)(addr + i));
			write(1, ": ", 2);
			initialize_str(str, LEN);
		}
		c = *((char*)addr + i);
		print_hexa(c, i, str);
		if (++count % LEN == 0 || i == size - 1)
		{
			while (count % LEN != 0)
			{
				ft_putstr("  ");
				count++;
			}
			ft_putstr(str);
			ft_putchar('\n');
		}
	}
	return (addr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("needs second argument: 's' or 'h'\n");
		return (0);
	}
	char str[] = "Bonjour les aminches\t\n\nc est fou\ttout\ncd qu on peut faire avec\v\t\nprint_memory\v\v\t\nlol\rlol\t .";
	if (strcmp(argv[1],"s") == 0)
	{
		char str1[100];
		char str2[100];

		printf("**** memory allocation in the stack ****\n\n");
		ft_print_memory(strcpy(str1, str), ft_strlen(str));
		ft_putchar('\n');
		ft_print_memory(strcpy(str2, str), ft_strlen(str));
		ft_putchar('\n');
	}
	else if (strcmp(argv[1], "h") == 0)
	{
		printf("**** memory allocation in the heap ****\n\n");
		ft_print_memory(strdup(str), ft_strlen(str));
		ft_putchar('\n');
		ft_print_memory(strdup(str), ft_strlen(str));
		ft_putchar('\n');
	}
	else
	{
		printf("needs second argument to be: 's' or 'h'\n");
		return (0);
	}
	return (0);
}
