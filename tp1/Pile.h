//
// Created by Kirankumar KICHENASSAMY on 19/11/2026.
//

#ifndef TP1_STACK_H
#define TP1_STACK_H
#include "slist.h"

typedef struct Pile {
    SList list;
}Pile;


Pile ds_stack_create(void);
int ds_stack_is_empty(const Pile *p);
int ds_stack_push(Pile *p, int x);
int ds_stack_pop(Pile *p, int *out);
int ds_stack_peek(const Pile *p, int *out);
void ds_stack_clear(Pile *p);




#endif //TP1_STACK_H
