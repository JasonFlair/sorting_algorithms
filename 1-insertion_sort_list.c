#include "sort.h"

/** 
 * insertion_sort_list - insertion_sort_list function
 * 
 * @list: list to be sorted
 * Return - void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *head, *temp, *ptr, *ptr2;

    if (list != NULL)
    {
        head = *list;
        ptr = head->next;
        ptr->prev = head;
        ptr2 = ptr->next;
        ptr2->prev = ptr;
        temp = ptr->prev;
        
    }
    while (ptr != NULL)
    {
        if (ptr->prev != NULL && ptr->prev != head)
        {
            if (ptr->n < temp->n)
            {
                ptr->prev = temp->prev;
                temp->prev->next = ptr;
                temp->next = ptr->next;
                ptr->next->prev = temp;
                ptr->next = temp;
                temp->prev = ptr;
                /* swap done now print */
                print_list(*list);
                temp = ptr->prev;
                /* change temp and check again */
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
            ptr = ptr->next;
            ptr2 = ptr->next;
            temp = ptr->prev;
        }
    }
}