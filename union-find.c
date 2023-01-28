#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static const size_t N = 10;

static size_t parent[N];

void init_parent(void) {
    for (size_t i = 0; i < N; ++i) {
        parent[i] = SIZE_MAX;
    }
}

void find_parent(size_t index) {
    size_t root = index;
    while (parent[root] != SIZE_MAX) {
        root = parent[root];
    }
    return root;
}

int main(void) {
    return EXIT_SUCCESS;
}