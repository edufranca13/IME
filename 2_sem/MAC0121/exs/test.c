#include <stdio.h>
#include <stdlib.h>

int main() {

        printf("Hello");
        char s[] = "Hello";

        int i;
        for (i = 0; i != '\0'; i++){
                printf("%s\n", s[i]);
        }

        return 0;
}

