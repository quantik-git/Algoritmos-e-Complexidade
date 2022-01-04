# 1 Especificações
## 1.
a) retorna o maior elemento  
b) retorna um divisor comum a `x` e `y`  
c) retorna um multiplo comum a `x` e `y`  
d) retorna um indice da lista onde está um elemento menor ou igual a todos os elementos  
e) retorna um `x` que é menor ou igual a todos os elementos da lista  
f) retorna um `x` que pertence à lista e é menor ou igual a todos os elementos da lista  
g) retorna -1 caso o elemento `x` não exista na lista o ou seu indice caso exista  

## 2.
a)  
pré: True  
pós: `r == x*y`  
b)  
pré: True
pós: `(x % r == 0 && y % r == 0) && nexists_{r < i < inf} x % i == 0 && y % i == 0`  
c)  
pré: N >= 0  
pós: `r == sum_{0 <= i < N} v[i]`  
d)  
pré: N >= 0
pós: `(N == 0 && r == 0) || (forall_{1 <= i < r} v[i-1] < v[i] && v[r] > v[r-1])`  
e)  
pré: N >= 0
pós: `forall_{1 <= i < N} v[i-1] < v[i]`  

# 2 Correção
## 1.
a) `x = 3, y = -1`  
b) `x = 3, y = 2`  
c) `x = 3, y = 3`  
d) `x = 3, y = 3`  
e) `x = 0, y = -1`  

## 2.
a) `x > 0 && y > 0`  
b) `x == y`  
c) `x != y`  
d) `x != y`  
e) `(x <= 0 && y > x) || (x > 0 && y > -x)` ou `y > -|x|`  

## 3.
a)
b)
c)
d)

# 3 Invariantes
## 1.
a)  
| Predicado | Init | Pres | Init | Pres |
|---|---|---|---|---|
| r == a * b | &#x274C; | &#x274C; | &#x274C; | &#x274C; |
| a >= 0 | &#10004; | &#10004; | &#10004; | &#10004; |
| b >= 0 | &#x274C; | &#x274C; | &#x274C; | &#x274C; |
| r >= 0 | &#10004; | &#x274C; | &#10004; | &#x274C; |
| a == x | &#10004; | &#x274C; | &#10004; | &#x274C; |
| b == y | &#10004; | &#10004; | &#10004; | &#x274C; |
| a * b == x * y | &#10004; | &#x274C; | &#10004; | &#x274C; |
| a * b + r == x * y | &#10004; | &#10004; | &#10004; | &#10004; |

b) `a * b + r == x * y && a >= 0`   

## 2.
Estes invariantes não devem ser fortes o suficiente para provar mas são a parte mais importante  
a) `0 <= r < i && (forall_{0 <= k < i} v[r] <= v[i])`  

b) `(exists_{0 <= r < i} r == v[p]) && (forall_{0 <= k < i} v[r] <= v[i])`  

c) `r == sum_{0 <= k < i} v[k]`  

d) `a * b + r = x^2`  

e) `r == i^2`  

f) `forall_{1 <= i < r} v[i-1] < v[i]`  

g) `(p == -1 && forall_{0 <= k < i} a[k] != x) || ((0 <= p < i) && x == a[p])`  
não sei se esta é mais útil `(p == -1 && forall_{0 <= k < i} a[k] != x) || (p == i-1 && x == a[p])`  

h) `r == (i-1) * i / 2`  

i) `n * (n+1) / 2 == (i * (i+1) / 2) + r`  

j) `exists_{q} x == q*y + r`  

k) `r == sum_{0 <= k < i} x^k * coef[k]`  

l) `r == sum_{i <= k < N} x^k * coef[k]`  

## 3.
Estes variantes não devem ser fortes o suficiente para provar mas são a parte mais importante  
a) `N-i`  

b) `N-i`  

c) `N-i`  

d) `a` ???  

e) `x-i`  

f) `N-r`  

g) `N-i`  

h) `n-i+1`  

i) `i`  

j) `r - (x % y)` ???  

k) `N-i`  

l) `i` 
