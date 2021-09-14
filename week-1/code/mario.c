#include<stdio.h>

int main() {
    int height;
    do {
        printf("What's the height? ");
        scanf("%i", &height);
    } while(height < 1 || height > 8);

    int i;
    for(i = 0; i < height; i++) {
        int j;
        for(j = 0; j < height - i; j++) {
            printf(" ");
        }
        for(j = j; j <= height; j++) {
            printf("#");
        }
        printf("  ");
        for(j = j; j > height - i; j--) {
            printf("#");
        }
        printf("\n");
    }
}