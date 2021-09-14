#include<stdio.h>

int height(char message[20]);
void pyramid(int height);

int main() {
    int h = height("What's the height?");

    pyramid(h);
}

int height(char message[20]) {
    int h;
    printf("%s ", message);
    scanf("%i", &h);
    if (h < 1 || h > 8) {
        return height(message);
    } return h;
}

void pyramid(int height) {
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