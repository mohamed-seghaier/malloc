/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** node
*/

#include "malloc.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add_first_node(data_t *head, size_t t)
{
    pthread_mutex_lock(&mutex);
    *head = sbrk(sizeof(struct data) + t);
    (*head)->size = t;
    (*head)->next = NULL;
    (*head)->free = false;
    pthread_mutex_unlock(&mutex);
    return *head + 1;
}

void *add_node(data_t *head, size_t t)
{
    pthread_mutex_lock(&mutex);
    while ((*head)->next != NULL) {
        if ((*head)->free == true && (*head)->size == t) {
            (*head)->free = false;
            pthread_mutex_unlock(&mutex);
            return ((data_t)(*head));
        }
        *head = (*head)->next;
    }
    data_t tmp = sbrk(sizeof(struct data) + t);
    if (tmp == (void *)-1)
        return NULL;
    tmp->size = t;
    tmp->next = NULL;
    tmp->free = false;

    (*head)->next = tmp;
    pthread_mutex_unlock(&mutex);
    return tmp + 1;
}