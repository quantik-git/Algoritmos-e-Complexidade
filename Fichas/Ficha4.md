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
    LAdj vis[NV], pai[NV], dist[NV];

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
// não tenho a certeza se funciona
int componentes (GrafoL g, int c[]) {
    int i, j, next = 0;
    LAdj vis[NV], pai[NV], dist[NV];

    for (i = 0; next < NV; i++) {
        BF(g, next, vis, pai, dist);

        for (j = 0, next = NV; j < NV; j++) {
            if (c[j] == 0 && vis[j] != 0)
                c[j] = i;
            else if (c[j] == 0 && j < next)
                next = j;
        }
    }
}
```

## 3.
```c
int ordTop (GrafoL g, int ord[]) {

}
```

## 4.
```c
int caminho (int L, int C, char *mapa[L], int ls, int cs, int lf, int cf) {
    
}
```