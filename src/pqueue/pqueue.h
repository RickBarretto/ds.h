#include "../klist_utils.h"
#include "../klist_utils.c"


typedef struct pqueue pqueue_t;
typedef struct pnode pnode_t;


struct pnode
{
        size_t val;
        pnode_t *next;
        size_t priority;
};


struct pqueue
{
        pnode_t *head;
        size_t len;
};


bool insert_pqueue(pqueue_t *queue, size_t value, size_t priority); 
