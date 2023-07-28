#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of a doubly linked list.
 *
 * @node: Pointer to the node to be swapped.
 * @list: Pointer to the head of the doubly linked list.
 *
 * Return: No Return.
 */
void swap_nodes(listint_t **node, listint_t **list)
{
listint_t *current = *node, *next_node, *prev_node;

if (!current->prev)
	*list = current->next;
current = prev_node = *node;
next_node = current->next;
current->next = next_node->next;
prev_node = current->prev;
current->prev = next_node;
next_node->next = current;
next_node->prev = prev_node;

if (next_node->prev)
	next_node->prev->next = next_node;
if (current->next)
	current->next->prev = current;
*node = next_node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order using
 *                       the Cocktail Shaker sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list.
 *
 * Return: No Return.
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *current, *aux;
int count = 0, low = -1, high = -1;

if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
	return;
current = *list;
while (high >= low)
{
low++;
while (current->next && count != high)
{
if (current->n > current->next->n)
{
aux = current;
swap_nodes(&aux, list);
print_list(*list);
current = aux;
}
count++;
current = current->next;
}
if (low == 0)
	high = count;
high--;
while (current->prev && count >= low)
{
if (current->n < current->prev->n)
{
aux = current->prev;
swap_nodes(&aux, list);
print_list(*list);
current = aux->next;
}
count--;
current = current->prev;
}
}
}
