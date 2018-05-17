#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Prim.h"
#include "generator.h"
#include "menu.h"
#include "Kruskal.h"

int main(int argc, char const *argv[]) {

    int **readed_graph;
    int total_cost;
    int number_nodes;
    int alg_choose;
    int read_mode_chose;
    int check_file;

    //number_nodes = (int *)malloc( sizeof(int ) );
    statement();
    draw_menu_choose_algorithm();
    scanf("%d", &alg_choose);
    assert(alg_choose >= 1 && alg_choose <=2);
    switch (alg_choose) {
        case 1 : { //Kruskal algorithm
            draw_menu_choose_read_mode();
            scanf("%d", &read_mode_chose);
            assert(read_mode_chose >= 1 && read_mode_chose <=2);
            switch (read_mode_chose) {
                case 1 : {
                    srand((unsigned)time(NULL));
                    number_nodes = generate_number(MAX);
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
                    matrix_constructor(readed_graph, number_nodes);
                    set_distances(readed_graph, number_nodes);
                    //get_distances(readed_graph, number_nodes);
                    start_K(readed_graph, number_nodes, 2);
                    printf("Open output file and read the answer of the problem with random values!\n");
                    break;
                }
                case 2 : {
                    number_nodes = 0;
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
                    matrix_constructor(readed_graph, number_nodes);
                    start_K(readed_graph, number_nodes, 1);
                    printf("Open output file and read the answer of the problem with values from input file!\n");
                    break;
                }
            }

            break;
        }
        case 2 : {
            draw_menu_choose_read_mode();
            scanf("%d", &read_mode_chose);
            assert(read_mode_chose >= 1 && read_mode_chose <=2);
            switch (read_mode_chose) {
                case 1 : {
                    srand((unsigned)time(NULL));
                    number_nodes = generate_number(MAX);
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
                    matrix_constructor(readed_graph, number_nodes);
                    set_distances(readed_graph, number_nodes);
                    //get_distances(readed_graph, number_nodes);
                    total_cost = start(readed_graph, number_nodes);
                    Write_minimum_spanning_tree_Prim(total_cost, number_nodes);
                    printf("Open output file and read the answer of the problem with random values!\n");
                    break;
                }
                case 2 : {
                    check_file = init_read_file();
                    if (check_file == -1) {
                        printf("File do not work!!!\n");
                    }
                    number_nodes = read_number_nodes();
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
                    matrix_constructor(readed_graph, number_nodes);
                    Read_data_matrix(readed_graph, number_nodes);
                    total_cost = start(readed_graph, number_nodes);
                    Write_minimum_spanning_tree_Prim(total_cost, number_nodes);
                    printf("Open output file and read the answer of the problem with values from input file!\n");
                    break;
                }
            }
            break;
        }
    }

    return 0;
}
