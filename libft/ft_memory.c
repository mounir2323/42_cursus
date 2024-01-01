/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:25:39 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 21:00:43 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_mem_block(void **p_head, void *ptr, size_t size)
{
	t_memory_block	*block;

	block = (t_memory_block *) malloc(sizeof(t_memory_block));
	block->adresse = ptr;
	block->size = size;
	block->next = *p_head;
	*p_head = block;
}

void	remove_mem_block(void **p_head, void *ptr)
{
	t_memory_block	*block;
	t_memory_block	*prev;

	block = *p_head;
	prev = NULL;
	while (block != NULL)
	{
		if (block->adresse == ptr)
		{
			if (prev == NULL)
				*p_head = block->next;
			else
				prev->next = block->next;
			free(block);
			break ;
		}
		prev = block;
		block = block->next;
	}
}

void	free_all_mem(void **p_head, int status, char *message)
{
	t_memory_block	*node;
	t_memory_block	*next;

	next = NULL;
	node = *p_head;
	while (node != NULL)
	{
		next = node->next;
		free(node->adresse);
		free(node);
		node = next;
	}
	*p_head = NULL;
	if (message)
		printf ("%s", message);
	exit(status);
}

void	*my_malloc(void **p_head, size_t size)
{
	void	*adresse;

	adresse = malloc(size);
	if (!adresse)
		free_all_mem(p_head, EXIT_FAILURE, "Memory error.\n");
	add_mem_block(p_head, adresse, size);
	return (adresse);
}

void	my_free(void **p_head, void *adresse)
{
	remove_mem_block(p_head, adresse);
	free(adresse);
}
