#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int main() {
    int rand_number;
    int iterator_i;
    int iterator_j;
    int iterator_delay;
    rand_number = generate_number(7);

    for( iterator_i = 0; iterator_i < rand_number; iterator_i++ ) {
        for( iterator_j = 0; iterator_j < rand_number; iterator_j++ ) {
            int aux = generate_number(50);
            printf("%d ", aux);
            for (iterator_delay = 1; iterator_delay <= 10000; iterator_delay++)
                {}
        }
        printf("\n");
    }

    //printf("%d\n",rand_number);
    return 0;
}
