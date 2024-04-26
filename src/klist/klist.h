/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef KLIST_H
#define KLIST_H


#include <stdlib.h>
#include <stdbool.h>


#include "../klist_utils.c"
#include "../klist_utils.h"


klist_t *new_klist();
void clear_klist(klist_t *list);
void remove_from_klist(klist_t *list, size_t element);
bool insert_into_klist(klist_t *list, size_t value);
void print_klist(klist_t *list);


#endif