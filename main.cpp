#include <iostream>
#include "graph/graph.h"
#include "graph/edge.h"
#include "graph/BFStraversal.h"

int main() {
    std::cout << "hello world" << std::endl;
    Graph<int, int> graph{1, 2, 3, 4};
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(3, 4);
    BFStraversal<int, int> test(graph, 1);
    for (auto i = test.begin(); i != test.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}