Spanner::Spanner() {
}

Spanner::Spanner(int** matrix, int dimension) {
    adjMatrix = matrix;
    dim = dimension;
}

Spanner::~Spanner() {
}

Spanner::kruskals() {
    int* arr = new int[dim];
    for (int i = 1; i <= dim; i++) {
        arr[i] = i;
    }

    candidateSet = new DisjointSet<int>(arr);
    delete[] arr;

    
}
