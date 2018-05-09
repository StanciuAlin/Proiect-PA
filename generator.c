#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int generate_number(int max_value) {

  time_t t;

  /* Intializes random number generator */
  srand((unsigned) time(NULL));

  /* Print 5 random numbers from 0 to 49 */
  return rand() % (max_value + 1);

}
