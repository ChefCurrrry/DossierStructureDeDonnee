//
// Created by Kirankumar KICHENASSAMY on 19/11/2026.
//

#ifndef TP1_QUEUE_H
#define TP1_QUEUE_H
#include "slist_ht.h"

typedef struct File {
    SList_HT plist;
}File;

File ds_queue_create(void);
int  ds_queue_is_empty(const File *f);
int  ds_queue_enqueue(File *f, int x);
int  ds_queue_dequeue(File *f, int *out);
int  ds_queue_front(const File *f, int *out);
void ds_queue_clear(File *f);

#endif //TP1_QUEUE_H
