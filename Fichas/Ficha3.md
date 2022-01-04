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

// bottom-up
void heapify (int v[], int N) {
  for(int i = parent(N-1); i >= 0; i--)
    bubbleDown(i, q->valores, N);
}

// falta determinar complexidade
```


## 6.
```c
void ordenaHeap(int h[], int N) {
  for (int i = 1; i < N; i++) {
    swap(h, 0, N-i);
    bubbleDown(i, h, N-i);
  }
}
```


## 7.
Assumindo `add = O(log(N))` e `remove = O(log(N))`, o pior caso seria dar os elemento de forma crescente. Sendo assim efetuados N add's e (N-k) remove's.  
`O(N*log(k) + (N-k)*log(k)) = O(N*log(k))`  
No caso de uma lista ligada a inserção na cauda seria `O(k)` e a remoção da cabeça seria `O(1)`, o pior caso seria dar os elemento de forma crescente. Sendo assim efetuados N insert's e (N-k) remove's.  
`O(N*k + (N-k)) = O(N*k)`  



# 2 Tabelas de Hash
Vamos por isso assumir a existência de uma função `unsigned hash (char *chave)`, como
por exemplo a seguinte (http://www.cse.yorku.ca/~oz/hash.html)
```c
unsigned hash(char *str){
  unsigned hash = 5381;
  int c;
  
  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  
  return hash % Size; // alterado aqui por conveniência
}
```


## 2.1 Chaining
```c
#define Size 11

typedef struct nodo {
  char *chave;
  int ocorr;
  struct nodo *prox;
} Nodo, *THash [Size];
```

## 1.
```c
void initEmpty (THash t) {
  for (int i = 0; i < Size; i++)
    t[i] = NULL;
}
```

## 2.
```c
void add (char *s, THash t) {
  unsigned hashed = hash(s);
  Nodo* ptr, ant = NULL;
  
  for (ptr = t[hashed]; ptr != NULL; ptr = ptr->prox) {
    if (!strcmp(ptr->chave, s)) {
      ptr->ocorr++;
      return;
    }
    
    ant = ptr;
  }
  
  ptr = calloc(sizeof(Nodo));
  strcpy(ptr->chave, s);
  ptr->ocorr = 1;
  ptr->prox = NULL;

  if (ant != NULL)
    ant->prox = ptr;
  else
    t[hashed] = ptr;
}
```

## 3.
```c
int lookup (char *s, THash t) {
  unsigned hashed = hash(s);
  
  for (Nodo* ptr = t[hashed]; ptr != NULL; ptr = ptr->prox)
    if (!strcmp(ptr->chave, s))
      return ptr->ocorr;
  
  return 0;
}
```

## 4.
```c
int remove (char *s, THash t) {
  unsigned hashed = hash(s);
  Nodo* ptr, ant = NULL;
  
  for (ptr = t[hashed]; !strcmp(ptr->chave, s); ptr = ptr->prox) {
    if (ptr == NULL) return -1;
    ant = ptr;
  }
  
  ptr->ocorr--;
      
  if (ptr->ocorr == 0) {
    if (ant != NULL)
      ant->prox = ptr->prox;
    else
      t[hashed] = ptr->prox;

    free(ptr);
  }

  return 0;
}
```

## 2.2 Open Addressing
```c
#define Size 11
#define Free 0
#define Used 1
#define Del 2

typedef struct bucket {
  int status; // Free | Used | Del
  char *chave;
  int ocorr;
} THash [Size];
```

## 1.
```c
int where (char *s, THash t) {
  int c, hash = 5381;

  while (c = *str++)
    hash *= 33 + c;

  return hash % Size;
}
```

## 2.
```c
// a)
void initEmpty(THash t) {
  for (int i; i < Size; i++) {
    t[i].status = Free;
    t[i].chave = NULL;
    t[i].ocorr = 0;
  }
}

// b)
void add (char *s, THash t) {
  int i, pos, hashed;
  pos = hashed = where(s);

  for (i = 1; t[pos].status > Free && i <= Size; i++) {
    if(!strcmp(t[pos].chave, s)) {
      (t[pos].ocorr)++;
      return;
    }

    pos = (hashed+i) % Size;
  }

  if (t[pos].status == Free) {
    t[pos].status = Used;
    strcpy(t[pos].chave, s);
    t[pos].ocorr = 1;
  } else {
    printf("
      Erro na inserção:\n
      Table cheia ou a precisar de garbage collection\n
    ");
  }
}

// c)
int lookup (char *s, THash t) {
  int i, pos, hashed;
  pos = hashed = where(s);
  
  for (i = 1; t[pos].status > Free && i <= Size; i++) {
    if(!strcmp(t[pos].chave, s)) {
      return t[pos].ocorr;
    }

    pos = (hashed+i) % Size;
  }
  
  return -1;
}

// d)
int remove (char *s, THash t) {
  int i, pos, hashed;
  pos = hashed = where(s);

  for (i = 1; strcmp(t[pos].chave, s); i++) {
    if(t[pos].status == Free || i == Size)
      return 1;

    pos = (hashed+i) % Size;
  }

  (t[pos].ocorr)--;

  if (t[pos].ocorr == 0) {
    t[pos].status = Del;
    t[pos].chave = NULL;
  }

  return 0;
}
```

## 3.
```c
void copy (char *s, int ocorr, THash t) {
  int i;

  for (i = where(s); t[i].status == Used; i = (i+1) % Size);

  t[i].status = Used;
  strcpy(t[i].chave, s);
  t[i].ocorr = ocorr;
}

int garb_collection (THash t) {
  char *keys[Size];
  int i, c = 0, ocorrs[Size];

  for(i = 0; i < Size; i++)
    if (t[i].status == Used) {
      strcpy(keys[c], t[i].chave);
      ocorrs[c] = t[i].ocorr;
      c++;
    }

  initEmpty(t);

  for (i = 0; i < c; i++) {
    copy(keys[i], ocorrs[i], t);
  }

  return 0;
}
```

## 4.
```c
typedef struct bucket {
  int status; // Free | Used | Del
  char *chave;
  int ocorr;
  int colided;
} THash [Size];

// Não percebo pelo enunciado qual é a forma que devemos contar as colisões
```