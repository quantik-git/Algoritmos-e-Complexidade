#include <stdlib.h>

#include "minheap.h"



void swap(Elem h[], int a, int b) {
    Elem aux = h[a];
    h[a] = h[b];
    h[b] = aux;
}


void initHeap (Heap *h, int size) {
    h->values = calloc(size, sizeof(Elem));
    h->size = size;
    h->used = 0;
}


void bubbleUp (Elem h[], int i) {
    while(i > 0 && h[i] < h[PARENT(i)]) {
        swap(h, i, PARENT(i));
        i = PARENT(i);
    }
}


int  insertHeap (Heap *h, Elem x) {
    if (h->size == h->used) {
        h->values = realloc(h->values, 2*(h->size)*sizeof(Elem));
        h->size *= 2;
    }
    
    h->values[h->used] = x;
    bubbleUp(h->values, h->used);
    (h->used)++;
    
    return 0;
}


void bubbleDown (Elem h[], int N) {
    int m, i = 0;
    
    while(LEFT(i) < N) {
        m = (RIGHT(i) < N && h[RIGHT(i)] < h[LEFT(i)]) ? RIGHT(i) : LEFT(i);
        
        if (h[m] > h[i]) break;
        
        swap(h, i, m);
        i = m;
    }
}


int  extractMin (Heap *h, Elem *x) {
    if (h->used < 1)
        return 1;
    
    *x = h->values[0];
    (h->used)--;
    h->values[0] = h->values[h->used];
    
    bubbleDown(h->values, h->used);
    
    return 0;
}


int minHeapOK (Heap h) {
    int i;
    
    for (i = 0; i <= PARENT(h.used); i++)
        if (LEFT(i) < h.used && h.values[i] > h.values[LEFT(i)] || RIGHT(i) < h.used && h.values[i] > h.values[RIGHT(i)])
            return 1;
    
    return 0;
}