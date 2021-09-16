## Compilando
```C
#include <stdio.h>

int main(void) {
    printf("hello, world\n");
}
```

- Considerando o código acima como ```hello.c```, a compilação pode ser feita utilizando ```make hello```, e, após isso, o programa pode ser executado com ```./hello```
- ```make``` é um programa que chama ```clang```, um compilador para linguagem C
  - Logo, o código também pode ser compilado utilizando ```clang hello.c```, e, por convenção, gerará um arquivo chamado a.out
- _clang_ ainda suporta outros argumentos. Por exemplo:
  - ```clang -o hello hello.c``` gerará um arquivo de saída (```-o```) chamado ```hello```, que é o resultado da compilação do arquivo ```hello.c```
- A compilação é dividida em quatro passos:
    1. Pre-processamento: envolve a substituição de linhas que começam com _#_, copiando e colando esses conteúdos no programa
    2. Compilação: transforma o código-fonte e converte em uma linguagem chamada __linguagem assembly__, que contém instruções básicas de memória e nos valores
    3. Montagem: traduz o código assembly em binário, para a CPU executar diretamente
    4. Vinculação: vincula as bibliotecas incluídas com o binário compilado, combinando todo o código de máquina para ```hello.c``` e ```stdio.h``` no binário ```a.out```, ```hello``` ou o nome que for informado

## Depuração
- __*Bugs*__ sao erros que levam os programas a se comportarem de forma diferente da esperada, e a depuração é o processo de localização e correção desses _bugs_
- Para saber mais, (clique aqui)[https://cs50.harvard.edu/college/2021/fall/notes/2/#debugging]

## Memória
- cada tipo de variável ocupa um tamanho diferente na memória
| bool | 1 _byte_ |
| char | 1 _byte_ |
| double | 8 _bytes_ |
| float | 4 _bytes_ |
| int | 4 _bytes_ |
| long | 8 _bytes_ |
| string | ? _bytes_ |
- os chips de RAM (memória de acesso aleatório) armazenam 0s e 1s, e podemos imaginar os _bytes_ armazenados como uma grade, um após o outro:
    ![RAM](https://cs50.harvard.edu/college/2021/fall/notes/2/ram.png)
    - existem milhões ou bilhões de _bytes_ por chip

## Vetores
```C
#include <stdio.h>

int main(void) {
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
```
- o programa acima calcula a média, e seu design não é o ideal
- enquanto o programa é executado, o seguinte ocorre na memória:
    ![media](https://cs50.harvard.edu/college/2021/fall/notes/2/scores.png)
    - cada variável ```int``` ocupa 4 _bytes_, sendo que, que _byte_ é composto por oito bits:
        ![media/bits](https://cs50.harvard.edu/college/2021/fall/notes/2/binary.png)
- o programa poderia ser otimizado utilizando uma variável domposto chamada __vetor__, que armazena valores do mesmo tipo de forma contígua na memória
- O usuário ainda pode informa a quantidade de valores e os valores que deseja
```C
#include <stdio.h>

int main(void) {
    /* n armazena a quantidade de valores a ser informada, e deve ser maior que 0 */
    int n;
    do {
        printf("How many scores? ");
        scanf("%i", &n);
    } while(n < 1);
    float scores[n]; /* entre [], a quantidade de valores que deseja armazenar no vetor */

    float sum = 0;
    for(int i = 0; i < n; i++) {
        printf("Score: ");
        scanf("%f", scores[i]);
        sum += scores[i]
    }

    printf("Average: %f/n", sum / n);
}
```

## Strings
- _String_ é um vetor do tipo ```char```, que ocupa o tamanho de _n+1 bytes_, onde _n_ corresponde ao tamanho da _string_
- toda string é encerrada por ```\0```, também chamado de caractere nulo
  - o caractere nulo é um _byte_ onde todos os _bits_ correspondem a 0. Por isso seu nome
- a biblioteca (```string```)[https://manual.cs50.io/#string.h] contém várias operações para este tipo de variável

## Criptografia
- Pode-se considerar o texto das frases e seu nível de legibilidade com base em fatores como o comprimento e a complexidade das palavras e frases
- A criptografia é a arte de embaralhar as informações para ocultar o seu conteúdo. A mensagem original é chamada de __texto simples__, e a mensagem criptografada é chamada de __texto cifrado__, sendo que o algoritmo que faz o embaralhamento é chamado __cifra__, que geralmente necessita de outra entrada além do texto simples, como, por exemplo, uma __chave__, que é mantida em segredo
[criptografia](https://cs50.harvard.edu/college/2021/fall/notes/2/cipher.png)

- Exemplo: usando ```-1``` como chave para a mensagem ```UIJT XBT DT50``` obtermos ```THIS WAS CS50```