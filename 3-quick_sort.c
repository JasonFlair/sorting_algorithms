#include "sort.h"

/**
 * swap - the swap function
 * @x: first param
 * @y: second param
 * Return - void
 */
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * partition_index - func returns partition
 * index 
 * 
 * @array: array to be sorted 
 * @start: starting position
 * @end: end position 
 * @arr_size: the arr size
 * Return: returns an int 
 */

int partition_index(int *array, int start, int end, size_t arr_size)
{
    int i, j;

    i = start;
    for (j = start; j < end; j++)
    {
        if (array[j] <= array[end])
        {
            if (array[j] != array[i])
            {
                swap(&array[j], &array[i]);
                print_array(array, arr_size);   
            }
            i++;
        }
    }
    if (array[end] != array[i])
    {
        swap(&array[end], &array[i]);
        print_array(array, arr_size);
    }
    
    return i;
}

/**
 * quick_sorter - quick sort recursion 
 * 
 * @array: array to be sorted 
 * @start: starting position
 * @end: end position 
 * @arr_size: the arr size
 * Return - void
 */

void quick_sorter(int *array, int start, int end, size_t arr_size)
{

    if (start < end)
    {
        int p_idx = partition_index(array, start, end, arr_size);
        quick_sorter(array, start, p_idx - 1, arr_size);
        quick_sorter(array, p_idx + 1, end, arr_size);
    }
}

/**
 * quick_sort - quick sort function 
 * 
 * @array: array to be sorted
 * @size: size of arr
 * Return - void
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    quick_sorter(array, 0, size - 1, size);
}