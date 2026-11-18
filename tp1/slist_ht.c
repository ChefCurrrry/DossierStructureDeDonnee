//
// Created by Kirankumar KICHENASSAMY on 06/11/2026.
//

#include "slist_ht.h"
#include <stdio.h>
#include <stdlib.h>


SList_HT ds_slist_ht_create() {
    SList_HT plist;
    plist.head = NULL;
    plist.tail = NULL;
    return plist;
}

int ds_slist_ht_is_empty(const SList_HT  *plist) {
    return !plist->head && !plist->tail;
}

void ds_slist_ht_init(SList_HT *plist) {
    plist->head = plist->tail = NULL;
}


int ds_slist_ht_insert_head(SList_HT *plist, int data) {
    SNode * node = ds_slist_create_node(data);
    if (!node) return 0;

    node->next = plist->head;
    plist->head = node;
    if (plist->tail == NULL) {
        plist->tail = node;
    }
    return 1;
}


int ds_slist_ht_insert_tail(SList_HT *plist, int data) {
    SNode * node = ds_slist_create_node(data);
    if (!node) return 0;

    node->next = NULL;
    if (ds_slist_ht_is_empty(plist)) {
        plist->head = node;
    } else {
        plist->tail->next = node;
    }
    plist->tail = node;
    return 1;
}


void ds_slist_ht_print(const SList_HT  *plist) {
    printf("[");
    SNode * current = plist->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}


SNode* ds_slist_ht_find(const SList_HT *list, int value) {
    SNode *current = list->head;
    SNode *res = NULL;
    while (current && !res) {
        if (current->data == value) res = current;
        current = current->next;
    }
    return res;
}


int ds_slist_ht_insert_at(SList_HT *list, int data, int position) {
    int op_ok = 0;
    if (position == 0) return ds_slist_ht_insert_head(list, data);
    else if (position > 0) {
        SNode * cur = list->head;
        int i = 0;
        while (cur && i < position - 1) {
            cur = cur->next;
            i++;
        }
        if (cur) {
            SNode * newNode = ds_slist_create_node(data);
            if (!newNode) return 0;
            newNode->next = cur->next;
            cur->next = newNode;
            if (cur == list->tail) list->tail = newNode;
            op_ok = 1;
        }
    }
    return op_ok;
}

int ds_slist_ht_remove_head(SList_HT *list, int *out) {
    if (ds_slist_ht_is_empty(list)) return 0;

    SNode * old = list->head;
    if (out) *out = old->data;

    list->head = old->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(old);
    return 1;
}


int ds_slist_ht_remove_tail(SList_HT *list, int *out) {
    if (ds_slist_ht_is_empty(list)) return 0;

    if (list->head == list->tail) {
        return ds_slist_ht_remove_head(list, out);
    }

    SNode * prev = list->head;
    while (prev->next != list->tail) {
        prev = prev->next;
    }

    if (out) *out = list->tail->data;
    free(list->tail);
    prev->next = NULL;
    list->tail = prev;
    return 1;
}


int ds_slist_ht_remove_value(SList_HT *list, int value) {
    if (ds_slist_ht_is_empty(list)) return 0;

    if (list->head->data == value) {
        return ds_slist_ht_remove_head(list, NULL);
    }

    SNode * prev = list->head;
    while (prev->next && prev->next->data != value) {
        prev = prev->next;
    }

    if (prev->next == NULL) return 0;
    SNode * to_delete = prev->next;
    prev->next = to_delete->next;
    if (to_delete == list->tail) {
        list->tail = prev;
    }
    free(to_delete);
    return 1;
}


void ds_slist_ht_clear(SList_HT *list) {
    SNode * current = list->head;
    while (current) {
        SNode * next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
}