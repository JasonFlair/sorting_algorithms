#include "sort.h"

/** 
 * insertion_sort_list - insertion_sort_list function
 * 
 * @list: list to be sorted
 * Return - void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *head, *temp, *temp2, *ptr, *ptr2;

    if (list != NULL)
    {
        head = *list;
        ptr = head->next;
        ptr->prev = head;
        ptr2 = ptr->next;
        ptr2->prev = ptr;
        temp = ptr->prev;
        temp2 = ptr2->prev;
        
    }
    while (ptr->next != NULL)
    {
        if (ptr->n > ptr2->n)
        {
            ptr->next = ptr2->next;
            ptr2->next->prev = ptr;
            ptr2->prev = ptr->prev;
            ptr2->next = ptr;
            ptr->prev = ptr2;
            temp->next = ptr2;
            temp2 = ptr2->prev;
            temp = ptr->prev;
            print_list(*list);
            if (ptr2->prev != NULL && ptr2->prev != head && ptr2->n < temp2->n)
            {
                if (ptr2->n < temp2->n)
                {
                    ptr2->prev = temp2->prev;
                    temp2->prev->next = ptr2;
                    temp2->next = ptr2->next;
                    ptr2->next->prev = temp2;
                    ptr2->next = temp2;
                    temp2->prev = ptr2;
                    temp2 = ptr2->prev;
                    temp = ptr->prev;
                    /* swap*/
                    print_list(*list);
                }
                break;
            }
            else
            {
                ptr2 = ptr->next;
                temp = ptr->prev;
                temp2 = ptr2->prev;
            }
        }
        else
        {
            ptr = ptr->next;
            ptr2 = ptr->next;
            temp = ptr->prev;
            temp2 = ptr2->prev;
        }
    }
}