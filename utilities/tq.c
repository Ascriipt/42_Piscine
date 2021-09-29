
#include <libc.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	atoi;

	sign = 1;
	atoi = 0;
	while (*str == ' ' || *str == '\n'
		|| *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + (*str - 48);
		str++;
	}
	return (atoi * sign);
}

int	ft_tq(char *base, int x, int n, int np)
{
	int	bn;
	int	bnp;

	bn = base[n] - '0';
	bnp = base[np] - '0';
	printf("x=%d\nbn=%d\nbnp=%d\n", x, bn, bnp);
	if (n == np)
		return (n);
	if (bn == bnp)
		return (n);
	if ((bn > bnp && n < np)
		|| (bn < bnp && n > np))
	{
		if (bn == bnp - x)
			return (bnp - x);
		return (20);
	}
	else
	{
		if (bn == bnp + x)
			return (bnp + x);
		return (20);
	}
	return (bnp + x);
}

/*int	ft_tq2(char *base, int n, int np)
{
	int	x;
	int	bn;
	int	bnp;
	int	bn;

	x = np - n;
	bn = base[n] - '0';
	bnp = base[np] - '0';
	bn = base[n + x] - '0';
	printf("x=%d\nbn=%d\nbnp=%d\nbn=%d\n", x, bn, bnp, bn);
	if (n == np)
		return (bn);
	if (bn == bnp)
		return (bn);
	if (bn < bnp)
		return (bn + x);
	if (bn > bnp)
		return (bn - x);
	return (-1);
}*/

int	main(int argc, char **argv)
{
	(void)argc;
	int n;
	int np;
	int	x;

	n = ft_atoi(argv[2]);
	np = ft_atoi(argv[3]);
	x = np - n;
	printf("%d\n", ft_tq(argv[1], x, n, np));
	return (0);
}
