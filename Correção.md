# Correção

## Triplo de Hoare
O triplo de Hoare é uma das ferramentas utilizadas para provar a correção **parcial** de um programa. Representa-se assim:  

{P} S {Q}  

P - pré-condição  
S - programa  
Q - pós-condição  

O triplo é válido se para qualquer pré-condição válida a pós-condição também for válida após a execução do programa.

### Atribuição
Lidámos com a atribuição fazendo subtituições da variável livre pelos valores atribuídos.  
* (x+y)[x\x-y] é (x-y)+y após substituirmos 
* (x + <img src="https://i.upmath.me/svg/%5Csum_%7B0%20%3C%3D%20y%20%3C%3D%20n%7D%20y%5E2" alt="\sum_{0 &lt;= y &lt;= n} y^2" />)[y\y+1] fica igual porque o y não é uma variável livre

### Sequenciação
Para a sequenciação começámos com a última operação e vamos subindo.
```c
{ x = x_0 && y = y_0 }
  x = x + y;
  y = x - y;
  x = x - y;
{ x = y_0 && y = x_0 }


{ x = y_0 && y = x_0 }[x \ x - y]
= { x - y = y_0 && y = x_0 }
{ x - y = y_0 && y = x_0 }[y \ x - y]
= { x - (x - y) = y_0 && x - y = x_0 }
= { y = y_0 && x - y = x_0 }
{ y = y_0 && x - y = x_0 }[x \ x + y]
= { y = y_0 && x + y - y = x_0 }
= { y = y_0 && x = x_0 }

// Da pós-condição conseguimos chegar à pré-condição por isso o triplo é válido
```

### Condicionais
Para os condicionais temos de verificar a correção para todos os ramos criados.
```c
if (x > y)
  M = x;
else
  M = y;

// esta condição cria dois ramos um em que x > y e outro em que x ≤ y portanto verificamos a correção para os dois

(x > y ∧ x = x_0 ∧ y = y_0)
=> (M = max(x_0, y_0))[M \ x]
=> x = max(x_0, y_0)
(x ≤ y ∧ x = x_0 ∧ y = y_0)
=> (M = max(x_0, y_0))[M \ y]
=> y = max(x_0, y_0)
```


### Ciclos
Para os ciclos temos de encontrar um **invariante de ciclo** algo que é verdade antes e após cada iteração do ciclo. As premissas a provar para mostrar a validade do ciclo são as seguintes:  
1. P => I: Antes da execução do ciclo, o invariante é verdadeiro;
2. {I && c} S {I}: Assumindo que o invariante é válido antes de uma iteração do ciclo, ele continua válido depois dessa iteração;
3. (I && ~c) => Q: Quando o ciclo termina a pós-condição é estabelecida.

```c
// multiplicação através de somas sucessivas
{ x = x_0 && y = y_0 >= 0 }
m = 0; d = y;
while (d>0) {
  m = m + x;
  d = d-1;
}
{ m = x_0 * y_0}
```

Algo que nos pode ajudar a descobrir o invariante é fazer uma tabela em que simulamos o programa e guardamos os valores das variáveis. Por exemplo `x=5` e `y=6`:

| Indice | x | y | d | m |
|---|---|---|---|---|
| 0 | 5 | 6 | 6 | 0 |
| 1 | 5 | 6 | 5 | 5 |
| 2 | 5 | 6 | 4 | 10 |
| 3 | 5 | 6 | 3 | 15 |
| 4 | 5 | 6 | 2 | 20 |
| 5 | 5 | 6 | 1 | 25 |
| 6 | 5 | 6 | 0 | 30 |

Analisando a tabela podemos ver que o valor de `m` são os múltiplos de `x` e que `x` e `y` mantêm sempre os seus valores originais. Podemos assim conjeturar um invariante `(x = x_0) && (y = y_0) && (m = x * (y-d))`. Este parece um bom invariante porque se olharmos para a sua última parte `m = x * (y-d)` esta expressão traduz adequadamente o "trabalho" que estamos a fazer no ciclo de somar sucessivamente e que eventualmente nos irá levar à pós-condição `m = x_0 * y_0`.  
Vamos agora tentar fazer a demontração:
1. (x = x_0 && y = y_0 ≥ 0) => (I[m \ 0, d \ y])  
<=> (x = x_0 && y = y_0 ≥ 0) => (x = x_0) && (y = y_0) && (0 = x * (y-y))  
<=> (x = x_0 && y = y_0 ≥ 0) => (x = x_0) && (y = y_0) && (0 = x * 0) 
2. (I && d > 0) => (I[m \ m + x, d \ d − 1])  
<=> (x = x_0) && (y = y_0) && (m = x * (y-d)) && (d > 0) => (x = x_0) && (y = y_0) && (m + x = x * (y-d+1))
3. (I && ¬(d > 0)) => (m = x_0 ∗ y_0)  
<=> (x = x_0) && (y = y_0) && (m = x * (y-d)) && (d <= 0) => (m = x_0 ∗ y_0)  
<=> (m = x_0 * (y_0-d)) && (d <= 0) => (m = x_0 ∗ y_0)  
Nesta parte falhámos

Na última parte falhámos porque não conseguimos mostrar que `d == 0` no final do ciclo. Uma propriedade que nos permite fortalecer o invariante e fazer a demonstração completa é `d >= 0` que em conjunção com `d <= 0` nos dará `d == 0` permitindo assim fazer a demonstração completa.  
**Cada vez que o invariante é alterado têm de provar de novo as 3 propriedades.**

## Correção Total
Para provar a correção total de um programa temos de demonstrar que o mesmo **termina**. Isto é algo trivial para todas os casos anteriores exceptuando os ciclos. Para demonstrar que um ciclo termina temos de introduzir o conceito de **variante**. Enquanto o **invariante** de um ciclo é um predicado que mostrarmos ser sempre válido, o **variante**  de um ciclo é uma expressão **inteira** que:
1. decresce estritamente em cada iteração do ciclo;
2. permanece sempremaior do que um determinado valor (tipicamente 0);

Olhando  para o programa anterior da multiplicação através de somas sucessivas é claro que o variante é `d`. É inteiro e estritamente decrescente e atinge o valor 0 quando o ciclo termina. Noutros ciclos mais típicos temos um indíce `i` que vai crescendo até atingir um limite superior `N` nesse caso apenas `i` não seria um variante porque apesar de ser inteiro não é estritamente decrescente, basta um pouco de aritmética para o tornar num variante funcional `N-i`.












