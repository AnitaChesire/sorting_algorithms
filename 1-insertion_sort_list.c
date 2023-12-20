#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Double linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || (*list)->next == NULL)
        return;

    listint_t *node = (*list)->next;

    while (node)
    {
        listint_t *current = node;

        while (current->prev && current->prev->n > current->n)
        {
            /* Swap the nodes */
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->prev->prev;

            if (current->prev)
                current->prev->next = current;
            else
                *list = current;

            current->next->prev = current;

            /* Move to the next node */
            print_list(*list);
        }

        node = node->next;
    }
}

