#include "iostream"
#include "graph/graph.h"
#include "graph/edge.h"
#include "graph/BFStraversal.h"

int main() {
    std::cout << "hello world" << std::endl;
    Graph<std::string, int> graph{"a", "b", "c"};
    BFStraversal<std::string, int> test(graph, "a");
    


}