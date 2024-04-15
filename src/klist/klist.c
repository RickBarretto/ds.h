/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iso646.h>
#include <stdbool.h>

#include "klist.h"

#define new(T, name) T *name = malloc(sizeof(T))
#define defer(variable, result) if (not (variable)) return (result)
#define NODE_SIZE sizeof(knode_t)


klist_t *new_klist()
{
	new(klist_t, list);
	list->len = 0;
	list->head = NULL;
	return list;
}


void clear_list(klist_t *list)
{
        knode_t *curr_node = list->head;
        knode_t *next_node = NULL;

        for (; curr_node; curr_node = next_node)
        {
                next_node = curr_node->next;
                free(curr_node);
        }

        list->head = NULL;
        list->len = 0;
}


bool insert_klist(klist_t *list, size_t value)
{
	new(knode_t, new_node);
        defer(new_node, false);
        new_node->val = value;

	// When list is empty
        if (not list->len)
        {
                list->head = new_node;
		list->len++;
                list->head->next = NULL;

                return true;
        }

	// Prepending element
        knode_t *aux = list->head;
        if (value < list->head->val) {
                new_node->next = list->head;
                list->head = new_node;
		list->len++;
                return true;
        }

        // Default case
        while (aux->next and aux->next->val < value)
                aux = aux->next;

        knode_t *next = aux->next;
        aux->next = new_node;

        new_node->next = (aux->next) ? next : NULL;
}


void traverse_klist(klist_t *list)
{
        for (knode_t *cur = list->head; cur; cur = cur->next)
                printf("%ld\n", cur->val);
}


#undef NODE_SIZE