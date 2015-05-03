/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Class implementation for Spanner
 */
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
    sort(pq, numEdges);
    
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
            std::cout << "No solution" << std::endl;
            return;
        }
    }
    for (int i = 0; i < dim - 1; i++) {
        std::cout << "(" << eT[i] -> getV1() << ", " << eT[i] -> getV2() << ") ";
    }
    std::cout << std::endl;
    
    // free memory
    delete[] eT;
    delete[] pq;
    delete candidateSet;
    eT = NULL;
    pq = NULL;
    candidateSet = NULL;
}

void Spanner::prims() {
    EdgeNode** eT = new EdgeNode*[dim - 1];
    for (int i = 0; i < dim - 1; i++) {
        eT[i] = NULL;
    }
    int* vT = new int[dim];
    for (int i = 0; i < dim; i++) {
        vT[i] = -1;
    }
    vT[0] = 0;

    pq = new EdgeNode*[dim * dim];
    int k = 0;
    for (int i = 1; i < dim; i++) {
        if (adjMatrix[0][i] != 0) {
            pq[k] = new EdgeNode(adjMatrix[0][i], 0, i);
            k++;
        }
    }
    sort(pq, dim * dim);

    /*
     * Begin Prims
     */
    EdgeNode* x;
    int cardinality = 0;
    while (!(emptyQueue(pq, dim * dim)) && cardinality != dim) {
        x = dequeue(pq, dim * dim);
        eT[cardinality] = x;
        vT[cardinality + 1] = x -> getV2();
        cardinality++;
    
        updateQueue(pq, vT);
    }
    for (int i = 0; i < dim - 1; i++) {
        if (eT[i] == NULL) {
            std::cout << "No solution" << std::endl;
            return;
        }
    }
    for (int i = 0; i < dim - 1; i++) {
        std::cout << "(" << eT[i] -> getV1() << ", " << eT[i] -> getV2() << ") ";
    }
    std::cout << std::endl;

    // free memory
    delete[] eT;
    delete[] vT;
    delete[] pq;
    eT = NULL;
    vT = NULL;
    pq = NULL;
}

/*
 * These helper functions in lieu of a full key/value supporting heap
 */
void Spanner::sort(EdgeNode** pq, int size) {
    EdgeNode* swap;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (pq[j + 1] == NULL || pq[j] -> getWeight() > pq[j + 1] -> getWeight()) {
                swap = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = swap;
            }
        }
    }
}

bool Spanner::element(int elem, int* vT) {
    for (int i = 0; i < dim; i++) {
        if (vT[i] == elem) {
            return true;
        }
    }
    return false;
}

EdgeNode* Spanner::dequeue(EdgeNode** pq, int size) {
    for (int i = 0; i < size; i++) {
        if (pq[i] != NULL) {
            return pq[i];
        }
    }
    return NULL;
}

void Spanner::updateQueue(EdgeNode** pq, int* vT) {
    for (int i = 0; i < dim * dim; i++) {
        pq[i] = NULL;
    }

    int k = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (adjMatrix[i][j] != 0 && element(i, vT) && !(element(j, vT))) {
                pq[k] = new EdgeNode(adjMatrix[i][j], i, j);
                k++;
            }
        }
    }
    sort(pq, dim * dim);
}

bool Spanner::emptyQueue(EdgeNode** pq, int size) {
    for (int i = 0; i < size; i++) {
        if (pq[i] != NULL) {
            return false;
        }
    }
    return true;
}
