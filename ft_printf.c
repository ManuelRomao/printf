# include "ft_printf.h"

int	ft_putchar(char	c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putperc(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putnmbr(int	i)
{
	int 	j;
	int		copy;
	char	*nmbr;

	j = 0;
	copy = i;
	while (copy / 10 > 0)
	{
		copy = copy / 10;
		j++;
	}
	nmbr = (char *) malloc(sizeof(char) * j);
	while (j >= 0)
	{
		nmbr[j] = i % 10 + 48;
		i = i / 10;
		j--;
	}
	free (nmbr);
	/* nmbr = calloc(j, sizeof(char)); */
	return (ft_putstr(nmbr));
}

int	ft_va_args(va_list args, const char fmt, int print_len)
{
	print_len = 0;
	if (fmt == '%')
		print_len += ft_putperc();
	else if (fmt == 'c')
		print_len += ft_putchar(va_arg(args, int));
	if (fmt == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (fmt == 'd' || fmt == 'i')
		print_len += ft_putnmbr(va_arg(args, int));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		print_len;

	va_start(args, str);
	print_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			print_len += ft_va_args(args, *str, 0);
		}
		else
			print_len += write(1, str, 1);
		++str;
	}
	va_end(args);
	return (print_len);
}

int	main	(void)
{
	int i, j;
	/* float	o; */
	char *str;

	i = 37122;
	j = 12;
	str = "My name is Manuel\n";
	/* o = 11.233444; */
	ft_printf("%s %s,\n feito?\n\n\n", "asdasd", str);
	printf("%i %s %i %s,\n feito?\n\n\n", i, str, i, str);
	/* printf("número é %%%%%d\n e a string é: %s,\n feito?\n\n\n%s", i, str, "O meu nome é Manuel\n\n\n\n");
	foo("\n\n\n%p\n\n\n", &str);
	printf("o: %f\n", o);
	printf("d: %d\n", i);*/
	/* printf("i: %c\n", i); */
	/* printf("p: %p\n", &str); */ 
	return (0);
}