#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static const size_t N = 10;

static size_t parent[N];

void Init(void) {
    for (size_t i = 0; i < N; ++i) {
        parent[i] = i;
    }
}

size_t Find(size_t index) {
    size_t curr = index;
    while (parent[curr] != curr) {
        curr = parent[curr];
    }
    return curr;
}

void FindReplace(size_t start_index, size_t new_value) {
    size_t curr = start_index;
    while (curr != parent[curr]) {
        size_t p = curr;
        curr = parent[curr];
        parent[p] = new_value;
    }
    parent[curr] = new_value;
}

void FindCompress(size_t index) {
    size_t root = Find(index);
    FindReplace(index, root);
}

void Union(size_t index1, size_t index2) {
    FindCompress(index1);
    size_t root = parent[index1];
    FindReplace(index2, root);
}

int main(void) {
    Init();
    Union(0, 1);
    Union(2, 3);
    Union(1, 3);
    Union(4, 5);
    assert(parent[1] == 0);
    assert(parent[2] == 0);
    assert(parent[3] == 0);
    assert(parent[4] == 4);
    assert(parent[5] == 4);
    assert(parent[6] == 6);
    return EXIT_SUCCESS;
}