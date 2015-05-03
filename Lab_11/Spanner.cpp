Spanner::Spanner() {
}

Spanner::Spanner(int** matrix, int dimension) {
    adjMatrix = matrix;
    dim = dimension;
}

Spanner::~Spanner() {
    for (int i = 0; i < dim; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Spanner::kruskals() {
    int* arr = new int[dim];
    for (int i = 0; i < dim; i++) {
        arr[i] = i;
    }

    candidateSet = new DisjointSet<int>(arr, dim);
    delete[] arr;

    int numEdges = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = i; j < dim; j++) {
            if (adjMatrix[i][j] != 0) {
                numEdges++;
            }
        }
    }
    pq = new EdgeNode*[numEdges];
    int k = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = i; j < dim; j++) {
            if (adjMatrix[i][j] != 0) {
                pq[k] = new EdgeNode(adjMatrix[i][j], i, j);
                k++;
            }
        }
    }

    for (int i = 0; i < numEdges; i++) {
        if (pq[i] == NULL) {
            break;
        }
    }
    bubbleSort(pq, numEdges);
    
    EdgeNode** eT = new EdgeNode*[dim - 1];
    for (int i = 0; i < dim - 1; i++) {
        eT[i] = NULL;
    }
    EdgeNode* x;
    /*
     * Begin Kruskal
     */
    int cardinality = 0;
    int iter = 0;
    while (!(emptyQueue(pq, numEdges)) && cardinality != dim - 1) {
        x = pq[iter];
        pq[iter] = NULL;

        if (candidateSet -> find(x -> getV1()) != candidateSet -> find(x -> getV2())) {
            eT[cardinality] = x;
            candidateSet -> setUnion(x -> getV1(), x -> getV2());
            cardinality++;
        }
        iter++;
    }
    for (int i = 0; i < dim - 1; i++) {
        if (eT[i] == NULL) {
            return;
        }
    }
    for (int i = 0; i < dim - 1; i++) {
        std::cout << "(" << eT[i] -> getV1() << ", " << eT[i] -> getV2() << ") ";
    }
    std::cout << std::endl;
    
    // free memory
    delete[] eT;
    eT = NULL;
    delete[] pq;
    pq = NULL;
    delete candidateSet;
    candidateSet = NULL;
}

void Spanner::prims() {
    
}

void Spanner::bubbleSort(EdgeNode** pq, int size) {
    EdgeNode* swap;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (pq[j] -> getWeight() > pq[j + 1] -> getWeight()) {
                swap = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = swap;
            }
        }
    }
}

bool Spanner::emptyQueue(EdgeNode** pq, int size) {
    for (int i = 0; i < size; i++) {
        if (pq[i] != NULL) {
            return false;
        }
    }
    return true;
}
