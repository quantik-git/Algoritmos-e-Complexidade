
//
//  hashing.c
//  Hashing
//
//  Created by Jorge Sousa Pinto on 22/11/17.
//  Copyright © 2017 Jorge Sousa Pinto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "hashing.h"


int hash_sol(char key[], int size) {

    int i=0, sum=0;
    while(key[i] != '\0') sum += key[i++];
    
    return (sum % size);
}


void initHT_sol(HT *h, int size) {
    int i;
    h->tbl = calloc(size, sizeof(struct pair));
    h->size = size;
    h->used = 0;
    for (i=0; i<size; i++)
        strcpy(h->tbl[i].key, EMPTY);
}


int freeHT_sol(HT *h, int k) {
    if (strcmp((h->tbl)[k].key, EMPTY)==0) return 1;
    if (strcmp((h->tbl)[k].key, DELETED)==0) return 1;
    return 0;
}


int writeHT_sol (HT *h, char key[], int value) {
    int i;
    float load = h->used / h->size;
    
//    if (load > 0.8) grow (h, 2*(h->size));

    i = hash(key, h->size);
    
    while (!freeHT(h, i)) {
        i = (i+1)%(h->size);
        printf("* ");
    }
    
    strcpy((h->tbl)[i].key, key);
    (h->tbl)[i].value = value;
    h->used++;
    
    return i;
}



int readHT_sol (HT *h, char key[], int* value) {
    int i, ii;
    i = ii = hash(key, h->size);

    while (strcmp((h->tbl)[i].key, key) != 0) {
        if (strcmp((h->tbl)[i].key, EMPTY) == 0) return -1;
        i = (i+1)%(h->size); printf("* ");
        if (i == ii) return -1;
    }

    *value = (h->tbl)[i].value;
    return i;
}



int deleteHT_sol (HT *h, char key[]) {
    int r, v;

    r = readHT(h, key, &v);

    if (r >= 0) {
        strcpy((h->tbl)[r].key, DELETED);
        h->used--;
    }
    
    return r;
}





