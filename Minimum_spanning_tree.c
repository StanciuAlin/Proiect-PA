#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Prim.h"
#include "generator.h"
#include "menu.h"
#include "Kruskal.h"

/**
* This method is main
* @author Stanciu Alin Marian
* @param argc
* @param *argv[]
* @return - returns 0
* @date 6/1/2018
*/

int main(int argc, char const *argv[]) {

    int **readed_graph;
    int total_cost;
    int number_nodes;
    int alg_choose;
    int read_mode_chose;
    int check_file;

    statement(); ///show statement of project
    draw_menu_choose_algorithm(); ///draw the menu to choose the algorithm: Kruskal or Prim
    scanf("%d", &alg_choose); ///read algorithm decision
    assert(alg_choose >= 1 && alg_choose <=2); ///check to insert only 1 or 2
    switch (alg_choose) {
        case 1 : { ///Kruskal algorithm is selected
            draw_menu_choose_read_mode(); ///draw menu for choose read mode
            scanf("%d", &read_mode_chose); ///read what date will use
            assert(read_mode_chose >= 1 && read_mode_chose <=2); ///check to insert only 1 or 2
            switch (read_mode_chose) {
                case 1 : { ///random mode is selected
                    srand((unsigned)time(NULL));
                    number_nodes = generate_number(MAX); ///generate number of nodes
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) ); ///allocate memory for matrix distance
                    matrix_constructor(readed_graph, number_nodes);
                    set_distances(readed_graph, number_nodes); ///set values for matrix distances
                    start_K(readed_graph, number_nodes, 2); ///start to solve
                    printf("Open output file and read the answer of the problem with random values!\n"); ///print a message
                    break;
                }
                case 2 : { ///read from file mode is selected
                    number_nodes = 0;
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) );
                    matrix_constructor(readed_graph, number_nodes); ///allocate memory for matrix distances
                    start_K(readed_graph, number_nodes, 1); ///start to solve
                    printf("Open output file and read the answer of the problem with values from input file!\n"); ///print a message
                    break;
                }
            }

            break;
        }
        case 2 : { ///Prim's algorithm is selected
            draw_menu_choose_read_mode(); ///draw menu for choose read mode
            scanf("%d", &read_mode_chose); ///read what date will use
            assert(read_mode_chose >= 1 && read_mode_chose <=2); ///check to insert only 1 or 2
            switch (read_mode_chose) {
                case 1 : { ///random mode is selected
                    srand((unsigned)time(NULL));
                    number_nodes = generate_number(MAX); ///generate number of nodes
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) ); ///allocate memory for matrix distances
                    matrix_constructor(readed_graph, number_nodes);
                    set_distances(readed_graph, number_nodes); ///set values for matrix distances
                    total_cost = start(readed_graph, number_nodes); ///compute the minimum spanning tree cost
                    Write_minimum_spanning_tree_Prim(total_cost, number_nodes); ///write the minimum spanning tree
                    printf("Open output file and read the answer of the problem with random values!\n"); ///print a message
                    break;
                }
                case 2 : { ///read from file mode is selected
                    check_file = init_read_file(); ///check if input file exist
                    if (check_file == -1) {
                        printf("File do not work!!!\n"); ///print an error message
                    }
                    number_nodes = read_number_nodes(); ///read number of nodes
                    readed_graph = (int **)calloc( number_nodes, sizeof(int *) ); ///allocate memory for matrix distances
                    matrix_constructor(readed_graph, number_nodes);
                    Read_data_matrix(readed_graph, number_nodes); ///read matrix distances
                    total_cost = start(readed_graph, number_nodes); ///compute the minimum spanning tree cost
                    Write_minimum_spanning_tree_Prim(total_cost, number_nodes); ///write the minimum spanning tree
                    printf("Open output file and read the answer of the problem with values from input file!\n"); ///print a message
                    break;
                }
            }
            break;
        }
    }

    return 0;
}
