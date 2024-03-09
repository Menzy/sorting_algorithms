#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @head: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **head)
{
    listint_t *sorted, *current, *temp;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    sorted = *head;
    current = sorted->next;

    while (current != NULL)
    {
        temp = current;
        current = current->next;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->prev->next = temp->next;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;

            if (temp->prev == NULL)
                *head = temp;
            else
                temp->prev->next = temp;

            print_list(*head);
        }
    }
}
