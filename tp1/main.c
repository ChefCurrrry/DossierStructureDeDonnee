#include <stdio.h>
#include "slist.h"


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);   // désactive le tampon de stdout
    SNode n1;
    n1.data = 10;
    n1.next = NULL;
    SNode n2 = {.data = 20, .next = NULL};

    SNode *p1 = &n1;
    printf("la data de n1 est %d \n", n1.data);
    printf("la data de n1 à travers p1 est %d \n", p1->data);
    printf("la data de n1 à travers p1 est %d \n", (*p1).data);

    n1.next = &n2;

    SList l1;
    ds_slist_init(&l1);
    l1.head = &n1;
    n1.next = &n2;
    ds_slist_print(&l1);
    // Attention : n1 et n2 sont sur la pile, il ne faut jamais appeler clear ou remove_* sur l1


    SList l2 = ds_slist_create();
    ds_slist_init(&l2);
    printf("\n*** Affichage de L2 lors de la creation \n");
    ds_slist_print(&l2);
    printf("\n*** Affichage de L2 après ajout \n");
    ds_slist_insert_tail(&l2, 100);
    ds_slist_insert_tail(&l2, 100);
    ds_slist_insert_head(&l2, 10);
    ds_slist_insert_head(&l2, 20);
    ds_slist_insert_head(&l2, 20);
    ds_slist_insert_head(&l2, 30);
    ds_slist_insert_tail(&l2, 40);
    ds_slist_insert_tail(&l2, 40);
    ds_slist_insert_head(&l2, 80);
    ds_slist_print(&l2);

    int ret;
    int val;
    printf("\n\n***Test ds_slist_is_empty\n");
    SList l3 = ds_slist_create();
    printf("l3 vide : %d (attendu : 1)\n", ds_slist_is_empty(&l3));
    printf("l2 vide : %d (attendu : 0)\n", ds_slist_is_empty(&l2));

    printf("\n\n***Test ds_slist_insert_at\n");

    printf("\n*** Indice négatif (attendu : retour = 0, L2 inchangée)\n");
    ret = ds_slist_insert_at(&l2, -1, 99);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Indice 0 (attendu : retour = 1, 35 en tête)\n");
    ret = ds_slist_insert_at(&l2, 0, 35);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Indice 3, au milieu (attendu : retour = 1, 67 entre 30 et 20)\n");
    ret = ds_slist_insert_at(&l2, 3, 67);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Indice 11, égal à la taille (attendu : retour = 1, 18 à la fin)\n");
    ret = ds_slist_insert_at(&l2, 11, 18);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Indice 13, taille + 1 (attendu : retour = 0, L2 inchangée)\n");
    ret = ds_slist_insert_at(&l2, 13, 90);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n\n***Test ds_slist_remove_tail\n");
    ret = ds_slist_remove_tail(&l2, &val);
    printf("retour = %d, valeur = %d (attendu : retour = 1, valeur = 18)\n", ret, val);
    ds_slist_print(&l2);

    printf("\n\n***Test ds_slist_remove_head\n");
    ret = ds_slist_remove_head(&l2, &val);
    printf("retour = %d, valeur = %d (attendu : retour = 1, valeur = 35)\n", ret, val);
    ds_slist_print(&l2);

    printf("\n\n***Test ds_slist_remove_value\n");

    printf("\n*** Valeur en tête : 80 (attendu : retour = 1)\n");
    ret = ds_slist_remove_value(&l2, 80);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Valeur au milieu, présente deux fois : 100 (attendu : retour = 1, une seule 100 retirée)\n");
    ret = ds_slist_remove_value(&l2, 100);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Valeur 40, première occurrence au milieu (attendu : retour = 1)\n");
    ret = ds_slist_remove_value(&l2, 40);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Valeur 40, maintenant en dernière position (attendu : retour = 1)\n");
    ret = ds_slist_remove_value(&l2, 40);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);

    printf("\n*** Valeur absente : 345 (attendu : retour = 0, L2 inchangée)\n");
    ret = ds_slist_remove_value(&l2, 345);
    printf("retour = %d\n", ret);
    ds_slist_print(&l2);


    printf("\n\n***Tests des cas limites sur L3 (liste vide puis à un seul élément)\n");

    printf("\n*** remove_tail sur liste vide (attendu : retour = 0)\n");
    ret = ds_slist_remove_tail(&l3, &val);
    printf("retour = %d\n", ret);

    printf("\n*** remove_head sur liste vide (attendu : retour = 0)\n");
    ret = ds_slist_remove_head(&l3, &val);
    printf("retour = %d\n", ret);

    printf("\n*** remove_value sur liste vide (attendu : retour = 0)\n");
    ret = ds_slist_remove_value(&l3, 5);
    printf("retour = %d\n", ret);

    printf("\n*** insert_at indice 0 sur liste vide (attendu : retour = 1, [5])\n");
    ret = ds_slist_insert_at(&l3, 0, 5);
    printf("retour = %d\n", ret);
    ds_slist_print(&l3);

    printf("\n*** insert_at indice 2 sur liste de taille 1 (attendu : retour = 0, [5])\n");
    ret = ds_slist_insert_at(&l3, 2, 7);
    printf("retour = %d\n", ret);
    ds_slist_print(&l3);

    printf("\n*** insert_at indice 1 sur liste de taille 1 (attendu : retour = 1, [5 -> 7])\n");
    ret = ds_slist_insert_at(&l3, 1, 7);
    printf("retour = %d\n", ret);
    ds_slist_print(&l3);

    printf("\n*** remove_head sur [5 -> 7] (attendu : retour = 1, valeur = 5, [7])\n");
    ret = ds_slist_remove_head(&l3, &val);
    printf("retour = %d, valeur = %d\n", ret, val);
    ds_slist_print(&l3);

    printf("\n*** remove_tail sur un seul élément (attendu : retour = 1, valeur = 7, [])\n");
    ret = ds_slist_remove_tail(&l3, &val);
    printf("retour = %d, valeur = %d\n", ret, val);
    ds_slist_print(&l3);

    printf("\n*** remove_value sur un seul élément (attendu : retour = 1, [])\n");
    ds_slist_insert_head(&l3, 9);
    ret = ds_slist_remove_value(&l3, 9);
    printf("retour = %d\n", ret);
    ds_slist_print(&l3);


    printf("\n\n***Test ds_slist_clear\n");

    printf("\n*** clear sur L2 (attendu : [])\n");
    ds_slist_clear(&l2);
    ds_slist_print(&l2);
    printf("l2 vide : %d (attendu : 1)\n", ds_slist_is_empty(&l2));

    printf("\n*** clear sur liste déjà vide (attendu : pas de crash, [])\n");
    ds_slist_clear(&l3);
    ds_slist_print(&l3);

    printf("\n*** Réutilisation de L2 après clear (attendu : [1 -> 2])\n");
    ds_slist_insert_tail(&l2, 1);
    ds_slist_insert_tail(&l2, 2);
    ds_slist_print(&l2);
    ds_slist_clear(&l2);



    printf("\n\n***Test ds_slist_find\n");
    SList l5 = ds_slist_create();
    printf("liste vide : %p (attendu : NULL)\n", (void *) ds_slist_find(&l5, 1));

    ds_slist_insert_tail(&l5, 1);
    ds_slist_insert_tail(&l5, 2);
    ds_slist_insert_tail(&l5, 3);

    SNode *n = ds_slist_find(&l5, 1);
    printf("tête : %d (attendu : 1)\n", n != NULL ? n->data : -1);
    n = ds_slist_find(&l5, 3);
    printf("dernier : %d (attendu : 3)\n", n != NULL ? n->data : -1);
    printf("absente : %p (attendu : NULL)\n", (void *) ds_slist_find(&l5, 42));

    ds_slist_clear(&l5);





    return 0;
}
