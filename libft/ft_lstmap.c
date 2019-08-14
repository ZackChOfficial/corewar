/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:53:19 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/07 14:30:55 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nw;

	nw = NULL;
	if (lst)
	{
		if ((nw = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		nw = (*f)(lst);
		nw->next = ft_lstmap(lst->next, (*f));
	}
	return (nw);
}
