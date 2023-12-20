#include "sort.h"

/**
 * swap - swap the positions of two elements in an array
 * @array: array
 * @item1: array element
 * @item2: array element
 */
void swap(int *array, size_t item1, size_t item2)
{
    int tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, index;

    if (array == NULL || size < 2)
        return;

    while (gap < size / 3)
        gap = 3 * gap + 1;

    while (gap >= 1)
    {
        for (i = gap; i < size; i++)
        {
            for (index = i; index >= gap && array[index] < array[index - gap]; index -= gap)
            {
                swap(array, index, index - gap);
            }
        }

        print_array(array, size);
        gap /= 3;
    }
}

