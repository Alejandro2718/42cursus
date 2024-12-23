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
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(const char *str, int search_str);
char	*ft_strrchr(const char *str, int chr);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

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
	const char sour[] = "Ejemplo";
	char des[] = "Destinosiou";
	printf("\nMY ft_memmove------------------\nBefore memmove:\nSource: %s\nDestination: %s\n", sour, des);
	ft_memmove(des, sour, 3);
	printf("\n\nAfter memmove:\nSource: %s\nDestination: %s\n", sour, des);

	const char sor[] = "Ejemplo";
	char ds[] = "Destinosiou";
	printf("\nORIGINAL\nBefore memmove:\nSource: %s\nDestination: %s\n", sor, ds);
	memmove(ds, sor, 3);
	printf("\n\nAfter memmove:\nSource: %s\nDestination: %s\n", sor, ds);

	//STRLCPY
	char tse[] = "Hello,World!";
    char test[8];
	size_t len = ft_strlcpy(test, tse, sizeof(test));
	printf("\nMY ft_strlcpy------------------\nDestination: %s\n", test);
    printf("Lenght: %zu\n", len);
	
	//STRLCAT
	char dst[12] = "Hello";
    char src[] = " World!";
    size_t nun = sizeof(dst);

    size_t lten = ft_strlcat(dst, src, nun);

    printf("\n\n\nDestino: %s\n", dst);
    printf("Longitud total: %zu\n", lten);

	char dst1[15] = "Hello";
    const char srrc[] = " World!";
    size_t result;

    // Caso 1
    result = ft_strlcat(dst1, srrc, sizeof(dst1));
    printf("\n\nCaso 1: %s (Longitud total: %zu)\n", dst1, result);

    // Caso 2
    char dst2[10] = "Hello";
    result = ft_strlcat(dst2, srrc, sizeof(dst2));
    printf("Caso 2: %s (Longitud total: %zu)\n", dst2, result);

    // Caso 3
    char dst3[10] = "Hello";
    result = ft_strlcat(dst3, srrc, 0);
    printf("Caso 3: %s (Longitud total: %zu)\n", dst3, result);

    // Caso 4
    char dst4[15] = "";
    result = ft_strlcat(dst4, srrc, sizeof(dst4));
    printf("Caso 4: %s (Longitud total: %zu)\n", dst4, result);

	// TOUPPER
	char upper = 'd';
	printf("\nMY ft_toupper------------------\nBefore: %c\n", upper);
	
	printf("\nAfter: %c", ft_toupper(upper));

	// TOLOWER
	char lower = 'R';
	printf("\nMY ft_tolower------------------\nBefore: %c\n", lower);
	
	printf("\nAfter: %c\n", ft_tolower(lower));

	// STRCHR
	const char *string = "Welcome to Tutorialspoint";
	char ch = 'e';

	char *pre = strchr(string, ch);

	printf("\nMY ft_strchr------------------\nString starting with %c is: %s\n", ch, pre);

	// STRRCHR

   	const char streng[] = "https://www.tutorialspoint.com";
   	const char che = '.';
   	char *ret;

   	ret = ft_strrchr(streng, che);

   	printf("\nMY ft_strrchr------------------\nString after %c is %s\n", che, ret);

	// STRNCMP
	char str1[15];
   	char str2[15];
   	int reto;
   	strcpy(str1, "abcde");
   	strcpy(str2, "abcdE");

	printf("\nMY ft_strncmp------------------\n");
   	reto = ft_strncmp(str1, str2, 3);
   	if(reto < 0) 
    	printf("str1 is less than str2");
   		else if(reto > 0) 
    		printf("str2 is less than str1");
   		else 
    		printf("str1 is equal to str2");
	printf("\n");

	// MEMCHR
	char myStr[] = "Hello World!";
  	char *myPtr = (char*)ft_memchr(myStr, 'o', 12);
  	if (myPtr != NULL) {
    	printf("\n%s\n", myPtr);
  	}

	// MEMCMP
	int arr1[] = {1, 2, 3, 4, 5};
  	int arr2[] = {1, 2, 3, 4, 5};

   	int esult = ft_memcmp(arr1, arr2, sizeof(arr1));
	printf("\nMY ft_memcmp------------------\n");
   	if (esult == 0) {
    	printf("Arrays are equal\n");
   	} else {
    	printf("Arrays are not equal\n");
   	}

	// STRNSTR
	printf("\n\nMY ft_strnstr------------------");
	char *frase = "Foo Bar Baz";
	char *peq = "Fo";
	char *coin = ft_strnstr(frase, peq, 11);
	printf("\nFound: %s\n", coin);

	// ATOI
}
