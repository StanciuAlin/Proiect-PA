#include <stdio.h>
#include <stdlib.h>
#include "Kruskal.h"
#include "generator.h"

/**
* This method will be used to read or construct matrix distance. The selection is made by read mode variable that has two values - 1 for read from file or 2 for construct randomly the matrix distances
* @author Stanciu Alin Marian
* @param **matrix_distance - retain the distances from every node to adjacent nodes
* @param number_nodes - number of nodes in graph
* @param read_mode - has two possible values 1 - read distances from file or 2 - generate distances
* @return - void type and has no returned values
* @date 6/1/2018
*/
void Read_data( int **matrix_distance, int number_nodes, int read_mode ) {

    int iterator_i, iterator_j;
    int cost;
    int **aux_read_matrix; ///auxiliar matrix for read data from input file

    read_spanning_tree = fopen ("spanning_tree_Kruskal.in","r"); ///open input file for Kruskal algorithm

    if (read_spanning_tree == NULL){ ///check if file exist
        printf("\n File does not exist.");
        fclose(read_spanning_tree);
        return;
    }
    /// read data as a matrix

    if (read_mode == 1) { ///read from file

        fscanf(read_spanning_tree,"%d", &no_vertices_tree); ///read number nodes of graph / number of row and columns in readed matrix
        aux_read_matrix = (int **)calloc( no_vertices_tree, sizeof(int *) );
        matrix_constructor(aux_read_matrix, no_vertices_tree);

        for(iterator_i = 0; iterator_i < no_vertices_tree; iterator_i++) {
            for(iterator_j = 0; iterator_j < no_vertices_tree; iterator_j++) {
                fscanf(read_spanning_tree, "%d", &cost); ///read every cost
                aux_read_matrix[iterator_i][iterator_j] = cost; ///add cost to aux_read_matrix at (iterator_i, iterator_j) position
            }
        }
        ///move data from aux_read_matrix in Graph struct (source, dest, weight)
        for(iterator_i = 0; iterator_i < no_vertices_tree; iterator_i++) {
            for(iterator_j = iterator_i; iterator_j < no_vertices_tree; iterator_j++) {
                if (aux_read_matrix[iterator_i][iterator_j] > 0) { //check if exist edge
                    Graph[no_edges_tree].source = iterator_i + 1;
                    Graph[no_edges_tree].dest = iterator_j + 1;
                    Graph[no_edges_tree].weight = aux_read_matrix[iterator_i][iterator_j];
                    no_edges_tree++; ///increase number edges of graph
                }
            }
        }
    } else if( read_mode == 2 ) { ///use generated matrix_distance
        no_vertices_tree = number_nodes;
        for(iterator_i = 0; iterator_i < no_vertices_tree; iterator_i++) {
            for(iterator_j = iterator_i; iterator_j < no_vertices_tree; iterator_j++) {
                if (matrix_distance[iterator_i][iterator_j] > 0) { ///create graph direct from matrix_distance matrix with random value
                    Graph[no_edges_tree].source = iterator_i + 1;
                    Graph[no_edges_tree].dest = iterator_j + 1;
                    Graph[no_edges_tree].weight = matrix_distance[iterator_i][iterator_j];
                    no_edges_tree++; ///increase number edges of graph
                }
            }
        }
    }
    //get_distances(matrix_distance, number_nodes);
    for (iterator_i = 0; iterator_i < no_vertices_tree; iterator_i++) {
        Connected_components[iterator_i] = iterator_i;
    }

    fclose (read_spanning_tree); ///close input file

}

