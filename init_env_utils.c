/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:28:43 by abenheni          #+#    #+#             */
/*   Updated: 2023/05/05 13:28:44 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert(t_export **sorted, t_export *new_node)
{
	t_export	*current;

	if (*sorted == NULL || strcmp((*sorted)->var, new_node->var) > 0)
	{
		new_node->next = *sorted;
		*sorted = new_node;
	}
	else
	{
		current = *sorted;
		while (current->next != NULL
			&& ft_strcmp(current->next->var, new_node->var) < 0)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}

void	sort(t_export **head)
{
	t_export	*sorted;
	t_export	*current;
	t_export	*temp;

	sorted = NULL;
	current = *head;
	while (current != NULL)
	{
		temp = current->next;
		insert(&sorted, current);
		current = temp;
	}
	*head = sorted;
}
