#include "sort.h"
#include <stdio.h>
#include <stdlib.h> /* Include stdlib for malloc and free */

/**
 * _calloc - this is a calloc function
 * @nmemb: number of elements
 * @size: bit size of each element
 * Return: pointer to memory assignment
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i = 0;
    char *p;

    if (nmemb == 0 || size == 0)
        return (NULL);

    p = malloc(nmemb * size);
    if (p == NULL)
        return (NULL);

    for (i = 0; i < (nmemb * size); i++)
        p[i] = '\0';

    return (p);
}

/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
    int index, maximun = 0, *counter = NULL, *tmp = NULL;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* find maximum number */
    for (i = 0; i < size; i++)
        if (array[i] > maximun)
            maximun = array[i];

    counter = _calloc(maximun + 1, sizeof(int));
    tmp = _calloc(size, sizeof(int));

    if (counter == NULL || tmp == NULL)
    {
        free(counter);
        free(tmp);
        return;
    }

    /* count the array elements */
    for (i = 0; i < size; i++)
        counter[array[i]]++;

    /* get the accumulative values */
    for (index = 1; index <= maximun; index++)
        counter[index] += counter[index - 1];

    print_array(counter, maximun + 1);

    /* get the new array sorted */
    for (i = 0; i < size; ++i)
    {
        tmp[counter[array[i]] - 1] = array[i];
        counter[array[i]]--;
    }

    /* replace old array with the new array sorted */
    for (i = 0; i < size; i++)
        array[i] = tmp[i];

    free(tmp);
    free(counter);
}

