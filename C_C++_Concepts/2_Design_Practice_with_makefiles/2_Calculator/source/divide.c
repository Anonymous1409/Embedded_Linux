#include "divide.h"

void _divide(int* a, int* b, int* c) {
    if (*b != 0) {
        *c = *a / *b;
    } else {
        *c = 0;
    }
    return;
}
