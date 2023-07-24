#include "sort.h"
void swap_nodes(listint_t *cur, listint_t *sm_node);

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 *
 * @list: pointer to a linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (!list || !*list)
		return;
	current = *list;

	while (current->next)
	{
		next_node = current->next;
		if (current->n > next_node->n)
		{
			swap_nodes(current, next_node);
			if (!next_node->prev)
				*list = next_node;
			print_list(*list);
			while (next_node->prev && next_node->prev->n > next_node->n)
			{
				swap_nodes(next_node->prev, next_node);
				if (!next_node->prev)
					*list = next_node;
				print_list(*list);
			}
			continue;
		}
		current = current->next;
	}
}

/**
 * swap_nodes - swaps the position of two nodes in a doubly linked list
 *
 * @cur: the larger node to move forward
 * @sm_node: smaller node to move backwards
 *
 * Return: void
 */
void swap_nodes(listint_t *cur, listint_t *sm_node)
{
		if (sm_node->next)
			sm_node->next->prev = cur;
		if (cur->prev)
			cur->prev->next = sm_node;
		cur->next = sm_node->next;
		sm_node->next = cur;
		sm_node->prev = cur->prev;
		cur->prev = sm_node;
}
