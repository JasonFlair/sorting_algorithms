#include "sort.h"
/**
 * selection_sort - selectio sort function 
 * 
 * @array: aray to be sorted
 * @size: size of array 
 * Return - void
 */
void selection_sort(int *array, size_t size)
{
    unsigned int i, j;
    int sp, fp, min, temp;
    i = 0;
    sp = 0; /* starting position marker */
    fp = 0; /* former position marker */

    while (i < size)
    {
        min = array[sp];
        for (j = (0 + sp); j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                fp = j;
                /* fp will be equal to position j */
            }
        }
        if (fp != sp)
        {
            temp = array[i];
            array[i] = min;
            array[fp] = temp;
            /* swap done now print */
            print_array(array, size);
        }
        i++;
        sp++;
        fp = (0 + sp); 
    }
}