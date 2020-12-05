#include <iostream>
#include "graph/graph.h"
#include "graph/edge.h"
#include "graph/BFStraversal.h"
#include "readFromFile.hpp"
#include "map"
#include  <math.h>

/**
 * get airports data from file
 * @param filename represents airports file
 * @return a unordered_map whose key is the name of airport and value is the location of airport
 */
unordered_map<std::string, pair<double, double>> readAirports(const std::string& filename);

/**
 * get routes data from file
 * @param filename represents routes file
 * @return a vector of pair of routes(pair's first is source airports, and pair's second is destination)
 */
std::vector<pair<std::string, std::string>> readRoutes(const std::string& filename);

/**
 * get a graph based on airports data and routes data
 * @param airports represents airports data
 * @param routes represents routes data
 * @return a directed graph whose vertex represents name of airport and edge represents route
 * weight = distance(source, destination)
 */
Graph<std::string, double> openFlightsGraph(const unordered_map<std::string, pair<double, double>>& airports, 
    const std::vector<pair<std::string, std::string>>& routes);

/**
 * calculate distance between source and destination
 * @param source represents source's location
 * @param des represents destination's location
 * @return the distance between source and destination
 */
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
    //sample : read in airports
    auto airports = readAirports("data/sample_airports.txt");
    std::cout << std::endl << "We have these airports: " << std::endl;
    for (auto& i : airports) {
        std::cout << "Name: " << i.first <<" Lontitude: "<< i.second.first << " Latitude: "<< i.second.second << std::endl;
    }
    //sample : read in routes
    auto routes = readRoutes("data/sample_routes.txt");
    std::cout << std::endl << "We have these routes: " << std::endl;
    for (auto& i : routes) {
        std::cout << "Source: " << i.first << " Destination: " << i.second << std::endl;
    }
    //sample : graph construction 
    auto sampleGraph = openFlightsGraph(airports, routes);
    //sample : do a traversal
    std::cout << std::endl << "Let's do a traversal, from airport LAE" << std::endl;
    BFStraversal<std::string, double> traversal(sampleGraph, "LAE");
    for (const auto& i : traversal) {
        std::cout << "Currently we are here: " << i << std::endl;
    }
    //other samples....
}

//implementaion of helper method

unordered_map<std::string, pair<double, double>> readAirports(const std::string& filename) {
    unordered_map<std::string, pair<double, double>> ans;
    auto lines = line_to_vector(filename, ",");
    for (auto line : lines) {
        auto name = line[4];
        name.erase(std::remove(name.begin(), name.end(), '"'), name.end());
        if (name.find("\N") == std::string::npos) {      
            ans[name] = pair<double, double>(std::stod(line[6]), std::stod(line[7]));
        }            
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
    return std::sqrt(s);
}

