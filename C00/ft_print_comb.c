#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}


void    ft_print_comb(void)
{
    int i;
    int j;
    int k;

    i = -1;
    while (i++ < 7)
    {
        j = i;
        while (j++ < 8)
        {
            k = j;
            while (k++ < 9)
            {
                ft_putchar(i + '0');
                ft_putchar(j + '0');
                ft_putchar(k + '0');
                if (i != 7)
                {
                    ft_putchar(',');
                    ft_putchar(' ');
                }
            }
        }
    }
}