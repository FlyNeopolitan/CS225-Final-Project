#include <iostream>
#include "graph/graph.h"
#include "graph/edge.h"
#include "graph/BFStraversal.h"
#include "readFromFile.hpp"
#include "map"

//helper method to print out results

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
void printTraversal(const Graph<std::string, double>& graph, std::string start);

/**
 * calculate the centrality, and print it out
 * @param graph represents graph 
 * @param target represents centrality we want to calculate
 */
void printCentrality(const Graph<std::string, double>& graph, std::string target);

/**
 * print shortest distance and paths from source to destination
 * @param graph represents graph
 * @param source represents source 
 * @param destination represents destination
 */
void printShortest(const Graph<std::string, double>& graph, std::string source, std::string destination);

//executable

int main() {
    //sample : read in airports and print out
    auto airports = readAirports("data/sample_airports.txt");
    printAirports(airports);
    //sample : read in routes and print out
    auto routes = readRoutes("data/sample_routes.txt");
    printRoutes(routes);
    //sample : graph construction 
    auto sampleGraph = openFlightsGraph(airports, routes);
    //sample : do a traversal, and print out
    printTraversal(sampleGraph, "LAE");
    //sample : find shortes path between two airport and print out
    printShortest(sampleGraph, "LAE", "HGU");
    //sample : calculate betweenness centrality of a airport and print out
    printCentrality(sampleGraph, "LAE");
}

//implementaion of helper methods
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


void printTraversal(const Graph<std::string, double>& graph, std::string start) {
    std::cout << std::endl << "Let's do a traversal, from airport: " + start << std::endl;
    BFStraversal<std::string, double> traversal(graph, start);
    for (const auto& i : traversal) {
        std::cout << "Currently we are here: " << i << std::endl;
    }
    std::cout << "Traversal finish" << std::endl;
}


void printCentrality(const Graph<std::string, double>& graph, std::string target) {
    std::cout << std::endl << "The Centrality of " + target + ": " << graph.BetweenessCentrality("LAE") << std::endl;
}


void printShortest(const Graph<std::string, double>& graph, std::string source, std::string destination) {
    auto distance = graph.shortestDis(source, destination);
    auto path = graph.shortestPath(source, destination);
    std::cout << std::endl << "The shortest distance between " + source + " and " + destination + ": " << distance << std::endl;
    std::cout << "The shortest path acorrdingly:" << std::endl;
    for (auto& node : path) {
        std::cout << node << std::endl;
    }
}
