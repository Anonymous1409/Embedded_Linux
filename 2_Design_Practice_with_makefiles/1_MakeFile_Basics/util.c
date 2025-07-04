#include "util.h"
#include <stdio.h>

void disp(char *message) {
    if (message != NULL) {
        printf("%s\n", message);
    } else {
        printf("No message provided.\n");
    }
}