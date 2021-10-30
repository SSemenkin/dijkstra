#include <iostream>
#include <fstream>

#include "myvector/vector.h"

using bicycle::Vector;

struct Edge {
    int m_distance;
    int m_toEdge;
};

struct Node {
    int m_id;
    Vector<Edge> m_edges;
};

class Graph {
public:
    Graph(const Vector<Node> &nodes) : m_nodes(nodes) {

    }

private:
    Vector<Node> m_nodes;
};



int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;


    return 0;
}

