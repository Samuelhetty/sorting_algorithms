#include "sort.h"

/**
 * insertion_sort_list - sorts list with insertion sort
 * @list: input list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *p_node, *n_node;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;
		p_node = temp->prev;
		n_node = temp->next;

		while (temp)
		{
			if (temp->n < p_node->n)
			{
				swap_insert(p_node, temp, n_node, list);
			}
			temp = n_node;
			if (temp)
			{
				n_node = temp->next;
				p_node = temp->prev;
			}
		}
	}
}

/**
 * swap_insert - swaps integers with insertion form
 * @p_node: previous node of linked list
 * @tmp: node to be swapped
 * @n_node: next node of list
 * @h: the head of the linked list
 */
void swap_insert(listint_t *p_node, listint_t *tmp,
		listint_t *n_node, listint_t **h)
{

	while (p_node && tmp->n < p_node->n)
	{
		/* handle next node */
		if (n_node)
			n_node->prev = p_node;

		/* handle temp node */
		tmp->next = p_node;
		tmp->prev = p_node->prev;

		/* handle prev node */
		if (p_node->prev)
			(p_node->prev)->next = tmp;
		p_node->prev = tmp;
		p_node->next = n_node;

		/* reset comparison values */
		n_node = p_node;
		p_node = tmp->prev;
		if ((*h)->prev)
			*h = (*h)->prev;
		print_list(*h);
	}
}
