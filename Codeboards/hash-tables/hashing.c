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



int hash(char key[], int size) {
    int i, sum = 0;
    
    for(i = 0; key[i] != '\0'; i++)
        sum += key[i];
    
    return (sum % size);
}


void initHT(HT *h, int size) {
    int i;
    
    h->size = size;
    h->used = 0;
    h->tbl = calloc(size, sizeof(struct pair));
    
    for(i = 0; i < size; i++)
        strcpy(h->tbl[i].key, EMPTY);
}


int freeHT(HT *h, int k) {
    return (!strcmp(h->tbl[k].key, EMPTY) || !strcmp(h->tbl[k].key, DELETED));
}


int writeHT (HT *h, char key[], int value) {
    int i;
    
    for (i = hash(key, h->size); !freeHT(h, i); i = (i+1)%(h->size))
        printf("* ");
    
    strcpy(h->tbl[i].key, key);
    h->tbl[i].value = value;
    (h->used)++;
    
    return i;
}


int readHT (HT *h, char key[], int* value) {
    int i, pos, hashed;
    pos = hashed = hash(key, h->size);
    
    for (i = 1; strcmp(h->tbl[pos].key, EMPTY) && i < h->size; i++) {
        if (!strcmp(h->tbl[pos].key, key)) {
            *value = h->tbl[pos].value;
            return pos;
        }
        
        printf("* ");
        pos = (hashed+i)%(h->size);
    }
    
    return -1;
}


int deleteHT (HT *h, char key[]) {
    int r, v;
    r = readHT(h, key, &v);

    if (r > -1) {
        strcpy(h->tbl[r].key, DELETED);
        h->used--;
    }
    
    return r;
}