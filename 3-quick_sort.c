#include "sort.h"

/**
 * swap - swap the positions of two elements in an array
 * @array: array
 * @item1: array element
 * @item2: array element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
    int tmp;

    tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size array
 * Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
    int pivot = array[last];
    ssize_t current = first, finder;

    for (finder = first; finder < last; finder++)
    {
        if (array[finder] < pivot)
        {
            if (array[current] != array[finder])
            {
                swap(array, current, finder);
                print_array(array, size);
            }
            current++;
        }
    }
    if (array[current] != array[last])
    {
        swap(array, current, last);
        print_array(array, size);
    }
    return (current);
}

/**
 * quick_sort_recursive - Quicksort algorithm implementation (recursive)
 * @array: array
 * @first: first array element
 * @last: last array element
 */
void quick_sort_recursive(int *array, ssize_t first, ssize_t last)
{
    ssize_t position;

    if (first < last)
    {
        position = lomuto_partition(array, first, last, 0);

        quick_sort_recursive(array, first, position - 1);
        quick_sort_recursive(array, position + 1, last);
    }
}

/**
 * quick_sort - Prepare the terrain for quicksort algorithm
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

