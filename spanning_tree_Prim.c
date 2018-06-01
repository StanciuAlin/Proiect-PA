#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"
#include "Kruskal.h"

/**
* This method will be the starting point of the solution ( Prim algorithm )
* calculate total cost of minimum spanning  tree.
* @author Stanciu Alin Marian
* @param readed_graph - matrix with distances from each node to its adjacent ones
* @param number_nodes - number of nodes in graph
* @return - returns the total cost of the minimum spanning tree
* @date 6/1/2018
*/
int start(int **readed_graph, int number_nodes) {

    int total_cost; ///retain the total cost of minimum spanning tree

    total_cost=prims( readed_graph, number_nodes );

    return total_cost; ///returns cost
}

/**
* This method will be used to read a number from an input file
* @author Stanciu Alin Marian
* @return - returns number of nodes in graph
* @date 6/1/2018
*/
int read_number_nodes() {
    ///read a number from an input file and return it
    int number_nodes;
    fscanf(read_spanning_tree, "%d", &number_nodes);
    return number_nodes;
}

/**
* This method will be used to check if the file exist
* @author Stanciu Alin Marian
* @return - returns -1 if file does not exist and otherwise returns 1
* @date 6/1/2018
*/
int init_read_file() {

    read_spanning_tree = fopen ("spanning_tree_Prim.in","r"); ///open input file

    if (read_spanning_tree == NULL){ ///check if the file exist
        printf("\n File does not exist.");
        fclose(read_spanning_tree);
        return -1; ///check value return is -1 because the file does not exist
    }
    return 1; ///file exist
}

/**
* This method will be used to read matrix distances from input file
* @author Stanciu Alin Marian
* @param readed_graph - matrix with distances from each node to its adjacent ones
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void Read_data_matrix( int **readed_graph, int number_nodes ) {
    ///read matrix distance from input file
    int iterator_i, iterator_j;

    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = 0; iterator_j < number_nodes; iterator_j++) {
            fscanf(read_spanning_tree, "%d", &readed_graph[iterator_i][iterator_j]);
        }
    }
    fclose(read_spanning_tree); ///close read file
}

/**
* This method will be used to write in output file the minimum spanning tree solved with Prim algorithm
* @author Stanciu Alin Marian
* @param total_cost_tree - retain the distances from every node to adjacent nodes
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void Write_minimum_spanning_tree_Prim( int total_cost_tree, int number_nodes ) {
    ///print the solutio of problem
    int iterator_i;
    int iterator_j;

    write_spanning_tree = fopen ("spanning_tree.out","w"); ///open output file
    fprintf(write_spanning_tree, "======= Minimum spanning tree - Prim algorithm =======\n");
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++)
    {
        for(iterator_j = iterator_i + 1; iterator_j < number_nodes; iterator_j++)
            if (spanning[iterator_i][iterator_j] != 0) {
                fprintf(write_spanning_tree, "\t\t[%d %d] -> cost=%d;\n", iterator_i + 1, iterator_j + 1, spanning[iterator_i][iterator_j] );
            }
    }

    fprintf(write_spanning_tree, "\tTotal cost of spanning tree = %d", total_cost_tree); ///print total cost
    fclose(write_spanning_tree); ///close output file

}

/**
* This method will be used to create cost matrix and spanning matrix which is needed later
* @author Stanciu Alin Marian
* @param readed_graph - matrix with distances from each node to its adjacent ones
* @param cost_matrix - the cost for every edge in graph(an edge with 0 distance has INF cost by convention)
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void create_cost_and_spanning_matrix( int **readed_graph, int cost_matrix[MAX][MAX], int number_nodes) {
    ///create cost[][] matrix,spanning[][]
    int iterator_i;
    int iterator_j;
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++)
        for(iterator_j = 0; iterator_j < number_nodes; iterator_j++)
        {
            if(readed_graph[iterator_i][iterator_j] == 0) ///if no exist edge from iterator_i node to iterator_j node, the distance is set INF
                cost_matrix[iterator_i][iterator_j] = INF;
            else
                cost_matrix[iterator_i][iterator_j] = readed_graph[iterator_i][iterator_j]; ///retain edge cost from iterator_i node to iterator_j node
                spanning[iterator_i][iterator_j] = 0; ///do not know if is a right edge in minimum spanning tree
        }
}

/**
* This method will be used to search for minimum distance from current edge to adjacent node
* @author Stanciu Alin Marian
* @param visited_nodes - retain for every node if was visited, 0 - not visited and 1 - was visited
* @param distance - an array with distances: on i-th position add cost from i node to adjacent node
* @param number_nodes - the edge with minimum cost from current node to it adjacent one
* @param number_nodes - number of nodes in graph
* @return - minimum distance
* @date 6/1/2018
*/
int find_adiacent_node_minim_edge( int visited_nodes[MAX], int distance[MAX], int *min_distance, int number_nodes ) {
    ///search for minimum distance from current edge to adjacent node
    int iterator_i;
    int iterator_node_minim_distance;

    *min_distance = INF;
    for(iterator_i = 1; iterator_i < number_nodes; iterator_i++)
        if(visited_nodes[iterator_i] == 0 && distance[iterator_i] < *min_distance)
        { ///if iterator_i node is not visited and distance to iterator_i is less than current minimum distance, is found a node with minimum distance
            iterator_node_minim_distance = iterator_i;
            *min_distance = distance[iterator_i]; ///update minimum distance
        }
    return iterator_node_minim_distance; ///return minimum distance
}

