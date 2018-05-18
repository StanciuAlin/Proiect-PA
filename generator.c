#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int generate_number( int max_value ) {
    //generate a number in range [0,max_value]
    return rand()%(max_value + 1);
}

void matrix_constructor( int **readed_graph, int number_nodes ) {
    //matrix constructor function
    int iterator_i;
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        readed_graph[iterator_i] = (int *)calloc(number_nodes + 1, sizeof(int *)); //initial, all matrix is 0
    }

}

void set_distances(int **readed_graph, int number_nodes) {
    //function to set random distances in matrix
    int iterator_i;
    int iterator_j;
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = iterator_i + 1; iterator_j < number_nodes; iterator_j++) {
            if (iterator_i != iterator_j) { //test for main diagonal
                readed_graph[iterator_i][iterator_j] = readed_graph[iterator_j][iterator_i] = generate_number(MAX_VALUE_GEN); //assign random value (distance in graph)
            }
        }
    }
    /*
    //  this part make a rare graph
    get_distances(readed_graph, number_nodes);
    printf("\n");
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = iterator_i + 1; iterator_j < number_nodes; iterator_j++) {
            if (readed_graph[iterator_i][iterator_j]) { //test if exist edge
                readed_graph[iterator_i][iterator_j] = readed_graph[iterator_j][iterator_i] = generate_number(MAX_VALUE_GEN); //assign random value (distance in graph)
            }
        }
    }*/

}

void get_distances(int **readed_graph, int number_nodes) {
    //print matrix_distance generated randomly
    int iterator_i;
    int iterator_j;
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = 0; iterator_j < number_nodes; iterator_j++) {
            printf("%d ", readed_graph[iterator_i][iterator_j]);
        }
        printf("\n");
    }

}
