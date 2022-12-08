#include<stdio.h>
// int main()
// {
//     int tab = {12, 4, 58, 6, 48};
//     printf("%lu", sizeof(tab)/ sizeof(tab[0]));
// }
// size_t	ft_atoii(const char *str)
// {
// 	int		a;
// 	char	res;
// 	int		nb;

// 	a = 0;
// 	nb = 1;
// 	res = 0;
// 	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
// 		a++;
// 	if (str[a] == '-')
// 		nb *= -1;
// 	if (str[a] == '+' || str[a] == '-')
// 		a++;
// 	while (str[a] >= 48 && str[a] <= 57)
// 	{
// 		res *= 10;
// 		res = res + str[a] - 48;
// 		a++;
// 	}
// 	return (res * nb);
// }
// int main()
// {
//     printf("%zu", ft_atoii(""));
// }