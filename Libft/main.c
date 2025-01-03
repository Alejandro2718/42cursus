#include "libft.h"
#include <stdio.h>

char	addOne(unsigned int i, char c)
{
	return (i + c);
}

int	main(void)
{
	char		s[] = "Hola a todos";
	int			n[4] = {1, 20, 3, 4};
	char		p[] = "Hola a todos";
	int			m[4] = {1, 20, 3, 4};
	char		t[6] = "Zabka";
	char		y[6] = "Zabka";
	const char	r[] = "Prove";
	char		e[] = "destination";
	const char	pt[] = "Prove";
	char		o[] = "destination";
	const char	sour[] = "Ejemplo";
	char		des[] = "Destinosiou";
	const char	sor[] = "Ejemplo";
	char		ds[] = "Destinosiou";
	char		tse[] = "Hello,World!";
	char		test[8];
	size_t		len;
	char		dst[12] = "Hello";
	char		src[] = " World!";
	size_t		nun;
	size_t		lten;
	char		dst1[15] = "Hello";
	const char	srrc[] = " World!";
	size_t		result;
	char		dst2[10] = "Hello";
	char		dst3[10] = "Hello";
	char		dst4[15] = "";
	char		upper;
	char		lower;
	const char	*string = "Welcome to Tutorialspoint";
	char		ch;
	char		*pre;
	const char	streng[] = "https://www.tutorialspoint.com";
	const char	che = '.';
	char		*ret;
	char		str1[15];
	char		str2[15];
	int			reto;
	char		myStr[] = "Hello World!";
	char		*myPtr;
	int			arr1[] = {1, 2, 3, 4, 5};
	int			arr2[] = {1, 2, 3, 4, 5};
	int			esult;
	char		*frase;
	char		*peq;
	char		*coin;
	char		*numb;
	int			yesul;
	size_t		ne;
	int			*arr;
	const char	*orginal = "Hello, World!";
	char		*duplicated;
	char const	*origin;
	char		*self;
	char		*resilt;
	char		*sre;
	char		**arrayes;
	char		*si;
	char		c;
	char		**rsult;
	char		*mou;
	char		*mous;

	// ALPHA
	printf("\nMY ft_isalpha---------\nIs alpha: %i TRUE\n", ft_isalpha('g'));
	printf("Is alpha: %i FALSE\n\n", ft_isalpha('0'));
	printf("ORIGINAL\nIs alpha: %i TRUE\n", isalpha('g'));
	printf("Is alpha: %i FALSE\n\n", isalpha('0'));
	// DIGIT
	printf("MY ft_isdigit---------\nIs digit: %i TRUE\n", ft_isdigit('9'));
	printf("Is digit: %i FALSE\n\n", ft_isdigit('*'));
	printf("ORIGINAL\nIs digit: %i TRUE\n", isdigit('9'));
	printf("Is digit: %i FALSE\n\n", isdigit('*'));
	// ALPHANUMERIC
	printf("MY ft_isalnum---------\nIs alnum: %i TRUE\n", ft_isalnum('i'));
	printf("Is alnum: %i TRUE\n", ft_isalnum('4'));
	printf("Is alnum: %i FALSE\n\n", ft_isalnum(')'));
	printf("ORIGINAL\nIs alnum: %i TRUE\n", isalnum('i'));
	printf("Is alnum: %i TRUE\n", isalnum('4'));
	printf("Is alnum: %i FALSE\n\n", isalnum(')'));
	// ASCII
	printf("MY ft_isascii---------\nIs ascii: %i TRUE\n", ft_isascii('H'));
	printf("Is ascii: %i FALSE\n\n", ft_isascii(143)); //Å
	printf("ORIGINAL\nIs ascii: %i TRUE\n", isascii('H'));
	printf("Is ascii: %i FALSE\n\n", isascii(143)); //Å
	// PRINTABLE
	printf("My ft_isprint---------\nIs printable: %i TRUE\n", ft_isprint(' '));
	printf("Is printable: %i FALSE\n\n", ft_isprint('\n'));
	printf("ORIGINAL\nIs printable: %i TRUE\n", isprint(' '));
	printf("Is printable: %i FALSE\n\n", isprint('\n'));
	// STRING LENGHT
	printf("MY ft_strlen---------\nString lenght: %zu \n", ft_strlen("hol4s"));
	printf("String lenght: %zu \n\n", ft_strlen("turtle"));
	printf("ORIGINAL\nString lenght: %li \n", strlen("hol4s"));
	printf("String lenght: %li \n\n", strlen("turtle"));
	// MEMORY SET
	printf("My ft_memset---------\nString before: %s \n", s);
	ft_memset(s, 'A', 5);
	printf("String after: %s \n\n", s);
	printf("Size of array n = %li\n", sizeof(n));
	printf("List of numbers before: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", n[i]);
	}
	printf("\n");
	ft_memset(n, 0, 8);
	printf("List of numbers after: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", n[i]);
	}
	printf("\n\nORIGINAL\nString before: %s \n", p);
	memset(p, 'A', 5);
	printf("String after: %s \n\n", p);
	printf("Size of array n = %li\n", sizeof(m));
	printf("List of numbers before: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", m[i]);
	}
	printf("\n");
	ft_memset(m, 0, 8);
	printf("List of numbers after: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", m[i]);
	}
	// BZERO
	printf("\n\nMy ft_bzero------------------\nBefore Bzero: %s\n", t);
	ft_bzero(t, 3);
	printf("After Bzero: ");
	for (int j = 0; j < 6; j++)
	{
		printf("%c", t[j]);
	}
	printf("\n");
	printf("\n\nORIGINAL\nBefore Bzero: %s\n", y);
	bzero(y, 3);
	printf("After Bzero: ");
	for (int j = 0; j < 6; j++)
	{
		printf("%c", y[j]);
	}
	printf("\n");
	// MEMCPY
	printf("\nMY ft_memcpy------------------\nBefore memcpy:\nSource:%s\nDestination:%s\n",
		r, e);
	ft_memcpy(e, r, 5);
	printf("\n\nAfter memcpy:\nSource: %s\nDestination: %s\n", r, e);
	printf("\nORIGINAL\nBefore memcpy:\nSource: %s\nDestination: %s\n", pt, o);
	memcpy(o, pt, 5);
	printf("\n\nAfter memcpy:\nSource: %s\nDestination: %s\n", pt, o);
	// MEMMOVE
	printf("\nMY ft_memmove------------------\nBefore memmove:\nSource:	%s\nDestination:	%s\n",
				sour, des);
	ft_memmove(des, sour, 3);
	printf("\n\nAfter memmove:\nSource: %s\nDestination: %s\n", sour, des);
	printf("\nORIGINAL\nBefore memmove:\nSource: %s\nDestination: %s\n", sor,
		ds);
	memmove(ds, sor, 3);
	printf("\n\nAfter memmove:\nSource: %s\nDestination: %s\n", sor, ds);
	// STRLCPY
	len = ft_strlcpy(test, tse, sizeof(test));
	printf("\nMY ft_strlcpy------------------\nDestination: %s\n", test);
	printf("Lenght: %zu\n", len);
	// STRLCAT
	nun = sizeof(dst);
	lten = ft_strlcat(dst, src, nun);
	printf("\n\n\nDestino: %s\n", dst);
	printf("Longitud total: %zu\n", lten);
	// Caso 1
	result = ft_strlcat(dst1, srrc, sizeof(dst1));
	printf("\n\nCaso 1: %s (Longitud total: %zu)\n", dst1, result);
	// Caso 2
	result = ft_strlcat(dst2, srrc, sizeof(dst2));
	printf("Caso 2: %s (Longitud total: %zu)\n", dst2, result);
	// Caso 3
	result = ft_strlcat(dst3, srrc, 0);
	printf("Caso 3: %s (Longitud total: %zu)\n", dst3, result);
	// Caso 4
	result = ft_strlcat(dst4, srrc, sizeof(dst4));
	printf("Caso 4: %s (Longitud total: %zu)\n", dst4, result);
	// TOUPPER
	upper = 'd';
	printf("\nMY ft_toupper------------------\nBefore: %c\n", upper);
	printf("\nAfter: %c", ft_toupper(upper));
	// TOLOWER
	lower = 'R';
	printf("\nMY ft_tolower------------------\nBefore: %c\n", lower);
	printf("\nAfter: %c\n", ft_tolower(lower));
	// STRCHR
	ch = 'e';
	pre = strchr(string, ch);
	printf("\nMY ft_strchr------------------\nString starting with %c is: %s\n",
		ch, pre);
	// STRRCHR
	ret = ft_strrchr(streng, che);
	printf("\nMY ft_strrchr------------------\nString after %c is %s\n", che,
		ret);
	// STRNCMP
	strcpy(str1, "abcde");
	strcpy(str2, "abcdE");
	printf("\nMY ft_strncmp------------------\n");
	reto = ft_strncmp(str1, str2, 3);
	if (reto < 0)
		printf("str1 is less than str2");
	else if (reto > 0)
		printf("str2 is less than str1");
	else
		printf("str1 is equal to str2");
	printf("\n");
	// MEMCHR
	printf("\nMY ft_memchr------------------\n");
	myPtr = (char *)ft_memchr(myStr, 'o', 12);
	if (myPtr != NULL)
	{
		printf("\nfound: %s\n", myPtr);
	}
	// MEMCMP
	esult = ft_memcmp(arr1, arr2, sizeof(arr1));
	printf("\nMY ft_memcmp------------------\n");
	if (esult == 0)
	{
		printf("Arrays are equal\n");
	}
	else
	{
		printf("Arrays are not equal\n");
	}
	// STRNSTR
	printf("\n\nMY ft_strnstr------------------");
	frase = "Foo Bar Baz";
	peq = "Bar";
	coin = ft_strnstr(frase, peq, 11);
	printf("\nFound: %s\n", coin);
	// ATOI
	printf("\n\nMY ft_atoi------------------");
	numb = "  \n  425*2654";
	yesul = ft_atoi(numb);
	printf("\nIngresado: %s\nResultado: %i\n", numb, yesul);
	// CALLOC
	printf("\n\nMy ft_calloc------------------\n");
	ne = 5;
	arr = (int *)ft_calloc(ne, sizeof(int));
	if (!arr)
	{
		printf("Error al asignar memoria.\n");
		return (1);
	}
	for (size_t i = 0; i < ne; i++)
		printf("%d ", arr[i]);
	free(arr);
	// STRDUP
	duplicated = ft_strdup(orginal);
	printf("\n\nMy ft_strdup------------------\n");
	if (duplicated)
	{
		printf("Original: %s\n", orginal);
		printf("Duplicated: %s\n", duplicated);
		free(duplicated);
	}
	else
	{
		printf("Error: No se pudo duplicar la cadena.\n");
	}
	printf("\n\n");
	// SUBSTR
	origin = "Hello, World!";
	printf("\n\nMy ft_substr------------------\n");
	self = ft_substr(origin, 1, 5);
	printf("\nResult: %s\n", self);
	free(self);
	// STRJOIN
	char const *r1, *r2;
	printf("\n\nMy ft_strjoin------------------\n");
	r1 = "hola";
	r2 = "chao";
	resilt = ft_strjoin(r1, r2);
	printf("\nUnidos: %s final\n", resilt);
	free(resilt);
	// STRTRIM
	printf("\n\nMy ft_strtrim------------------\n");
	sre = ft_strtrim("   xxxtripouille", "x");
	printf("\n\nCadena resultante:%s\n", sre);
	// SPLIT
	printf("\n\nMy ft_split------------------\n");
	si = "Hello,,,World,,Split,,Function";
	c = ',';
	rsult = ft_split(si, c);
	if (result)
	{
		for (int i = 0; rsult[i] != NULL; i++)
		{
			printf("Palabra %d: %s\n", i, rsult[i]);
			free(rsult[i]); // Liberar memoria de cada palabra
		}
		free(rsult); // Liberar el array de punteros
	}
	else
	{
		printf("Error al dividir la cadena.\n");
	}
	printf("\n");
	// ITOA
	printf("\n\nMy ft_itoa------------------\n");
	mou = ft_itoa(-1);
	printf("\nResultado: %s\n", mou);
	for (int i = 0; mou[i] != '\0'; i++)
	{
		printf("\nCada uno: %c\n", mou[i]);
	}
	// STRMAPI
	printf("\n\nMy ft_strmapi------------------\n");
	mous = "hola";
	printf("\nResultado: %s\n", ft_strmapi(mous, addOne));
	// STRITERI
}
