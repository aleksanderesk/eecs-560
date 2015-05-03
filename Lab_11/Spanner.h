#ifndef _SPANNER
#define _SPANNER

#include <iostream>
#include "EdgeNode.h"
#include "DisjointSet.h"

class Spanner {
    private:
        DisjointSet<int>* candidateSet;
        EdgeNode** pq;
        int** adjMatrix;
        int dim;

        void bubbleSort(EdgeNode** pq, int size);
        bool emptyQueue(EdgeNode** pq, int size);

    public:
        Spanner();
        Spanner(int** matrix, int dimension);
        virtual ~Spanner();
        
        void kruskals();
        //void prims();
};

#include "Spanner.cpp"
#endif
