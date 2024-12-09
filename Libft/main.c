#include <stdio.h>
#include <ctype.h>

int		ft_isalpha(int a);
int		ft_isdigit(int d);
int		ft_isalnum(int an);
int		ft_isascii(int as);
int		ft_isprint(int pr);
int		ft_strlen(char *s);
void	*ft_memset(void *str, int c, unsigned int n);
void	bzero(void *s, size_t n);

int	main(void)
{
	//ALPHA
	printf("\n\nIs alpha: %i TRUE\n", ft_isalpha('g'));
	printf("Is alpha: %i FALSE\n\n", ft_isalpha('0'));
	//DIGIT
	printf("Is digit: %i TRUE\n", ft_isdigit('9'));
	printf("Is digit: %i FALSE\n\n", ft_isdigit('*'));
	//ALPHANUMERIC
	printf("Is alnum: %i TRUE\n", ft_isalnum('i'));
	printf("Is alnum: %i TRUE\n", ft_isalnum('4'));
	printf("Is alnum: %i FALSE\n\n", ft_isalnum(')'));
	//ASCII
	printf("Is ascii: %i TRUE\n", ft_isascii('H'));
	printf("Is ascii: %i FALSE\n\n", ft_isascii(143)); //Å
	//PRINTABLE
	printf("Is printable: %i TRUE\n", ft_isprint(' '));
	printf("Is printable: %i FALSE\n\n", ft_isprint('\n'));
	//STRING LENGHT
	printf("String lenght: %i \n", ft_strlen("hol4s"));
	printf("String lenght: %i \n\n", ft_strlen("turtle"));
	//MEMORY SET
	char s[12] = "Hola a todos";
	printf("MEMSET\nString before: %s \n", s);
	ft_memset(s, 'A', 5);
	printf("String after: %s \n\n", s);
	int n[4] = {1, 20, 3, 4};
	printf("Size of array n = %li\n", sizeof(n));
	printf("List of numbers before: ");
	for (int i = 0; i < 4; i++) {
 		printf("%d ", n[i]);
	}
	printf("\n");
	ft_memset(n, 0, 8);
	printf("List of numbers after: ");
	for (int i = 0; i < 4; i++) {
 		printf("%d ", n[i]);
	}
	printf("\n\nBZERO");
	//BZERO
	printf("\nBefore Bzero: %s\n", s);
	bzero(s, 5);
	printf("After Bzero: %s\n", s);
}
