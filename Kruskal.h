/**
* @file Kruskal.h
* @brief this header file will contain all required
* definitions and basic utilities functions.
*
* @author Stanciu Alin Marian
*
* @date 6/1/2018
*/
#ifndef KRUSKAL_H
#define KRUSKAL_H

#define N_MAX_VERTICES 50
#define N_MAX_EDGES N_MAX_VERTICES * ( N_MAX_VERTICES - 1 ) / 2

struct Edge
{
    int source;
    int dest;
    int weight;
};

FILE *read_spanning_tree; ///input file
FILE *write_spanning_tree; ///output file

struct Edge Graph[N_MAX_EDGES];
int Partial_tree[N_MAX_VERTICES];
int Connected_components[N_MAX_VERTICES];
int no_vertices_tree;
int no_edges_tree;

void Read_data( int **matrix_distance, int number_nodes, int read_mode );
void Write_minimum_spanning_tree(int **matrix_distance, int number_nodes);
void Sort_edges(int left, int right);
void start_K( int **matrix_distance, int number_nodes, int read_mode );

#endif
