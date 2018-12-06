/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:24:50 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/09 14:14:46 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;

	temp = *alst;
	while (temp)
	{
		del(temp->content, temp->content_size);
		temp = temp->next;
		free(*alst);
		*alst = NULL;
		*alst = temp;
	}
}
