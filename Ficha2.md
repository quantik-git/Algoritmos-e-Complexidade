# 1 Contagem
## 1.
a)  
**melhor caso:** array ordenado  
**pior caso:** array com ordem invertida  
nº comparações = sum_{0 < i < N} i  

b)  
**melhor caso:** array ordenado  
**pior caso:** array com ordem invertida  
nº comparações melhor caso = sum_{0 < i < N} 1  
nº comparações pior caso = sum_{0 < i < N} i  


## 2.
a)  
nº comparações = 2 * x  
melhor caso é ter 2^(n-1)  
pior caso é ter 2^n-1  

b)  
nº comparações = 3 * (log_2(x) + 1) + nº de ocorrências de impares  
melhor caso é ter `100...0`  
pior caso é ter `111...1`  


## 3.
a) sum_{0 < i < N} sum_{i <= j < N} j-i+1  

b)  
```c
int maxSoma (int v[], int N) {
  int i, j, r, m, c[N];
  c[0] = v[0];
  r = c[0]
  for (i = 1; i<N; i++)
    c[i] = (c[i-1] + v[i] > v[i]) ? c[i-1] + v[i] : v[i];
  for (i = 1; i<N; i++)
    if (c[i] > r) r = c[i];
  return r;
}

// otimização máxima

int maxSoma (int v[], int N) {
  int i, j, r, m;
  r = c[0]
  for (i = 1; i<N; i++)
    r = (r + v[i] > v[i]) ? r + v[i] : v[i];
    // r = (r + v[i] > v[i]) * r + v[i];
  return r;
}
```

## 4.
**melhor caso:** array por ordem decrescente  
**pior caso:** array por ordem crescente  
nº = comprimento dos segmentos crescentes
