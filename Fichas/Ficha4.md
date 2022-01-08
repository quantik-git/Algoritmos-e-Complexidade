# 1 Representações

```c
define NV 5

typedef struct aresta {
    int dest;
    int custo;
    struct aresta *prox;
} *LAdj, *GrafoL [NV];

typedef int GrafoM [NV][NV];
```

## 1.
O(NV^2)
```c
void fromMat (GrafoM in, GrafoL out)
```

## 2.
O(NV+E)
```c
void inverte (GrafoL in, GrafoL out) {
    LAdj d, aux;

    for (o = 0; o < NV; o++)
        out[o] = NULL;

    for (o = 0; o < NV; o++) {
        d = in[o];
        while (d) {
            aux = malloc(sizeof(struct aresta));
            aux->dest = o;
            aux->custo = 1;
            aux->prox = out[d->dest];
            out[d->dest] = aux;
            d = d->prox;
        }
    }
}
```

## 3.
O(NV+E) sendo E o número de arestas do grafo
```c
int inDegree (GrafoL g) {
    int ind[NV], o, m = 0;
    LAdj d;

    for (o = 0; o < NV; o++)
        ind[o] = 0;

    for (o = 0; o < NV; o++)
        for (d = g[o]; d != NULL; d = d->prox)
            ind[d->dest]++;

    for (o = 0; o < NV; o++)
        if (ind[o] > m) m = ind[o];

    return m;
}
```

## 4.
O(NV+E)
```c
int colorOK (GrafoL g, int cor[]) {
    int o;
    LAdj d;

    for (o = 0; o < NV; o++)
        for (d = g[o]; d != NULL; d = d->prox)
            if(cor[o] == cor[d->dest])
                return 0;

    return 1;
}
```

## 5.
O(NV+E)
```c
int homomorfOK (GrafoL g, GrafoL h, int f[]) {
    int o;
    LAdj a, b;

    for (o = 0; o < NV; o++) {
        for (a = g[o]; a != NULL; a = a->prox) {
            for (b = h[f[a]]; b != NULL; b = b->prox)
                if(a->dest == f[b->dest])
                    break;
            
            if (b == NULL)
                return 0;
        }
    }

    return 1;
}
```


# 2 Travessias

## 1.
```c
int maisLonga (GrafoL g, int or, int p[]) {
    int i, r, max = or;
    int vis[NV], pai[NV], dist[NV];

    BF(g, or, vis, pai, dist);

    for (i = 0; i < NV; i++) {
        if (dist[i] > dist[max]) {
            max = i;
        }
    }

    r = dist[max];

    while (max != -1) {
        p[dist[max]] = max;
        max = pai[max];
    }

    return r;
}
```

## 2.
```c
int componentes (GrafoL g, int c[]) {
    int i, j, next = 0;
    int vis[NV], pai[NV], dist[NV];

    for (i = 0; i < NV; i++)
        c[i] = 0;

    for (i = 0; next < NV; i++) {
        BF(g, next, vis, pai, dist);

        for (j = 0, next = NV; j < NV; j++) {
            if (vis[j])
                c[j] = i+1;
            else if (c[j] == 0 && j < next)
                next = j;
        }
    }

    return i;
}
```

## 3.
```c
int ordTop (GrafoL g, int ord[]) {

}
```

## 4.
```c
typedef struct coord {
    int l;
    int c;
    int dist;
} coord;

coord newC(int l, int c) {
    coord n = {l, c, 0};
    return n;
}

int equals(coord a, coord b) {
    return a.l == b.l && a.c == b.c;
}

int valid(coord a, int L, int C, char mapa[L][C]) {
    return (a.l >= 0 && a.l < L) && (a.c >= 0 && a.c < C) && mapa[a.l][a.c] == ' ';
}

/*
* O array de visitados é necessário se não estivermos a escrever no array (ASCII print)
*/
int caminho (int L, int C, char mapa[L][C], int ls, int cs, int lf, int cf) {
    int front, end, vis[L][C], i, j;
    coord queue[2*L*C], curr, dest;

    front = end = 0;
    dest = newC(lf, cf);
    queue[end++] = newC(ls, cs); //enqueue

    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++)
            vis[i][j] = 0;

    while (front != end) {
        curr = queue[front++]; //dequeue

        if (equals(curr, dest)) {
            mapa[curr.l][curr.c] = '$';
            return curr.dist;
        }

        if (vis[curr.l][curr.c] == 1) {
            continue;
        } else {
            vis[curr.l][curr.c] = 1;
        }
        
        // ASCII print
        mapa[curr.l][curr.c] = curr.dist+'0';

        coord next_moves[4] = {
            {curr.l-1, curr.c, curr.dist+1},
            {curr.l+1, curr.c, curr.dist+1},
            {curr.l, curr.c-1, curr.dist+1},
            {curr.l, curr.c+1, curr.dist+1},
        };

        for (i = 0; i < 4; i++) {
            if (valid(next_moves[i], L, C, mapa)) {
                printf("*%d %d;  ", next_moves[i].l, next_moves[i].c);
                queue[end++] = next_moves[i];
            }
        }
    }

    return -1;
}
```