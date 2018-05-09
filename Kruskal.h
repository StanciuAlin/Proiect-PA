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

FILE *read_spanning_tree;
FILE *write_spanning_tree;

struct Edge Graph[N_MAX_EDGES];
int Partial_tree[N_MAX_VERTICES];
int Connected_components[N_MAX_VERTICES];
int no_vertices_tree;
int no_edges_tree;

void Read_data();
void Write_minimum_spanning_tree();
void Sort_edges(int left, int right);

#endif
