#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 **/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Perform the sift-down operation in Heap sort
 * @array: Array to be sorted
 * @start: Start index of the heap
 * @end: End index of the heap
 * @size: Size of the array
 **/
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child, swap_index;

    while (2 * root + 1 <= end)
    {
        child = 2 * root + 1;
        swap_index = root;

        if (array[swap_index] < array[child])
            swap_index = child;

        if (child + 1 <= end && array[swap_index] < array[child + 1])
            swap_index = child + 1;

        if (swap_index == root)
            return;

        swap(&array[root], &array[swap_index]);
        print_array(array, size);
        root = swap_index;
    }
}

/**
 * heapify - Build a max heap from the array
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void heapify(int *array, size_t size)
{
    ssize_t start = (size - 2) / 2;

    while (start >= 0)
    {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void heap_sort(int *array, size_t size)
{
    size_t end = size - 1;

    if (!array || size < 2)
        return;

    heapify(array, size);

    while (end > 0)
    {
        swap(&array[end], &array[0]);
        print_array(array, size);
        end--;
        sift_down(array, 0, end, size);
    }
}

