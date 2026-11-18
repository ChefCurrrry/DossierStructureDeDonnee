//
// Created by Kirankumar KICHENASSAMY on 23/10/2026.
//

#ifndef TP1_SLIST_H //Permet d'éviter les redondances d'inclusions des fichiers
#define TP1_SLIST_H

typedef struct SNode {
    int data;
    struct SNode *next;
}SNode;


typedef struct SList {
    SNode *head;
}SList;


SNode * ds_slist_create_node(int data);
SList ds_slist_create();
void ds_slist_init(SList *plist);
int ds_slist_is_empty(const SList *plist);
void ds_slist_print(const SList *plist);

int ds_slist_insert_head(SList *plist, int data);
int ds_slist_insert_tail(SList *plist, int data);
int ds_slist_insert_at(SList *list, int index, int value);

int ds_slist_remove_tail(SList *list, int *out);
int ds_slist_remove_head(SList *list, int *out);
int ds_slist_remove_value(SList *list, int value);
void ds_slist_clear(SList *list);
SNode* ds_slist_find(const SList *list, int value);
void ds_slist_print_rec(SNode * start);

#endif //TP1_SLIST_H
