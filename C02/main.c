#include <stdio.h>

char	*ft_strcapitalize(char *str);
void	ft_putstr_non_printable(char *str);

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("1 argument needed.\n");
		return (1);
	}
	else
	{
//		printf("%s\n", ft_strcapitalize(argv[1]));
		ft_putstr_non_printable(argv[1]);
		return (0);
	}
}
