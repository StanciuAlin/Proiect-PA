#ifndef PRIM_H
#define PRIM_H
#define MAX 50
#define INF 10000

int number_nodes;
int readed_graph[MAX][MAX];
int spanning[MAX][MAX];

void Read_data_matrix();
void Write_minimum_spanning_tree_Prim( int total_cost_tree );
void create_cost_and_spanning_matrix( int cost_matrix[MAX][MAX]);

int find_adiacent_node_minim_edge( int visited_nodes[MAX], int distance[MAX], int *min_distance );
void update_distance_array( int visited_nodes[MAX], int cost[MAX][MAX], int distance[MAX], int from[MAX], int adiacent_node );
int prims();

#endif
