#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"
#include "Kruskal.h"

int start(int **readed_graph, int number_nodes) {

    int total_cost;

    total_cost=prims( readed_graph, number_nodes );

    return total_cost;
}

int read_number_nodes() {
    int number_nodes;
    fscanf(read_spanning_tree, "%d", &number_nodes);
    return number_nodes;
}

int init_read_file() {

    read_spanning_tree = fopen ("spanning_tree_Prim.in","r");

    if (read_spanning_tree == NULL){ //verific daca fisierul nu exista
        printf("\n File does not exist.");
        fclose(read_spanning_tree);
        return -1;
    }
    return 1;
}

void Read_data_matrix( int **readed_graph, int number_nodes ) {

    int iterator_i, iterator_j;

    for (iterator_i = 0; iterator_i < number_nodes; iterator_i++) {
        for (iterator_j = 0; iterator_j < number_nodes; iterator_j++) {
            fscanf(read_spanning_tree, "%d", &readed_graph[iterator_i][iterator_j]);
        }
    }
    fclose(write_spanning_tree);
}

void Write_minimum_spanning_tree_Prim( int total_cost_tree, int number_nodes ) {

    int iterator_i;
    int iterator_j;

    write_spanning_tree = fopen ("spanning_tree.out","w");

    /*fprintf(write_spanning_tree, "\nspanning tree matrix:\n");
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++)
    {
        fprintf(write_spanning_tree, "\n");
        for(iterator_j = 0; iterator_j < number_nodes; iterator_j++)
            fprintf(write_spanning_tree, "%d ", spanning[iterator_i][iterator_j]);
    }
    fprintf(write_spanning_tree, "\n\n");
    */
    fprintf(write_spanning_tree, "======= Minimum spanning tree - Prim algorithm =======\n");
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++)
    {
        for(iterator_j = iterator_i + 1; iterator_j < number_nodes; iterator_j++)
            if (spanning[iterator_i][iterator_j] != 0) {
                fprintf(write_spanning_tree, "\t\t[%d %d] -> cost=%d;\n", iterator_i + 1, iterator_j + 1, spanning[iterator_i][iterator_j] );
            }
    }

    fprintf(write_spanning_tree, "\tTotal cost of spanning tree = %d", total_cost_tree);
    fclose(write_spanning_tree);

}

void create_cost_and_spanning_matrix( int **readed_graph, int cost_matrix[MAX][MAX], int number_nodes) {
    //create cost[][] matrix,spanning[][]
    int iterator_i;
    int iterator_j;
    for(iterator_i = 0; iterator_i < number_nodes; iterator_i++)
        for(iterator_j = 0; iterator_j < number_nodes; iterator_j++)
        {
            if(readed_graph[iterator_i][iterator_j] == 0)
                cost_matrix[iterator_i][iterator_j] = INF;
            else
                cost_matrix[iterator_i][iterator_j] = readed_graph[iterator_i][iterator_j];
                spanning[iterator_i][iterator_j] = 0;
        }
}

int find_adiacent_node_minim_edge( int visited_nodes[MAX], int distance[MAX], int *min_distance, int number_nodes ) {

    int iterator_i;
    int iterator_node_minim;

    *min_distance = INF;
    for(iterator_i = 1; iterator_i < number_nodes; iterator_i++)
        if(visited_nodes[iterator_i] == 0 && distance[iterator_i] < *min_distance)
        {
            iterator_node_minim = iterator_i;
            *min_distance = distance[iterator_i];
        }
    return iterator_node_minim;
}

void update_distance_array( int visited_nodes[MAX], int cost_matrix[MAX][MAX], int distance[MAX], int from[MAX], int adiacent_node, int number_nodes ) {

    int iterator_i;

    for(iterator_i = 1; iterator_i < number_nodes; iterator_i++)
        if(visited_nodes[iterator_i] == 0 && cost_matrix[iterator_i][adiacent_node] < distance[iterator_i])
        {
            distance[iterator_i] = cost_matrix[iterator_i][adiacent_node];
            from[iterator_i] = adiacent_node;
        }

}

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
    //create cost[][] matrix,spanning[][]
    create_cost_and_spanning_matrix( readed_graph, cost, number_nodes );

    //initialise visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;

    for(iterator_i = 1; iterator_i < number_nodes; iterator_i++)
    {
        distance[iterator_i] = cost[0][iterator_i];
        from[iterator_i] = 0;
        visited[iterator_i] = 0;
    }

    min_cost = 0;        //cost of spanning tree
    no_of_edges = number_nodes - 1;        //no. of edges to be added

    while(no_of_edges > 0)
    {
        //find the vertex at minimum distance from the tree
        second_adiacent_node = find_adiacent_node_minim_edge(visited, distance, &min_distance, number_nodes);
        first_adiacent_node = from[second_adiacent_node];

        //insert the edge in spanning tree
        spanning[first_adiacent_node][second_adiacent_node] = distance[second_adiacent_node];
        spanning[second_adiacent_node][first_adiacent_node] = distance[second_adiacent_node];
        no_of_edges--;
        visited[second_adiacent_node] = 1;

        //updated the distance[] array
        update_distance_array(visited, cost, distance, from, second_adiacent_node, number_nodes);
        min_cost = min_cost + cost[first_adiacent_node][second_adiacent_node];
    }

    return min_cost;
}
