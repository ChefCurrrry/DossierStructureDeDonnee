//
// Created by Kirankumar KICHENASSAMY on 19/11/2026.
//

#include "Queue.h"

File ds_queue_create(void) {
    File f;
    f.plist = ds_slist_ht_create();
    return f;
}

int  ds_queue_is_empty(const File *f) {
    return ds_slist_ht_is_empty(&f->plist);
}

int  ds_queue_enqueue(File *f, int x) {
    return ds_slist_ht_insert_tail(&f->plist, x);
}

int  ds_queue_dequeue(File *f, int *out){
    return ds_slist_ht_remove_head(&f->plist, out);
}

int  ds_queue_front(const File *f, int *out) {
    if (ds_slist_ht_is_empty(&f->plist)) {return 0;}
    *out = f->plist.head->data;
    return 1;
}

void ds_queue_clear(File *f) {
    ds_slist_ht_clear(&f->plist);
}