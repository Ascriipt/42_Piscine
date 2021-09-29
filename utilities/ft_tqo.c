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

int	ft_tq(char *base, int n, int np)
{
	int	x;
	int	bn;
	int	bnp;
	int	bx;

	x = np - n;
	bn = base[n] - '0';
	bnp = base[np] - '0';
	bx = base[n + x] - '0';
	printf("x=%d\nbn=%d\nbnp=%d\nbx=%d\n", x, bn, bnp, bx);
	if (n == np)
		return (bn);
	if (bn == bnp)
		return (bn);
	if (bn > bnp)
		return (bx + x);
	if (bn < bnp)
		return (bx - x);
	return (-1);
}

int	ft_tq2(char *base, int n, int np)
{
	int	x;
	int	bn;
	int	bnp;
	int	bx;

	x = np - n;
	bn = base[n] - '0';
	bnp = base[np] - '0';
	bx = base[n + x] - '0';
	printf("x=%d\nbn=%d\nbnp=%d\nbx=%d\n", x, bn, bnp, bx);
	if (n == np)
		return (bn);
	if (bn == bnp)
		return (bn);
	if (bn < bnp)
		return (bx + x);
	if (bn > bnp)
		return (bx - x);
	return (-1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (ft_atoi(argv[2]) <= ft_atoi(argv[3]))
		printf("%d\n", ft_tq(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3])));
	else
		printf("%d\n", ft_tq2(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3])));
	return (0);
}
