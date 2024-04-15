/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

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