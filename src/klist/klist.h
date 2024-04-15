#ifndef KLIST_H
#define KLIST_H


#include <stdlib.h>
#include <stdbool.h>


typedef struct klist klist_t;
typedef struct knode knode_t;

struct knode
{
        size_t val;
        knode_t *next;
};


struct klist
{
        knode_t *head;
        size_t len;
};


klist_t *new_klist();
void clear_list(klist_t *list);
bool insert_klist(klist_t *list, size_t value);
void traverse_klist(klist_t *list);


#endif