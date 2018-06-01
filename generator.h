/**
* @file generator.h
* @brief this header file will contain all required
* definitions and basic utilities functions for random generator
* @author Stanciu Alin Marian
* @date 6/1/2018
*/
#ifndef GENERATOR_H
#define GENERATOR_H
#ifndef MAX_VALUE_GEN
#define MAX_VALUE_GEN 1000
#endif

int generate_number( int max_value );
void matrix_constructor( int **readed_graph, int number_nodes );
void set_distances(int **readed_graph, int number_nodes);
void get_distances(int **readed_graph, int number_nodes);

#endif /* end of include guard: GENERATOR_H */
