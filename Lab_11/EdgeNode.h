/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Class definition for Edge Node, representing an edge between two vertices
 */
#ifndef _EDGE
#define _EDGE

class EdgeNode {
    private:
        int w;
        int v1;
        int v2;

    public:
        EdgeNode();
        EdgeNode(const int weight, const int vert1, const int vert2);

        void setWeight(const int weight);
        void setV1(const int vert1);
        void setV2(const int vert2);
        int getWeight() const;
        int getV1() const;
        int getV2() const;
};

#include "EdgeNode.cpp"
#endif
