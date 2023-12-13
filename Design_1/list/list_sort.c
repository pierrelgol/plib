/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:03:40 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 15:03:43 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static t_list	*list_sorted_merge(t_list *left, t_list *right,
		int (*f)(void *d1, void *d2))
{
	t_list	*result;

	result = 0;
	if (!left)
		return (right);
	else if (!right)
		return (left);
	if (f(left->data, right->data))
	{
		result = left;
		result->next = list_sorted_merge(left->next, right, f);
	}
	else
	{
		result = right;
		result->next = list_sorted_merge(left, right->next, f);
	}
	return (result);
}

static void	list_find_middle(t_list *list, t_list **start, t_list **end)
{
	t_list	*fast;
	t_list	*slow;

	slow = list;
	fast = list->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*start = list;
	*end = slow->next;
	slow->next = 0;
}

void	list_sort(t_list **list, int (*f)(void *d1, void *d2))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *list;
	if (!head || !head->next)
		return ;
	list_find_middle(head, &a, &b);
	list_sort(&a, f);
	list_sort(&b, f);
	*list = list_sorted_merge(a, b, f);
}
