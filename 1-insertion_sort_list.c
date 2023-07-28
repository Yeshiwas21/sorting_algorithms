#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *swap, *tmp;

if (!list || !(*list) || !(*list)->next)
	return;

curr = *list;

while (curr->next != NULL)
{
swap = curr->next;
if (curr->n > swap->n)
{
tmp = curr;
while (tmp != NULL && tmp->n > swap->n)
{
tmp->next = swap->next;
if (tmp->next != NULL)
	tmp->next->prev = tmp;
swap->prev = tmp->prev;
if (swap->prev != NULL)
	swap->prev->next = swap;
else
	*list = swap;
tmp->prev = swap;
swap->next = tmp;
print_list(*list);
tmp = swap->prev;
}
continue;
}
curr = curr->next;
}
}
