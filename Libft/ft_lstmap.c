/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:37:52 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/05 20:55:57 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;

	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		new_list = malloc(sizeof(t_list));
		if (!new_list)
			temp = lst->next;
		new_list->content = f(lst->content);
		new_list->next = lst->next;
		lst = temp;
	}
	return (new_list);
}
