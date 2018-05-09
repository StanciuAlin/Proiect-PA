#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

int main(int argc, char const *argv[]) {

    int **readed_graph, number_nodes;
    int iterator_i;
    int iterator_j;
    //number_nodes = (int *)malloc( sizeof(int ) );
    srand( time(NULL) );
    number_nodes = generate_value(30);
    printf("%d\n", number_nodes);
    readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
    matrix_constructor(readed_graph, number_nodes);
    set_distances(readed_graph, number_nodes);
    get_distances(readed_graph, number_nodes);
    return 0;
}
