#include <stdio.h>

int main(int argc, char **argv) {
    if (argc <= 0) { /* error occurred */
        printf("Wrong number of arguments\n");
        return 1;
    }
    else {
        printf("%d\n", argc-1);
        int i;
        for (i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}