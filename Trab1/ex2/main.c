#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
    void *handle;
    char *error;

    // Load the library.
    handle = dlopen(argv[1], RTLD_LAZY);
    error = dlerror();

    if (!handle || error != NULL) {
        printf("nao disponivel\n");
        return 0;
    }

    // Get the address of the imprime() function.
    int (*imprime)() = dlsym(handle, "imprime");
    if (imprime == NULL) {
        printf("nao implementado\n");
    } else {
        printf("%d\n", imprime());
    }
    
    // Get the address of the calcula() function.
    int (*calcula)() = dlsym(handle, "calcula");
    if (!calcula || error != NULL) {
        printf("nao implementado\n");
    } else {
        printf("%d\n", calcula(atoi(argv[2]), atoi(argv[3])));
    }
    
    // Get the address of the trigo() function.
    int (*trigo)() = dlsym(handle, "trigo");
    if (!trigo || error != NULL) {
        printf("nao implementado\n");
    } else {
        printf("%d\n", trigo(atof(argv[4])));
    }

    // Unload the library.
    dlclose(handle);

    return 0;
}