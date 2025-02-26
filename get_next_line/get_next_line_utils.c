/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:19 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/26 17:13:35 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * ft_strlen: Calcula la longitud de una cadena
 * Parámetros:
 *   str: Cadena cuya longitud queremos calcular
 * Retorno:
 *   Longitud de la cadena (número de caracteres hasta '\0')
 *   0 si str es NULL
 */
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str) /* Comprobación de seguridad para str NULL */
		return (0);
	while (str[i]) /* Incrementamos i hasta encontrar el carácter nulo */
		i++;
	return (i);
}

/*
 * ft_strchr: Busca la primera ocurrencia de un carácter en una cadena
 * Parámetros:
 *   s: Cadena en la que buscar
 *   c: Carácter a buscar
 * Retorno:
 *   Puntero a la primera ocurrencia del carácter c en s
 *   NULL si no se encuentra o si s es NULL
 */
char	*ft_strchr(char *s, int c)
{
	if (!s) /* Comprobación de seguridad para s NULL */
		return (NULL);
	while (*s)
	{
		if (*s == (char)c) /* Compara cada carácter con c */
			return ((char *)s);
		s++;
	}
	/* También comprobamos el carácter nulo (por si c es '\0') */
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
 * ft_substr: Extrae una subcadena de una cadena
 * Parámetros:
 *   s: Cadena original
 *   start: Índice desde donde empezar la subcadena
 *   len: Longitud máxima de la subcadena
 * Retorno:
 *   Puntero a la nueva subcadena (debe liberarse después)
 *   NULL si hay error o s es NULL
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	/* Ajustamos len si start está fuera de la cadena o si len es mayor que el resto */
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	/* Asignamos memoria para la subcadena */
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	/* Copiamos los caracteres de s a substr */
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0'; /* Añadimos el carácter nulo al final */
	return (substr);
}

/*
 * ft_strjoin_part1: Primera parte de la unión de cadenas
 * Crea una nueva cadena con s1 y s2 concatenadas
 * Esta función se divide en dos para cumplir con el límite de 25 líneas
 */
static char	*ft_strjoin_part1(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	char	*joined;

	/* Asignamos memoria para la cadena resultante */
	joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	return (joined);
}

/*
 * ft_strjoin: Une dos cadenas en una nueva y libera s1
 * Parámetros:
 *   s1: Primera cadena (se libera al final)
 *   s2: Segunda cadena (no se modifica)
 * Retorno:
 *   Puntero a la nueva cadena unida (debe liberarse después)
 *   NULL si hay error de asignación de memoria
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char *joined;
	size_t i, j;
	size_t s1_len, s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	joined = ft_strjoin_part1(s1, s2, s1_len, s2_len);
	if (!joined)
		return (NULL);

	/* Copiamos s1 a joined */
	i = 0;
	while (i < s1_len)
	{
		joined[i] = s1[i];
		i++;
	}

	/* Copiamos s2 después de s1 en joined */
	j = 0;
	while (j < s2_len)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0'; /* Añadimos el carácter nulo al final */

	if (s1) /* Liberamos s1 (importante para evitar pérdidas de memoria) */
		free(s1);
	return (joined);
}