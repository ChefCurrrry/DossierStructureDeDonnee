//
// Created by Kirankumar KICHENASSAMY on 23/10/2026.
//

#include "slist.h"

#include <stdio.h>
#include <stdlib.h>

void ds_slist_init(SList *plist) {
    plist->head = NULL;
}

SList ds_slist_create() {
    SList plist;
    plist.head = NULL;
    return plist;
}

int ds_slist_is_empty(const SList *plist) {
    return plist->head == NULL;
}

SNode * ds_slist_create_node(int data) {
    SNode * node = (SNode *) malloc(sizeof(SNode));
    //Verification
    if (node == NULL) {
        fprintf(stderr,"ds_slist_create_node: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void ds_slist_print(const SList *plist) {
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

int ds_slist_insert_head(SList *plist, int data) {
    SNode * node = ds_slist_create_node(data);
    node->next = plist->head;
    plist->head = node;
    return 1; //je ne gère pas le prob malloc, parce que exit utilisé dans create node

}
int ds_slist_insert_tail(SList *plist, int data) {
    SNode * node = ds_slist_create_node(data);
    if (ds_slist_is_empty(plist)) {
        plist->head = node;
    }
    else {
        SNode * current = plist->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    return 1; //je ne gère pas le prob malloc, parce que exit utilisé dans create node
}

int ds_slist_insert_at(SList *list, int index, int value) {

    if (index < 0) {
        fprintf(stderr,"ds_slist_insert_at : L'index ne peut pas être négatif. \n");
        return 0;
    }
    if (index == 0) {
        return ds_slist_insert_head(list, value);
    }
    if (ds_slist_is_empty(list)) {
        fprintf(stderr, "ds_slist_insert_at: Index %d is out of bounds\n", index);
        return 0;
    }
    SNode * current = list->head;
    int indexTemp = 0;
    while (current->next != NULL && indexTemp < index - 1) {
        current = current->next;
        indexTemp++;
    }
    if (indexTemp < index - 1) {
        fprintf(stderr, "ds_slist_insert_at: Index %d is out of bounds\n", index);
        return 0;
    }
    SNode * node = ds_slist_create_node(value);
    node->next = current->next;
    current->next = node;
    printf("Noeud inséré à l'indice %d .\n", index);
    return 1;
}

int ds_slist_remove_tail(SList *list, int *out) {
    if (ds_slist_is_empty(list)) {
        fprintf(stderr,"ds_slist_remove_tail: La liste est vide rien à supprimer. \n");
        return 0;
    }
    SNode * current = list->head;
    if (list->head->next == NULL) {
        *out = list->head->data;
        free(list->head);
        list->head = NULL;
        return 1;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    *out = current->next->data;
    free(current->next);
    current->next = NULL;
    printf("La dernière valeur %d à été supprimée. \n", *out);
    return 1;
}

int ds_slist_remove_head(SList *list, int *out) {
    if (ds_slist_is_empty(list)) {
        fprintf(stderr,"ds_slist_remove_tail: La liste est vide rien à supprimer. \n");
        return 0;
    }
    SNode * aSupprimer = list->head;
    list->head = aSupprimer->next;
    *out = aSupprimer->data;
    free(aSupprimer);
    printf("La valeur de tête %d à été supprimée. \n", *out);
    return 1;
}

int ds_slist_remove_value(SList *list, int value) {
    SNode * current = list->head;
    SNode * previous = NULL;
    int valSuppr;
    while (current != NULL) {
        if (current->data != value) {
            previous = current;
            current = current->next;
        }
        else {
            if ( current == list->head ) {
                ds_slist_remove_head(list, &valSuppr);
                return 1;
            }
            if (current->next == NULL) {
                ds_slist_remove_tail(list, &valSuppr);
                return 1;
            }
            previous->next = current->next;
            free(current);
            printf("La valeur %d a été supprimée de la liste.\n", value);
            return 1;
        }
    }
    fprintf(stderr,"La valeur %d n'est pas présente dans la liste.\n", value);
    return 0;
}

void ds_slist_clear(SList *list) {
    SNode * current = list->head;
    SNode * nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        list->head = nextNode;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
}


SNode* ds_slist_find(const SList *list, int value) {
    SNode * current = list->head;
    if (ds_slist_is_empty(list)) {
        fprintf(stderr,"La liste est vide");
    }
    while (current != NULL) {
        if (current->data == value) {
            printf("Noeud avec la valeur %d a été trouvé \n", value);
            return current;
        }
        current = current->next;
    }
    printf("La valeur %d n'a pas été trouvée dans la liste.\n", value);
    return NULL;
}


void ds_slist_print_rec(SNode * start) {
    if (start) {
        ds_slist_print_rec(start->next);
        printf("%d ", start->data);
    }
}