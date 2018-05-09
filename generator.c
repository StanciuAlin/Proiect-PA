#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int generate_number( int max_value ) {
    return rand()%(max_value + 1);
}

void matrix_constructor( int **readed_graph, int number_nodes ) {

    int iterator_i;
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        readed_graph[iterator_i] = (int *)calloc(number_nodes + 1, sizeof(int *));
    }

}

void set_distances(int **readed_graph, int number_nodes) {

    int iterator_i;
    int iterator_j;
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = iterator_i + 1; iterator_j < number_nodes; iterator_j++) {
            if (iterator_i != iterator_j) {
                readed_graph[iterator_i][iterator_j] = readed_graph[iterator_j][iterator_i] = generate_number(MAX_VALUE_GEN);
            }
        }
    }

}
void get_distances(int **readed_graph, int number_nodes) {

    int iterator_i;
    int iterator_j;
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = 0; iterator_j < number_nodes; iterator_j++) {
            printf("%d ", readed_graph[iterator_i][iterator_j]);
        }
        printf("\n");
    }

}
