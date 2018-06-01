#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

/**
* This method will be used to generate a number in range [0,max value]
* @author Stanciu Alin Marian
* @param max_value - maximum value which can be generated randomly
* @return - generated number
* @date 6/1/2018
*/
int generate_number( int max_value ) {
    ///generate a number in range [0,max_value]
    return rand()%(max_value + 1);
}

/**
* This method will be used to allocate memory for a matrix that will retain all distances in graph
* @author Stanciu Alin Marian
* @param readed_graph - upcoming matrix with distances from each node to its adjacent ones.
* @param number_nodes - upcoming number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void matrix_constructor( int **readed_graph, int number_nodes ) {
    ///matrix constructor function
    int iterator_i;
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        readed_graph[iterator_i] = (int *)calloc(number_nodes + 1, sizeof(int *)); ///initial, all matrix is 0
    }

}

/**
* This method will be used to set random distances in matrix
* @author Stanciu Alin Marian
* @param readed_graph - matrix with distances from each node to its adjacent ones.
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void set_distances(int **readed_graph, int number_nodes) {
    ///function to set random distances in matrix
    int iterator_i;
    int iterator_j;
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = iterator_i + 1; iterator_j < number_nodes; iterator_j++) {
            if (iterator_i != iterator_j) { ///test for main diagonal
                readed_graph[iterator_i][iterator_j] = readed_graph[iterator_j][iterator_i] = generate_number(MAX_VALUE_GEN); ///assign random value (distance in graph)
            }
        }
    }

}

/**
* This method will be used to print matrix of distances generated randomly
* @author Stanciu Alin Marian
* @param readed_graph - matrix with distances from each node to its adjacent ones.
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void get_distances(int **readed_graph, int number_nodes) {
    ///print matrix_distance generated randomly
    int iterator_i;
    int iterator_j;
    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = 0; iterator_j < number_nodes; iterator_j++) {
            printf("%d ", readed_graph[iterator_i][iterator_j]);
        }
        printf("\n");
    }

}
