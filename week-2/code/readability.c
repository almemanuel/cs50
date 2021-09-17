#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main() {
    char text[250];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int chars = 0, words = 0;
    float s = 0;
    int i;
    for(i = 0; text[i] != '\0'; i++) {
        if(isalnum(text[i]) != 0) {
            chars++;
        } else {
            if(text[i] == ' ') {
                words++;
            }
            if(isalnum(text[i + 1]) == 0) {
                s++;
            }
        }
    }

    float l;
    if(words < 100) {
        l = chars / (float) words * 100;
        s = s / words * 100;
    } else {
        l = chars / (float) words / 100;
        s = s / words / 100;
    }

    words--;
    if(words < 100) {
        l = chars / (float) words * 100;
    } else {
        l = chars / (float) words / 100;
    }

    float index = 0.0588 * l - 0.296 * s - 15.8;
    printf("Grade: %i\n", (int)index);

    return 0;
}