## Busca
- o computador pode olhar apenas para um elemento por vez em um vetor
  - para um vetor com ```n``` itens, o indice maximo é ```n-1```
### Big ```O```
- algoritmos de busca podem ter diferentes eficiências
- Big ```O``` é a descrição do tempo de execução de um algoritmo
  ![Big O](https://cs50.harvard.edu/college/2021/fall/notes/3/time_to_solve_zoomed_out.png)
- big Ω descreve o limite inferior do número de etapas para o algoritmo no melhor caso
- Big ⍬ descreve o tempo de execução do algoritmo se o limite superior e o inferior forem iguais

### Pesquisa Linear, Pesquisa Binária
__Busca Linear__:
```
for i from 0 to n - 1
    if number behind doors[i]
        return true
return false
```
- o big O para o algortimo acima é ```O(n)```
- o big Ω seria Ω(1), já que poderiamos encontrar de cara
__Busca Binária__:
```
if no doors
    return false
if number behind doors[middle]
    return true
else if number < doors[middle]
    search doors[0] through doors[middle - 1]
else if number > doors[middle]
    search doors[middle + 1] through doors[n - 1]
```
- o big O para o algortimo acima é ```O(log n)```, pois podemos continuar dividindo o número de portas por dois até que não haja mais portas
- o big Ω seria Ω(1), já que poderiamos encontrar de cara
- a pesquisa binária pode ser muito mais rápida que a linear, mas requer uma classificação do vetor
- se os dados forem buscados muitas vezes, vale a pena separá-los antes
- outros recursos a serem considerados além do tempo de execução são o tempo para escrever o código e a quantidade de memória necessária para o código

## Structs
codigo de agenda chamado ```phonebook0.c```:
```C
#include <cs50.h>
#include <stdio.h>
#include <string.h>
  
int main(void)
{
    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};
  
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], "David") == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
- os vetores names e numbers possuem relação, onde names[0] é dono do telefone numbers[0]
- em C, um novo tipo de data pode ser definido através de __structs__, que podem tornar um programa melhor desenhado
  ```C
    typedef struct {
        string name;
        string number;
    } person;
  ```
- agora, nomes e telefones podem ser acessados com person.name e person.number
- a encapsulação ocorreu quando os dados que possuem algum tipo de relação foram agrupados

## Ordenação
![Ordenação](https://cs50.harvard.edu/college/2021/fall/notes/3/sorting.png)
### Select Sort
- o melhor valor é selecionado e movido para a sua posição, trocando de posição com este valor
- a partir da troca, é buscado o menor valor maior que o anterior, e feito o mesmo procedimento
  - Ex: 2 3 1 -> 1 | 3 2 -> 1 2 | 3 -> 1 2 3
- o pseudocodigo abaixo representa este tipo de ordenação
```
for i from 0 to n - 1
    find smallest number between numbers[i] and numbers[n - 1]
    swap smallest number with numbers[i]
```
- a ordem deste algoritmo é O(n^2) e Ω(n^2)
### Bubble Sort
- ordenaremos os valores de pares em pares
  - Ex: 5 2 7 4 1 5 3 0 -> | 5 2 | 7 4 1 5 6 3 0
  2 | 5 7 | 4 1 6 3 0 -> ... -> 2 5 4 1 6 3 0 | 7
  - após isso, o processo será refeito, até que os números estejão ordenados (0 1 2 3 4 5 6 7)
- no __bubble sort__, o maior valor ficará ao fim, o segundo na penultima posição, e assim adiante
- o pseudocódigo deste tipo de ordenação é:
```
repeat n-1 times
    for i from 0 to n - 2
        if numbers[i] and numbers[i + 1] out of order
            swap them
        if no swaps
            quit
```
- a ordem deste algoritmo é O(n^2) e Ω(n)

## Recursão
- __recursão__ é a habilidade de uma função chamar ela mesma
- é importante que um caso básico seja definido, para não gerar um _loop_ infinito

## Merge Sort
- utiliza a ideia de recursão
```
if only one number
    quit
else
    sort left half of number
    sort right half of number
    merge sorted halves
```
- utiliza a estratégia "dividir para conquistar"
```
2 4 5 7 | 0 1 3 6

__2__ 4 5 7 | __0__ 1 3 6 -> 0
__2__ 4 5 7 | __1__ 3 6 -> 0 1
__2__ 4 5 7 | __3__ 6 -> 0 1 2
__4__ 5 7 | __3__ 6 -> 0 1 2 3
__4__ 5 7 | __6__ -> 0 1 2 3 4
__5__ 7 | __6__ -> 0 1 2 3 4 5
__7__ | __6__ -> 0 1 2 3 4 5 6
__7__ | -> 0 1 2 3 4 5 6 7
```
- podemos dividir várias vezes caso os valores estejam desordenados:
5 2 7 4
5 2 | 7 4
2 5 | 4 7
5 | 4 7 -> 2
5 | 7 -> 2 4
7 -> 2 4 5
2 4 5 7
- desta forma, os valores foram ordenados, coincidindo com a primeira metade do exemple acima dele
- a ordem deste algoritmo é O(nlogn), Ω(nlogn) e ⍬(nlogn), sendo o algoritmo mais eficiente