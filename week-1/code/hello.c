#include<stdio.h>
#include<string.h>

int main() {
    char name[10];
    printf("What's your name? ");
    fgets(name, 10, stdin);

    printf("hello, %s", name);

    return 0;
}