#include <stdio.h>
#include <windows.h>

void statement() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\tImplement two different algorithms to determine the minimum spanning trees Prim & Kruskal algorithm.\n\n\n\n\n\n\n\n\n");
    printf(" Lecturer : Costin Badica");
    printf("Teaching assistant : Alex Becheru & Ionut ̧ Muraret\t\t\t\tStudent : Stanciu Alin Marian\n\n\n\n");
}

void delay(int max_value) {
    int iterator_i;
    for (iterator_i = 0; iterator_i < max_value; iterator_i++) {
        Sleep(100);
    }
}
void draw_menu_choose_read_mode() {
    printf("Do you want a random data input or input file?Please chhose an option!\n");
    printf(" 1.Random data input.\n");
    printf(" 2.Input file.\n");
}
void draw_menu_choose_algorithm() {
    printf("Please choose an algorithm to solve the statement!\n");
    printf(" 1.Kruskal algorithm.\n");
    printf(" 2.Prim algorithm.\n");
}
