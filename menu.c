#include <stdio.h>
#include <windows.h>

void statement() {
    //print statement of problem
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\tImplement two different algorithms to determine the minimum spanning trees Prim & Kruskal algorithm.\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //print first info about project
    printf(" Lecturer: Costin Badica\n");
    printf(" Teaching assistant: Alex Becheru & Ionut Muraret\t\t\t\t\t\t\tStudent: Stanciu Alin Marian\n\n");
}

void delay(int max_value) {
    //delay effect for better visual effect
    int iterator_i;
    for (iterator_i = 0; iterator_i < max_value; iterator_i++) {
        Sleep(1000);
    }
}
void draw_menu_choose_read_mode() {
    //menu for choose read mode of data
    printf(" Do you want a random data input or input file?Please chhose an option!\n");
    printf("  1.Random data input.\n");
    printf("  2.Input file.\n");
}
void draw_menu_choose_algorithm() {
    //menu for choose the algorithm to solve the problem
    printf(" Please choose an algorithm to solve the statement!\n");
    printf("  1.Kruskal algorithm.\n");
    printf("  2.Prim algorithm.\n");
}
