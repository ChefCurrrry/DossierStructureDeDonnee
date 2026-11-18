//
// Created by Kirankumar KICHENASSAMY on 06/11/2026.
//

#ifndef TP1_SLIST_HT_H
#define TP1_SLIST_HT_H
#include "slist.h"

typedef struct SList_HT {
    SNode *head;
    SNode *tail;
}SList_HT;

SNode * ds_slist_ht_create_node(int data);
SList_HT ds_slist_ht_create();
void ds_slist_ht_init(SList_HT *plist);
int ds_slist_ht_is_empty(const SList_HT  *plist);
void ds_slist_ht_print(const SList_HT  *plist);

int ds_slist_ht_insert_head(SList_HT *plist, int data);
int ds_slist_ht_insert_tail(SList_HT *plist, int data);
int ds_slist_ht_insert_at(SList_HT *list, int data, int position);

int ds_slist_ht_remove_tail(SList_HT *list, int *out);
int ds_slist_ht_remove_head(SList_HT *list, int *out);
int ds_slist_ht_remove_value(SList_HT *list, int value);
void ds_slist_ht_clear(SList_HT *list);
SNode* ds_slist_ht_find(const SList_HT *list, int value);

#endif //TP1_SLIST_HT_H
