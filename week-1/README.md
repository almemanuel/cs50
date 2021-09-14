## Linguagem C
- A meta não deve ser aprender uma linguagem de programação, mas sim, como programar
- Com o passar do tempo, a sintaxe torna-se familiar, mesmo que, no início, possa parecer obscuro
- A qualidade de um código pode ser avaliada considerando:
  1. Exatidão: o código deve resolver o problema corretamente
  2. Design: o código deve ser bem escrito, eficiente e legível
  3. Estilo: o código deve ser visualmente bem formatado
- O programa abaixo simplesmente imprime "hello, world"

```C
#include <stdio.h>

int main() {
    printf("hello, world\n");
}
```
Para fins de organização, chamaremos o código acima de ```hello.c```

## IDEs, compiladores, interfaces
- Para transformar o código em um programa executável, é necessário traduzi-lo para binário
- As __IDEs__ (ambientes de desenvolvimento integrados) incluirão recursos para escrever, traduzir e executar o código
- Após salvar um código, é necessário converte-lo em linguagem de máquina, que representam as instruções que o computador deve operar em baixo nível
- __Compilador__ é um programa que converte uma linguagem em outra
    ![Processo de compilação](https://cs50.harvard.edu/college/2021/fall/notes/1/compiler.png)
- O terminal fornece uma __interface de linha de comando__ (CLI), permitindo executar vários comandos
  1. Para compilar nosso programa, no diretório dele, podemos digitar ```make hello```, que criará o arquivo chamado ```hello```
  2. Após isso, para executá-lo, podemos digitar ```./hello```, onde ```.``` informa que o arquivo ```hello``` está na pasta atual
  3. Para excluir o arquivo, podemos usar ```rm hello```
  4. Para listar os arquivos presentes no diretório, podemos usar ```ls```

## Funções, argumentos, valores de retorno, variáveis
```C
printf("hello, world");
```
- printf é uma função que realiza impressão formatada de um texto na tela, e o texto entre aspas duplas é chamado de _string_
- Os parênteses permitem a passagem de argumentos para a função
- Um tipo de saída para um função é um efeito colateral ou mudança que podemos observar
    ![Função](https://cs50.harvard.edu/college/2021/fall/notes/1/side_effects.png)
- Uma função também pode possuir um valor de retorno que pode ser armazenado em uma variável, lembrando sempre que, em C, ```=``` é um operador de atribuição, e não de comparação
    ![Função](https://cs50.harvard.edu/college/2021/fall/notes/1/return_value.png)

## Main, arquivos de cabeçalho, comandos
```C
int main() {

}
```
- Em C, __```main```__ é o programa principal, e as chaves circundam o código que será executado junto com o programa
- __Arquivos de cabeçalho__, como ```<stdio.h>```, informar ao compilador as bibliotecas que devem ser carregadas no programa
- __Comandos__ são códigos que podemos utilizar para executar alguma ação:
  - ```cd``` para alterar para o diretório atual
  - ```cp``` para copiar arquivos e diretórios
  - ```ls``` para listar arquivos em um diretório
  - ```mkdir``` para criar um diretório
  - ```mv``` para mover/renomear arquivos e diretórios
  - ```rm``` para remover arquivos
  - ```rmdir``` para remover diretórios
  - ...

## Tipos, códigos de formato, operadores
- Os __tipos__ de dados indicam ao nosso programa que tipo de dados eles representam
  - ```bool``` para expressões booleanas
  - ```char``` para um único caractere
  - ```double``` para um valor de ponto flutuante com mais dígitos que um ```float```
  - ```float``` para um valor de número real com um valor decimal
  - ```int``` para inteiros até um certo tamanho
  - ```long``` para interios com mais _bits_ que um ```int```
  - ```string``` para uma série de caracteres
  - ...
- Dentro da função ```printf``` existem marcadores de posição para cada tipo, chamados __códigos de formato__:
  - ```%c``` para char
  - ```%f``` para float e double
  - ```%i``` ou ```%d``` para int
  - ```%li``` para long
  - ```%s``` para strings
- Também existem vários __operadores__:
  - ```+``` para adição
  - ```-``` para subtração
  - ```*``` para multiplicação
  - ```/``` para divisão
  - ```%``` para módulo (resto de divisão)

## Variáveis, simplificações sintáticas
```C
int counter = 0;
```
- Acima, foi criada uma __variável__ inteira chamada _counter_, cujo valor inicial é ```0```
- Para aumentar o valor, podemos utilizar ```counter = counter + 1```, que tornará ```counter = 1```
- C também permite __simplificações sintáticas__, como ```counter += 1``` ou ```counter++```, que fazem o mesmo que ```counter = counter + 1```
- O mesmo pode ser feito também com adição, multiplicação e, com mais cautela, divisão

## Cálculos
```C
int x = 1, y = 2;
int z = x + y;
```
- Acima, são criadas as variáveis inteiras _x_, _y_ e _z_. São atribuídos valores para _x_ e _y_, e _z_ armazena ```x+y```

## Condicionais, expressões booleanas
```C
if(x < y) {
    printf("x is less than y\n");
} else if (x > y) {
    printf("x is not less than y\n");
} else {
    printf("x is equal to y\n");
}
```
- embora possua parâmetros, ```if``` não é uma função. Ele realiza analisa a expressão entre parenteses.
  - Caso seja verdade, ele executa o bloco e pula os próximos ```if``` e ```else```, que dependem da falsidade do atual para serem testados
  - O operador de igualdade, que pode ser utilizado para comparações, é ```==```

## Loops, funções
```C
#include <stdio.h>

int main() {
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}
```
- este código pode ser otimizado
```C
while(True) {
    printf("meow\n");
}
```
- o código acima executaria pra sempre
```C
int counter = 0;
while(counter < 3) {
    printf("meow\n");
    counter++;
}
```
- o código acima executaria enquanto ```counter < 3```
```C
for(int i = 0; i < 3; i++) {
    printf("meow\n");
}
```
- o código acima também executaria 3 vezes, porém seu funcionamento é um pouco diferente
  - é criada uma variável (geralmente uma variável de controle). Como neste caso ela foi criada dentro do _loop for_, ela está acessível apenas durante o _loop_
  - é informada uma condição para verificar cada ciclo do _loop_
  - A última parte mostra a alteração que geralmente é feita na variável de controle
```C
#include <stdio.h>
void meow() {
    printf("meow\n");
}


int main() {
    for (int i = 0; i < 3; i++) {
        meow();
    }
}
```
- ```void meow()``` é uma função. O funcionamento de toda função é muito parecido com ```printf```. Neste caso, antes do nome, é informado o tipo do retorno da função, sendo que ```void``` significa que não há retorno para a função
  - Geralmente, funções do tipo ```void``` são chamadas de procedimento
  - As linhas de código entre as chaves a seguir representam o código a ser executado quando a função for chamada
  - Ainda podemos mover a função para o fim do código, declarando-a com um protótipo no início do código
  - Sempre que uma função for chamada, é necessário que ela tenha sido criada anteriormente
```C
#include <stdio.h>

void meow(); /* PROTÓTIPO */

int main() {
    for (int i = 0; i < 3; i++) {
        meow();
    }
}

/* FUNCÃO */
void meow() {
    printf("meow\n");
}
```
- Ainda podemos adicionar um parâmetro a função
  - ```n``` dirá quantas vezes desejamos imprimir a mensagem na tela
```C
#include <stdio.h>

void meow(int n); /* PROTÓTIPO */

int main() {
    meow(3);
}

/* FUNCÃO */
void meow(int ) {
    for(int i = 0; i < n; i++) {
        printf("meow\n");
    }
}
```
- Na chamada da função, o valor informado entre parênteses é atribuído à ```n```