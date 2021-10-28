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
pré: ?
pós: `(x % r == 0 && y % r == 0) && nexists_{r < i < inf} x % i == 0 && y % i == 0`  
c)  
pré: True  
pós: `r == sum_{0 <= i < N} v[i]`  
d)  
pré: ?
pós: `forall_{1 <= i < r} v[i-1] < v[i]`  
e)  
pré: ?
pós: `r == forall_{1 <= i < N} v[i-1] < v[i]`  

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


## 3.
