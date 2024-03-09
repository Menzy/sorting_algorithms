#include "sort.h"

/**
 * swap - swaps positions of two numbers
 * @x: pointer to first number to be swapped
 * @y: pointer to second number to be swapped
 */
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * selection_sort - sort an array of integers in ascending order
 * @arr: array of integers to be sorted
 * @size: size of the array to be sorted
 * Description: prints the array after every swap
 */
void selection_sort(int *arr, size_t size)
{
    size_t i, j, min_index;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&arr[i], &arr[min_index]);
            print_array(arr, size);
        }
    }
}
