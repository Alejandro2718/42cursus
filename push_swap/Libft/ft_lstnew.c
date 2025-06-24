/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:51:13 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/05 18:59:21 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This Function creates a new_node
based on the structure t_list.
Asign content took as argument into
the object content of the t_list
*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
