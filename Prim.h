#ifndef PRIM_H
#define PRIM_H
#define MAX 50
#define INF 10000

int spanning[MAX][MAX];

void Read_data_matrix( int **readed_graph, int number_nodes );
void Write_minimum_spanning_tree_Prim( int total_cost_tree, int number_nodes );
void create_cost_and_spanning_matrix( int **readed_graph, int cost_matrix[MAX][MAX], int number_nodes);

int start(int **readed_graph, int number_nodes);
int find_adiacent_node_minim_edge( int visited_nodes[MAX], int distance[MAX], int *min_distance, int number_nodes );
void update_distance_array( int visited_nodes[MAX], int cost[MAX][MAX], int distance[MAX], int from[MAX], int adiacent_node, int number_nodes );
int prims( int **readed_graph, int number_nodes );
int read_number_nodes();

#endif
