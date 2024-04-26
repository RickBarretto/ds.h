#include "../klist_utils.c"
#include "pqueue.h"


bool insert_pqueue(pqueue_t *queue, size_t value, size_t priority)
{
        new(pnode_t, new_node);
        defer(new_node, false);
        new_node->val = value;
        new_node->priority = priority;
            
        unless(queue->len) {
                queue->head = new_node;
                queue->head->next = NULL;
                queue->len++;
                return true;  
        }
        
        if (new_node->priority > queue->head->priority) {
                new_node->next = queue->head;
                queue->head = new_node;
                queue->len++;
                return true;
        }
        
        pnode_t *aux = queue->head;
            
        while (aux->next and new_node->priority <= aux->next->priority)
                aux = aux->next;
            
        new_node->next = aux->next;
        aux->next = new_node;
        queue->len++;        
            
        return true;
}