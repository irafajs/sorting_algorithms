#include "sort.h"

/**
 * cocktail_sort_list - sort list uding cocktail shaker
 * @list: passed param as list
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swap)
	{
		swap = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				swap = 1;
				if (current->prev == NULL)
				{
					*list = current;
				}
				print_list(*list);
			}
		}
		if (!swap)
			break;
		swap = 0;
		for (; current != NULL && current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				swap = 1;
				if (current->prev == NULL)
				{
					*list = current;
				}
				print_list(*list);
			}
		}
	}
}
/**
 * swap_nodes - function to swap nodes
 * @node1: passed param as a pointer to node one
 * @node2: passed param as node two
 *
 * Return: nothing
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
