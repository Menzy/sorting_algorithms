#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @x: first integer to be swapped
 * @y: second integer to be swapped
 */
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * quick_sort - sorts an array of integers in an
 * asc order using the quicksort algo
 * @array: array of integers
 * @size: size of the array
 *
 * Description: utilizes the Lomuto partition scheme
 * prints the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - partitions the array around a pivot element
 * @array: array to be partitioned
 * @size: size of the array
 * @left: starting index of the subset to be partitioned
 * @right: ending index of the subset to be partitioned
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }

    swap(&array[i + 1], &array[right]);
    print_array(array, size);
    
    return (i + 1);
}

/**
 * lomuto_sort - quicksort algorithm by recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 *
 * Description: utilizes the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    if (left < right)
    {
        int part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}
