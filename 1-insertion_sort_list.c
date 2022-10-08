
#include "sort.h"

/** 
 * insertion_sort_list - insertion_sort_list function
 * 
 * @list: list to be sorted
 * Return - void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *head, *temp, *ptr, *ptr2, *ptr_next, *prev;

    head = *list;
    if (head == NULL || head->next == NULL)
    {
        print_list(*list);
        return;
    }

    if (head != NULL)
    {
        head = *list;
        ptr = head->next;
        temp = ptr->prev;
        ptr2 = ptr->next;
        
    }
    while (ptr != NULL)
    {
        if (ptr->prev != NULL)
        {
            if (ptr->n < temp->n)
            {
               prev = temp->prev; /* hold value of temp prev */
               ptr_next = ptr->next;
               /* holds value of ptr next at the time */

               temp->next = ptr_next;
               ptr->next = temp;
               temp->prev = ptr;
               if (ptr_next != NULL)
               {
                ptr_next->prev = temp;
               }
               ptr->prev = prev;
               if (prev == NULL)
               {
                *list = ptr;
                /* ptr becomes head */
               }
               else
               {
                prev->next = ptr;
                /* else prev-next points to ptr */
               }
               print_list(*list);
               temp = ptr->prev;
            }
            else
            {
                ptr = ptr2;
                ptr2 = ptr->next;
                temp = ptr->prev;
            }
            
        }
        else
        {
            ptr = ptr2;
            ptr2 = ptr->next;
            temp = ptr->prev;
        }
    }
}