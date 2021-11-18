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


# 2 Definições Recursivas
## 1.
a) T(n) = k + T(n-1)
sum_{0 <= i < n} k + k' 
b)
sum_{0 <= i < log_2(n)} 2^i * k + k'
c)
(sum_{0 <= i < log_2(n)} 2^i) * k + 2^(log_2(n)) * k'
d) T(n) = n + T(n-1)
sum_{0 <= i < n} n + k' = n^2/2 + n/2 + k'
e)
(sum_{0 <= i < log_2(n)} n/2^i) + k'
f)
(sum_{0 <= i < log_2(n)} n/2^i) + 2^(log_2(n)+1) * k'
O(n * log_2(n))

## 2.
T(0) = 0
T(n) = n + T(n-1)
n^2/2 + n/2

## 3.
T(0) = 0
T(n) = k + 2 * T(n-1)
sum_{0 <= i < n} 2^i = 2^n -1

## 4.
T(0) = k
T(n) = k' + 2 * n + 2 * T(n/2)
O(n * log_2(n))

## 5.
1)
T(0) = k
T(n) = k' + 2 * T(n/2)
2)
T(0) = k
T(n) = k' + T(n-1) + T(0)


# 3 Análise de caso médio
## 1.
nº médio de comparações = (N-1) * (1/2)^(N-1) + sum_{0 < i < N} i * (1/2)^i  

maxcresc = sum_{0 <= i <= N-2} 2 - 1/(2^(N-i-2)

## 3.
N * (1/2)^N + sum_{1 <= i <= N} i * (1/2)^i

## 4.
N * (1/2)^N + sum_{1 <= i <= N} i * (1/2)^i

## 5.


