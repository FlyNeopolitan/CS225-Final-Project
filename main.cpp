#include <iostream>
#include "graph/graph.h"
#include "graph/edge.h"
#include "graph/BFStraversal.h"
#include "readFromFile.hpp"
#include "map"
#include  <math.h>

unordered_map<std::string, pair<double, double>> readAirports(const std::string& filename);

std::vector<pair<std::string, std::string>> readRoutes(const std::string& filename);

Graph<std::string, double> openFlightsGraph(const unordered_map<std::string, pair<double, double>>& airports, 
    const std::vector<pair<std::string, std::string>>& routes);

double distance(const pair<double, double>& source, const pair<double, double>& des);

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
    //sample : read in sample 
    auto airports = readAirports("data/sample_airports.txt");
    for (auto& i : airports) {
        std::cout << i.first <<" "<< i.second.first << " "<< i.second.second << std::endl;
    }
    auto routes = readRoutes("data/sample_routes.txt");
    for (auto& i : routes) {
        std::cout << i.first << " " << i.second << std::endl;
    }
    auto sampleGraph = openFlightsGraph(airports, routes);
    BFStraversal<std::string, double> traversal(sampleGraph, "KZG");
    for (const auto& i : traversal) {
        std::cout << i << std::endl;
    }
}

unordered_map<std::string, pair<double, double>> readAirports(const std::string& filename) {
    unordered_map<std::string, pair<double, double>> ans;
    auto lines = line_to_vector(filename, ",");
    for (auto line : lines) {
        auto name = line[4];
        name.erase(std::remove(name.begin(), name.end(), '"'), name.end());
        ans[name] = pair<double, double>(std::stod(line[6]), std::stod(line[7]));
    }
    return ans;
}

std::vector<pair<std::string, std::string>> readRoutes(const std::string& filename) {
    std::vector<pair<std::string, std::string>> routes;
    auto lines = line_to_vector(filename, ",");
    for (auto line : lines) {
        auto source = line[2];
        auto des = line[4];
        routes.push_back(pair<std::string, std::string>(source, des));
    }
    return routes;
}

Graph<std::string, double> openFlightsGraph(const unordered_map<std::string, pair<double, double>>& airports, 
    const std::vector<pair<std::string, std::string>>& routes) {
        std::vector<std::string> airportNames;
        for (auto& i : airports) {
            airportNames.push_back(i.first);
        }
        Graph<std::string, double> graph(airportNames);
        for (auto& route : routes) {
            auto lookSrc = airports.find(route.first);
            auto lookDes = airports.find(route.second);
            double dis = distance(lookSrc->second, lookDes->second);
            graph.insertEdge(route.first, route.second, dis);
        }
        return graph; 
}

double distance(const pair<double, double>& source, const pair<double, double>& des) {
    double s = (source.first - des.first) * (source.first - des.first) + (source.second - des.second) * (source.second - des.second);
    std::cout << s << std::endl;
    return std::sqrt(s);
}
