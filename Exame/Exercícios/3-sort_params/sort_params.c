/*
Escreva um programa que exiba os argumentos recebidos na linha de comando classificados em ordem ASCII. 
Cada argumento deve estar em uma linha separada. Se nenhum argumento for passado para o programa, exiba uma nova linha.

Exemplos:

$>./ft_sort_params ga bu zo | cat -e
bu$
ga$
zo$
$>./ft_sort_params | cat -e
$
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		ft_putchar(str[idx++]);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && (s1[idx] != '\0' || s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char **argv)
{
	int	start;
	int	idx;

	start = 1;
	while (start < argc - 1)
	{
		idx = 1;
		while (idx < argc - 1)
		{
			if (ft_strcmp(argv[idx], argv[idx + 1]) > 0)
				ft_swap_str(&argv[idx], &argv[idx + 1]);
			idx++;
		}
		start++;
	}
	start = 1;
	while (start < argc)
	{
		ft_putstr(argv[start]);
		ft_putchar('\n');
		start++;
	}
	return (0);
}