/**
* This method will be used to write in output file the minimum spanning tree solved with Kruskal algorithm
* @author Stanciu Alin Marian
* @param **matrix_distance - retain the distances from every node to adjacent nodes
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void Write_minimum_spanning_tree(int **matrix_distance, int number_nodes) {
    ///print problem solution
    int iterator_i;
    int costMST = 0; ///total cost of minimum spanning tree

    write_spanning_tree = fopen ("spanning_tree.out","w");

    if (write_spanning_tree!=NULL)
    {
        fprintf(write_spanning_tree,"======= Minimum spanning tree - Kruskal algorithm =======\n");
        for (iterator_i = 1; iterator_i < no_vertices_tree; iterator_i++) {
            fprintf(write_spanning_tree, "\t\t[%d %d] -> cost=%d\n", Graph[Partial_tree[iterator_i]].source, Graph[Partial_tree[iterator_i]].dest, Graph[Partial_tree[iterator_i]].weight);
            costMST += Graph[Partial_tree[iterator_i]].weight;
        }
        fprintf(write_spanning_tree, "\tTotal cost of spanning tree = %d", costMST);
        fclose(write_spanning_tree); ///close output file
    }

}

/**
* This method will be used to sort the edges with Merge Sort algorithm
* @author Stanciu Alin Marian
* @param left - left limit of array to be sorted
* @param right - right limit of array to be sorted
* @return - void type and has no returned values
* @date 6/1/2018
*/
void Sort_edges( int left, int right) {
    ///sort graph edges with merge sort algorithm
    int iterator_i;
    int iterator_j;
    struct Edge current_edge;

    if (left < right) {
        current_edge = Graph[left];
        iterator_i = left;
        iterator_j = right;
        while (iterator_i < iterator_j) {
            while (iterator_i < iterator_j && Graph[iterator_j].weight >= current_edge.weight) {
                iterator_j--;
            }
            Graph[iterator_i] = Graph[iterator_j];
            while (iterator_i < iterator_j && Graph[iterator_i].weight <= current_edge.weight) {
                iterator_i++;
            }
            Graph[iterator_j] = Graph[iterator_i];
        }
        Graph[iterator_i] = current_edge;
        Sort_edges(left, iterator_i - 1);
        Sort_edges(iterator_i + 1, right);
    }

}

/**
* This method will be the starting point of the solution
* @author Stanciu Alin Marian
* @param **matrix_distance - retain the distances from every node to adjacent nodes
* @param number_nodes - number of nodes in graph
* @param read_mode - has two possible values 1 - read distances from file or 2 - generate distances
* @return - void type and has no returned values
* @date 6/1/2018
*/
void start_K( int **matrix_distance, int number_nodes, int read_mode ) {
    ///start point of the Kruskal algorithm
    int iterator_i;
    int iterator_j;
    int min;
    int max;
    int No_max_sel;

    if (read_mode == 1) { ///check if data are readed from input file or are generated randomly
        Read_data(matrix_distance, number_nodes, 1);
    } else if(read_mode == 2) {
        Read_data(matrix_distance, number_nodes, 2);
    }

    Sort_edges(0, no_edges_tree - 1);

    No_max_sel = 0; /// number of selected edges
    for(iterator_i = 0; No_max_sel < no_vertices_tree - 1; iterator_i++) { ///if is not selected no_vertices_tree node from graph, check connection
        if (Connected_components[Graph[iterator_i].source] != Connected_components[Graph[iterator_i].dest]) {
            Partial_tree[++No_max_sel] = iterator_i; ///add the edge to partial tree
            if (Connected_components[Graph[iterator_i].source] < Connected_components[Graph[iterator_i].dest]) { ///check the sense of edge
                ///an edge is (min_point_edge --- max_point_edge)
                min = Connected_components[Graph[iterator_i].source];
                max = Connected_components[Graph[iterator_i].dest];
            } else {
                min = Connected_components[Graph[iterator_i].dest];
                max = Connected_components[Graph[iterator_i].source];
            }
            for(iterator_j = 0; iterator_j < no_vertices_tree; iterator_j++) {
                if (Connected_components[iterator_j] == max) {
                    Connected_components[iterator_j] = min;
                }
            }
        }
    }
    Write_minimum_spanning_tree(matrix_distance, number_nodes);
}
