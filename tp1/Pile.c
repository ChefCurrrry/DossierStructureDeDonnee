//
// Created by Kirankumar KICHENASSAMY on 19/11/2026.
//

#include "Pile.h"

Pile ds_stack_create(void) {
    Pile p;
    p.list = ds_slist_create();
    return p;
}

int ds_stack_is_empty(const Pile *p) {
    return ds_slist_is_empty(&p->list);
}

int ds_stack_push(Pile *p, int x) {
    return ds_slist_insert_head(&p->list, x);
}

int ds_stack_pop(Pile *p, int *out) {
    return ds_slist_remove_head(&p->list, out);
}

int ds_stack_peek(const Pile *p, int *out) {
    if (ds_stack_is_empty(p)) { return 0; }
    *out = p->list.head->data;
    return 1;
}

void ds_stack_clear(Pile *p) {
    ds_slist_clear(&p->list);
}





