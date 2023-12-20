#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Double linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *node, *back, *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    node = (*list)->next;
    while (node)
    {
        current = node;
        while (current->prev && current->prev->n > current->n)
        {
            back = current->prev;

            /* Perform the swap */
            if (back->prev)
                back->prev->next = current;
            else
                *list = current;
            current->prev = back->prev;
            back->next = current->next;
            if (current->next)
                current->next->prev = back;
            current->next = back;
            back->prev = current;

            print_list(*list);
        }
        node = node->next;
    }
}