/**
* This method will be used to update distance and from arrays.
* @author Stanciu Alin Marian
* @param visited_nodes - retain for every node if was visited, 0 - not visited and 1 - was visited
* @param cost_matrix - matrix with the cost for every edge in graph
* @param distance - an array with distances: on i-th position add cost from i node to adjacent node
* @param from - an array with adjacent nodes: on i-th position add adjacent node with i node
* @param adiacent_node - adjacent node with current node
* @param number_nodes - number of nodes in graph
* @return - void type and has no returned values
* @date 6/1/2018
*/
void update_distance_array( int visited_nodes[MAX], int cost_matrix[MAX][MAX], int distance[MAX], int from[MAX], int adiacent_node, int number_nodes ) {
    ///update distance
    int iterator_i;

    for(iterator_i = 1; iterator_i < number_nodes; iterator_i++)
        if(visited_nodes[iterator_i] == 0 && cost_matrix[iterator_i][adiacent_node] < distance[iterator_i])
        {
            distance[iterator_i] = cost_matrix[iterator_i][adiacent_node];
            from[iterator_i] = adiacent_node;
        }

}

/**
* This method will be used to implement Prim’s algorithm
* @author Stanciu Alin Marian
* @param readed_graph - matrix with distances from each node to its adjacent ones
* @param number_nodes - number of nodes in graph
* @return - returns minimum cost after Prim’s algorithm action
* @date 6/1/2018
*/
int prims( int **readed_graph, int number_nodes ) {

    int cost[MAX][MAX];
    int min_distance;
    int first_adiacent_node, second_adiacent_node;
    int iterator_i;
    int no_of_edges;
    int min_cost;
    int *visited = (int *)calloc(number_nodes, sizeof(int));
    int *distance = (int *)calloc(number_nodes, sizeof(int));
    int *from = (int *)calloc(number_nodes, sizeof(int));

    ///create cost[][] matrix,spanning[][]
    create_cost_and_spanning_matrix( readed_graph, cost, number_nodes );

    ///initialise visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;

    for(iterator_i = 1; iterator_i < number_nodes; iterator_i++)
    {
        distance[iterator_i] = cost[0][iterator_i];
        from[iterator_i] = 0;
        visited[iterator_i] = 0;
    }

    min_cost = 0; ///cost of spanning tree
    no_of_edges = number_nodes - 1; ///number of edges to be added

    while(no_of_edges > 0)
    {
        ///find the vertex at minimum distance from the tree
        second_adiacent_node = find_adiacent_node_minim_edge(visited, distance, &min_distance, number_nodes);
        first_adiacent_node = from[second_adiacent_node];

        ///insert the edge in spanning tree
        spanning[first_adiacent_node][second_adiacent_node] = distance[second_adiacent_node];
        spanning[second_adiacent_node][first_adiacent_node] = distance[second_adiacent_node];
        no_of_edges--;
        visited[second_adiacent_node] = 1;

        ///update the distance[] array
        update_distance_array(visited, cost, distance, from, second_adiacent_node, number_nodes);
        min_cost = min_cost + cost[first_adiacent_node][second_adiacent_node];
    }

    return min_cost;
}
