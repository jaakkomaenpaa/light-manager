#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void setError(const char* msg) {
    perror(msg);
    exit(1);
}
