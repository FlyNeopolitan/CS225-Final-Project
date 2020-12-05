#pragma once
#include <string>
#include <vector>
#include "graph/graph.h"


/** 
 * Reads a file into a string
 * @param filename The file to read from 
 * @return a string containing filename's contents
 */
std::string file_to_string(const std::string & filename);

/** 
 * Reads a file into a vector
 * @param filename The file to read from
 * @return a vector containing filename's contents
 */
std::vector<std::string> file_to_vector(const std::string & filename);

/**
 * Helper function to split an input string using the delim given
 * @param str The string to parse
 * @param delim The delim given to split the string
 * @return a vector containing the string parsed by the delim
 */
std::vector<std::string> split(std::string str,std::string delim);

/**
 * Reads a file into a vector of vectors containing vectors of line being parsed by the given delimiters
 * @param filename The filename to parse by line and delimiters
 * @param delim The delim given to split the line
 * @return a vector of vectors, containing the vectors of line parsed by the delim
 */
std::vector<std::vector<std::string>> line_to_vector(const std::string & filename,std::string delim);

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

