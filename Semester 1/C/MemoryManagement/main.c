#include <stdio.h>
#include "mm.h"

int main(){
    int *newValue = mm_malloc(sizeof(int));
    printf("Adresse des Wertes: %p\n", newValue);

    int *newValue2 = mm_malloc(sizeof(int));
    printf("Adresse des Wertes: %p\n", newValue2);

    mm_free(newValue2);

    int *newValue3 = mm_malloc(sizeof(int));
    printf("Adresse des Wertes: %p\n", newValue3);
}