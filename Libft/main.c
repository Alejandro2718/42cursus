#include <stdio.h>
#include <ctype.h>
#include <string.h>

int		ft_isalpha(int a);
int		ft_isdigit(int d);
int		ft_isalnum(int an);
int		ft_isascii(int as);
int		ft_isprint(int pr);
int		ft_strlen(char *s);
void	*ft_memset(void *str, int c, unsigned int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	//ALPHA
	printf("\nMY ft_isalpha---------\nIs alpha: %i TRUE\n", ft_isalpha('g'));
	printf("Is alpha: %i FALSE\n\n", ft_isalpha('0'));

	printf("ORIGINAL\nIs alpha: %i TRUE\n", isalpha('g'));
	printf("Is alpha: %i FALSE\n\n", isalpha('0'));
	//DIGIT
	printf("MY ft_isdigit---------\nIs digit: %i TRUE\n", ft_isdigit('9'));
	printf("Is digit: %i FALSE\n\n", ft_isdigit('*'));

	printf("ORIGINAL\nIs digit: %i TRUE\n", isdigit('9'));
	printf("Is digit: %i FALSE\n\n", isdigit('*'));
	//ALPHANUMERIC
	printf("MY ft_isalnum---------\nIs alnum: %i TRUE\n", ft_isalnum('i'));
	printf("Is alnum: %i TRUE\n", ft_isalnum('4'));
	printf("Is alnum: %i FALSE\n\n", ft_isalnum(')'));

	printf("ORIGINAL\nIs alnum: %i TRUE\n", isalnum('i'));
	printf("Is alnum: %i TRUE\n", isalnum('4'));
	printf("Is alnum: %i FALSE\n\n", isalnum(')'));
	//ASCII
	printf("MY ft_isascii---------\nIs ascii: %i TRUE\n", ft_isascii('H'));
	printf("Is ascii: %i FALSE\n\n", ft_isascii(143)); //Å

	printf("ORIGINAL\nIs ascii: %i TRUE\n", isascii('H'));
	printf("Is ascii: %i FALSE\n\n", isascii(143)); //Å
	//PRINTABLE
	printf("My ft_isprint---------\nIs printable: %i TRUE\n", ft_isprint(' '));
	printf("Is printable: %i FALSE\n\n", ft_isprint('\n'));

	printf("ORIGINAL\nIs printable: %i TRUE\n", isprint(' '));
	printf("Is printable: %i FALSE\n\n", isprint('\n'));
		
	//STRING LENGHT
	printf("MY ft_strlen---------\nString lenght: %i \n", ft_strlen("hol4s"));
	printf("String lenght: %i \n\n", ft_strlen("turtle"));

	printf("ORIGINAL\nString lenght: %li \n", strlen("hol4s"));
	printf("String lenght: %li \n\n", strlen("turtle"));
	//MEMORY SET
	char s[] = "Hola a todos";
	printf("My ft_memset---------\nString before: %s \n", s);
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


	char p[] = "Hola a todos";
	printf("\n\nORIGINAL\nString before: %s \n", p);
	memset(p, 'A', 5);
	printf("String after: %s \n\n", p);
	int m[4] = {1, 20, 3, 4};
	printf("Size of array n = %li\n", sizeof(m));
	printf("List of numbers before: ");
	for (int i = 0; i < 4; i++) {
 		printf("%d ", m[i]);
	}
	printf("\n");
	ft_memset(m, 0, 8);
	printf("List of numbers after: ");
	for (int i = 0; i < 4; i++) {
 		printf("%d ", m[i]);
	}
	//BZERO
	char t[6] = "Zabka";
	printf("\n\nMy ft_bzero------------------\nBefore Bzero: %s\n", t);
	ft_bzero(t, 3);
	printf("After Bzero: ");
	for (int j = 0; j < 6; j++)
	{
		printf("%c", t[j]);
	}
	printf("\n");

	char y[6] = "Zabka";
	printf("\n\nORIGINAL\nBefore Bzero: %s\n", y);
	bzero(y, 3);
	printf("After Bzero: ");
	for (int j = 0; j < 6; j++)
	{
		printf("%c", y[j]);
	}
	printf("\n");
	//MEMCPY
	const char r[] = "Prove";
	char e[] = "destination";
	
	printf("\nMY ft_memcpy------------------\nBefore memcpy:\nSource: %s\nDestination: %s\n", r, e);
	ft_memcpy(e, r, 5);
	printf("\n\nAfter memcpy:\nSource: %s\nDestination: %s\n", r, e);

	const char pt[] = "Prove";
	char o[] = "destination";
	printf("\nORIGINAL\nBefore memcpy:\nSource: %s\nDestination: %s\n", pt, o);
	memcpy(o, pt, 5);
	printf("\n\nAfter memcpy:\nSource: %s\nDestination: %s\n", pt, o);
	//MEMMOVE
	
}
