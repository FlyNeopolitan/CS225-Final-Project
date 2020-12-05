#include <iostream>
#include "graph/graph.h"
#include "graph/edge.h"
#include "graph/BFStraversal.h"
#include "readFromFile.hpp"
#include "map"

/**
 * print airports
 * @param airports represents airports data
 */
void printAirports(const std::unordered_map<std::string, std::pair<double, double>>& airports);

/**
 * print routes
 * @param routes represents routes data
 */
void printRoutes(const std::vector<std::pair<std::string, std::string>>& routes);

/**
 * do a traversal and print the processs
 * @param graph represents graph to traverse
 * @param start represents start point
 */
void printTraversal(Graph<std::string, double>& graph, std::string start);

int main() {
    //sample : BFS traversal for graph
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
    //sample : read in airports
    auto airports = readAirports("data/sample_airports.txt");
    printAirports(airports);
    //sample : read in routes
    auto routes = readRoutes("data/sample_routes.txt");
    printRoutes(routes);
    //sample : graph construction 
    auto sampleGraph = openFlightsGraph(airports, routes);
    //sample : do a traversal
    printTraversal(sampleGraph, "LAE");
    //shortes path
    auto distance = sampleGraph.shortestDis("LAE", "GOH");
    auto path = sampleGraph.shortestPath("LAE", "GOH");
    std::cout << distance << std::endl;
    for (auto& node : path) {
        std::cout << node << std::endl;
    }
    //centrality
    std::cout <<sampleGraph.BetweenessCentrality("KZG") << std::endl;
}

void printAirports(const std::unordered_map<std::string, std::pair<double, double>>& airports) {
    std::cout << std::endl << "We have these airports: " << std::endl;
    for (auto& i : airports) {
        std::cout << "Name: " << i.first <<" Lontitude: "<< i.second.first << " Latitude: "<< i.second.second << std::endl;
    }
}

void printRoutes(const std::vector<std::pair<std::string, std::string>>& routes) {
    std::cout << std::endl << "We have these routes: " << std::endl;
    for (auto& i : routes) {
        std::cout << "Source: " << i.first << " Destination: " << i.second << std::endl;
    }
}

void printTraversal(Graph<std::string, double>& graph, std::string start) {
    std::cout << std::endl << "Let's do a traversal, from airport: " + start << std::endl;
    BFStraversal<std::string, double> traversal(graph, start);
    for (const auto& i : traversal) {
        std::cout << "Currently we are here: " << i << std::endl;
    }
}
