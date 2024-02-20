#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition scheme)
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Recursively performs quicksort using Hoare partition
 * @array: Array to be sorted
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = hoare_partition(array, low, high, size);

        quicksort_hoare(array, low, p, size);
        quicksort_hoare(array, p + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: Array to be partitioned
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 * Return: Index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

