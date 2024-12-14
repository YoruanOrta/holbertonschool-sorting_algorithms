#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort.
 * @list: Double pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		key = current;
		prev = current->prev;

		while (prev && prev->n > key->n)
		{
			prev->next = key->next;
			if (key->next)
				key->next->prev = prev;

			key->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = key;

			key->next = prev;
			prev->prev = key;

			if (!key->prev)
				*list = key;
			print_list(*list);
			prev = key->prev;
		}
		current = current->next;
	}
}
