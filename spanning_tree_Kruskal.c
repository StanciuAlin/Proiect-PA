#include <stdio.h>
#include "Kruskal.h"
#include "generator.h"

void Read_data() {

    int iterator_i, iterator_j;
    int cost;
    read_spanning_tree = fopen ("spanning_tree_Kruskal.in","r");

    if (read_spanning_tree == NULL){ //verific daca fisierul nu exista
        printf("\n File does not exist.");
        fclose(read_spanning_tree);
        return;
    }


    //*   to read data as a matrix
    //fscanf(read_spanning_tree,"%d", &no_vertices_tree);
    no_vertices_tree = generator_input_matrix();
    printf("%d\n", no_vertices_tree);
    /*for(iterator_i = 0; iterator_i < no_vertices_tree; iterator_i++) {
        for(iterator_j = 0; iterator_j < no_vertices_tree; iterator_j++) {
            //fscanf(read_spanning_tree, "%d", &cost);
            if (cost > 0) {
                Graph[iterator_i].source = iterator_i + 1;
                Graph[iterator_i].dest = iterator_j + 1;
                Graph[iterator_i].weight = cost;
                no_edges_tree++;
            }
        }
    }

    fscanf(read_spanning_tree,"%d%d", &no_vertices_tree, &no_edges_tree);
    for (iterator_i = 0; iterator_i < no_edges_tree; iterator_i++) {
        fscanf(read_spanning_tree, "%d%d%d", &Graph[iterator_i].source, &Graph[iterator_i].dest, &Graph[iterator_i].weight);
    }*/
    for (iterator_i = 0; iterator_i < no_vertices_tree; iterator_i++) {
        Connected_components[iterator_i] = iterator_i;
    }
    fclose (read_spanning_tree);

}


void Write_minimum_spanning_tree() {

    int iterator_i;
    int costAPM = 0;
    write_spanning_tree = fopen ("spanning_tree.out","w");
    if (write_spanning_tree!=NULL)
    {
        fprintf(write_spanning_tree,"======= Minimum spanning tree - Kruskal algorithm =======\n");
        for (iterator_i = 1; iterator_i < no_vertices_tree; iterator_i++) {
            fprintf(write_spanning_tree, "\t\t[%d %d] -> cost=%d\n", Graph[Partial_tree[iterator_i]].source, Graph[Partial_tree[iterator_i]].dest, Graph[Partial_tree[iterator_i]].weight);
            costAPM += Graph[Partial_tree[iterator_i]].weight;
        }
        fprintf(write_spanning_tree, "\tTotal cost of spanning tree = %d", costAPM);
        fclose (write_spanning_tree);
    }

}


void Sort_edges( int left, int right) {

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


int main(int argc, char const *argv[]) {
    int iterator_i, iterator_j, min, max, No_max_sel;
    Read_data();
    Sort_edges(0, no_edges_tree - 1);
    No_max_sel = 0; // numarul de muchii selectate
    for(iterator_i = 0; No_max_sel < no_vertices_tree - 1; iterator_i++) {
        if (Connected_components[Graph[iterator_i].source] != Connected_components[Graph[iterator_i].dest]) {
            Partial_tree[++No_max_sel] = iterator_i;
            if (Connected_components[Graph[iterator_i].source] < Connected_components[Graph[iterator_i].dest]) {
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
    Write_minimum_spanning_tree();
    return 0;
}
