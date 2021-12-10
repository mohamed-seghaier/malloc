/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** my_malloc
*/

#include "./malloc.h"

void *malloc(size_t t)
{
    static data_t head = NULL;

    if (t <= 0)
        return NULL;
    if (head == NULL)
        return add_first_node(&head, t);
    else
        return add_node(&head, t);

}

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    data_t to_free = (data_t)ptr - 1;
    to_free->free = true;
    if (to_free->next == NULL && to_free->free == true)
        brk(ptr);
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }
    data_t to_rea = (data_t)ptr - 1;
    if (size <= to_rea->size) {
        return ptr;
    }
    void *tmp = malloc(size);
    if (!tmp) {
        return NULL;
    }
    memcpy(tmp, ptr, to_rea->size);
    free(ptr);
    return tmp;
}