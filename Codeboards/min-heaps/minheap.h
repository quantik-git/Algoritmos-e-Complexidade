
#define PARENT(i) (i-1)/2  // os indices do array começam em 0 
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

typedef int Elem;  // elementos da heap.

typedef struct {
 int   size;
 int   used;
 Elem  *values;
} Heap;

void initHeap (Heap *h, int size); 
int  insertHeap (Heap *h, Elem x);
int  extractMin (Heap *h, Elem *x);
int minHeapOK (Heap h); 

void initHeap_sol (Heap *h, int size); 
int  insertHeap_sol (Heap *h, Elem x);
int  extractMin_sol (Heap *h, Elem *x);
