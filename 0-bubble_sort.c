#include "sort.h"

/**
 * swap - swaps positions of two numbers
 * @x: pointer to the first number to be swapped
 * @y: pointer to the second number to be swapped
 */
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @arr: array of integers to be sorted
 * @len: size of the array to be sorted
 * Description: prints the array after every swap
 */
void bubble_sort(int *arr, size_t len)
{
    size_t i, j;

    if (arr == NULL)
        return;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                print_array(arr, len);
            }
        }
    }
}
