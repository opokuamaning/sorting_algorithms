#include "sort.h"

/**
 * getMax - Find the maximum element in an array
 * @array: Array to find the maximum from
 * @size: Size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * countSort - Perform counting sort on the LSD
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent for the current digit place
 */
void countSort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (!output)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
        print_array(array, size);
    }

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
    }
}

