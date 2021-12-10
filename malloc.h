/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** malloc_h
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct data *data_t;
struct data
{
    data_t next;
    size_t size;
    bool free;
};

void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);
void *add_node(data_t *head, size_t t);
void *add_first_node(data_t *head, size_t t);

#endif