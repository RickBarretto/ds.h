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