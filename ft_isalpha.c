#include <stdio.h>

int ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main(void)
{
	char *str = "Hello, World!";

	while (*str)
	{
		if (ft_isalpha(*str))
			printf("Character '%c' is an alphabetic character.\n", *str);
		else
			printf("Character '%c' is not an alphabetic character.\n", *str);
		str++;
	}
	return 0;
}
