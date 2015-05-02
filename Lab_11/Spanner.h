#ifndef _SPANNER
#define _SPANNER

class Spanner {
    private:
        DisjointSet<int> candidateSet;
        
        int** adjMatrix;
        int dim;

    public:
        Spanner();
        Spanner(int** matrix, int dimension);
        virtual ~Spanner();
        
        kruskals();
        prims();
};

#include "Spanner.cpp"
#endif
