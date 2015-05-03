/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Class description for Spanner, which finds the minimum spanning tree
 * of an adjacency matrix using Kruskal's and Prim's algorithms
 */
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

        void sort(EdgeNode** pq, int size);
        bool element(int elem, int* vT);
        EdgeNode* dequeue(EdgeNode** pq, int size);
        void updateQueue(EdgeNode** pq, int* vT);
        bool emptyQueue(EdgeNode** pq, int size);

    public:
        Spanner();
        Spanner(int** matrix, int dimension);
        virtual ~Spanner();
        
        void kruskals();
        void prims();
};

#include "Spanner.cpp"
#endif
