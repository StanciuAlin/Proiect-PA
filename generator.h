#ifndef GENERATOR_H
#define GENERATOR_H
#ifndef MAX_VALUE_GEN
#define MAX_VALUE_GEN 9
#endif

int generate_number( int max_value );
void matrix_constructor( int **readed_graph, int number_nodes );
void set_distances(int **readed_graph, int number_nodes);
void get_distances(int **readed_graph, int number_nodes);

#endif /* end of include guard: GENERATOR_H */
