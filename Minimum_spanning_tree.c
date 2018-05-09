#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"
#include "generator.h"
#include "menu.h"

int main(int argc, char const *argv[]) {

    int total_cost;
    int number_nodes;
    int **readed_graph;

    //number_nodes = (int *)malloc( sizeof(int ) );

    statement();
    delay(2);
    draw_menu_choose_read_mode();
    int read_mode_chose;
    scanf("%d", &read_mode_chose);
    switch (read_mode_chose) {
        case 1 : {
            srand((unsigned) time(NULL));
            number_nodes = generate_number(MAX);
            readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
            matrix_constructor(readed_graph, number_nodes);
            set_distances(readed_graph, number_nodes);
            get_distances(readed_graph, number_nodes);
            break;
        }
        case 2 : {
            int check_file;
            //check_file = init_read_file();
            if (check_file == -1) {
                printf("File do not work!!!\n");
            }
            //number_nodes = read_number_nodes();
            readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
            matrix_constructor(readed_graph, number_nodes);
            //Read_data_matrix(readed_graph, number_nodes);
            break;
        }
    }
    delay(2);
    draw_menu_choose_algorithm();
    int alg_choose;
    scanf("%d", &alg_choose);
    switch (alg_choose) {
        case 1 : {
            break;
        }
        case 2 : {
            //total_cost = start(readed_graph, number_nodes);
            //Write_minimum_spanning_tree_Prim(total_cost, number_nodes);
            printf("Open output file and read the answer of the problem!\n");
            break;
        }
    }
    delay(2);


    //show distances matrix
    //printf("%d\n", total_cost);
    /*int iterator_i;
    int iterator_j;
    for( iterator_i = 0; iterator_i < number_nodes; iterator_i++ ) {
        for( iterator_j = 0; iterator_j < number_nodes; iterator_j++ ) {
            printf("%d ", *(*(readed_graph + iterator_i) + iterator_j));
        }
        printf("\n");
    }*/
    //Read_data_matrix();
    return 0;
}
