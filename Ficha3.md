# 1 Min-heaps
## 1.  
a) 2 * i + 1  
b) 2 * i + 2  
c) (i - 1) / 2  
d) pai(n) + 1  

## 2.
```c
void bubbleUp (int i, int h[]) {
  while(i > 0 && h[i] < h[parent(i)]) {
    swap(h, i, parent(i));
    i = parent(i);
  }
}
// one-liner
void bubbleUp (int i, int h[]) {
  for(; i > 0 && h[i] < h[parent(i)]; swap(h, i, parent(i)), i = parent(i));
}
```

## 3.
```c
void bubbleDown (int i, int h[], int N) {
  int m;
  while(left(i) < N) {
    m = (right(i) < N && h[right(i)] < h[left(i)]) ? right(i) : left(i);
    
    if (h[m] > h[i]) break;
    
    swap(h, i, m);
    i = m;
  }
}
```

## 4
```c
#define Max 100
typedef struct pQueue {
  int valores [Max];
  int tamanho;
} PriorityQueue;

void empty (PriorityQueue *q) {
  q->tamanho = 0;
}

int isEmpty (PriorityQueue *q) {
  return (q->tamanho == 0);
}

int add (int x, PriorityQueue *q) {
  if(q->tamanho == Max) return 1;
  
  q->valores[q->tamanho] = x;
  bubbleUp(q->tamanho, q->valores);
  q->tamanho++;
  
  return 0;
}

int remove (PriorityQueue *q, int *rem) {
  rem = q->valores[0];
  q->valores[0] = q->valores[q->tamanho - 1];
  q->tamanho--;
  bubbleDown(0, q->valores, q->tamanho);
}
```

## 5.
```c
// top-down
void heapify (int v[], int N) {
  for (int i = 1; i < N; i++)
    bubbleUp (i, q->valores);
}

// bottom-up not sure
void heapify (int v[], int N) {
  for(i = parent(N-1); i > 0; i--)
    bubbleDown(i, q->valores, N);
}

// falta determinar complexidade
```


```c```
