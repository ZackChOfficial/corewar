/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:13:12 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/19 17:19:38 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	next = tmp->next;
	while (next != NULL)
	{
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = next;
		next = tmp->next;
	}
	(*del)(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
