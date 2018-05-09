#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int generate_number(int max_value) {

  return rand() % (max_value + 1);

}
