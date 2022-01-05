/* 
* Main function of the C program.
* https://codeboard.io/projects/10165
*/
#include <stdio.h>
#include <stdlib.h>

#include "minheap.h"

void print_heap(Heap h) {
    int i;
    for (i = 0; i < h.used; i++)
        printf("%d ", h.values[i]);
    printf("\n");
}

int main() {
    Heap h;
    int i, x;

    initHeap(&h, 1);
    
    insertHeap(&h, 30);
    print_heap(h);
    insertHeap(&h, 60);
    print_heap(h);
    insertHeap(&h, 40);
    print_heap(h);
    insertHeap(&h, 10);
    print_heap(h);
    insertHeap(&h, 100);
    print_heap(h);
    insertHeap(&h, 20);
    print_heap(h);
    insertHeap(&h, 90);
    print_heap(h);
    insertHeap(&h, 50);
    print_heap(h);
    insertHeap(&h, 80);
    print_heap(h);
    insertHeap(&h, 70);
    print_heap(h);
  
    printf("Heap construída (capacidade %d):\n", h.size);
    for (i = 0; i < h.used; i++)
        printf("%d\n", h.values[i]);

    minHeapOK(h);

    printf("Extracção de elementos:\n");
    while (!extractMin(&h, &x)) 
        printf("%d\n", x);
    
}
