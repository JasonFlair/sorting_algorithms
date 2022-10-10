#include "sort.h"

/**
 * swap - swap function
 * @x: first param
 * @y: second param
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
 * @param array; array
 * @param start: starting pos
 * @param end: end pos
 * @param arr_size: size
 * @return int 
 */
int partition_index(int *array, int start, int end, size_t arr_size)
{
    int i, j;

    i = start;
    for (j = start; j < end; j++)
    {
        if (array[j] <= array[end])
        {
            swap(&array[j], &array[i]);
            print_array(array, arr_size);
            i++;
        }
    }
    swap(&array[end], &array[i]);
    print_array(array, arr_size);
    return i;
}
/**
 * quick_sorter - quick sort recursion 
 * 
 * @param array: array to be sorted 
 * @param start: starting position
 * @param end: end position 
 * @param arr_size: arr size 
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
 * quick sort - quick sort function 
 * 
 * @param array: array to be sorted
 * @param size: size of arr
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    quick_sorter(array, 0, size - 1, size);
}