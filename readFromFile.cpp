#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include "readFromFile.hpp"
#include "math.h"

using std::pair;


// we do not use this function
// drawbacks: the buffer is too large, not good for performance; and not sliced by delim
std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}


// we do not use this function either
// drawbacks: the delimeter is white space, not slicing the file the way we want
std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
}


// helper function, split string
std::vector<std::string> split(std::string str,std::string delim){
	std::vector<std::string> res;
	if (str=="") return res;

	while(1){
		size_t pos=str.find(delim);
		if(pos==str.npos) break;
		// if there is delim in the contents enclosed by ""
        if(str[0]=='\"' && str[pos]!='\"'){
            for (size_t i=1;i<str.length();i++){
                if(str[i]=='\"') {pos=i+1; break;}
            }
        }
		res.push_back(str.substr(0,pos));
		str=str.substr(pos+1);
	}
	res.push_back(str);
	return res;
}


// You may access the data in the file in the form :
// For example: data[0][0] for the first column in the first line
// Another usage: data.size() to get the total line in the data
// Yet another: data[0].size() to get the colomn number in the data
std::vector<std::vector<std::string>> line_to_vector(const std::string & filename,std::string delim){
	std::ifstream infile(filename);
	std::vector<std::vector<std::string>> res;
	// check if the file is open
	if(!infile.is_open()){
		perror("fopen");
		return res;
	}

	//std::vector<std::string> res;
	std::string line;
	while(getline(infile,line)){
		res.push_back(split(line,delim));
	}
	return res;
}


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
            if (lookSrc != airports.end() && lookDes != airports.end()) {
                double dis = distance(lookSrc->second, lookDes->second);
                graph.insertEdge(route.first, route.second, dis);
            }           
        }
        return graph; 
}


double distance(const pair<double, double>& source, const pair<double, double>& des) {
    double x = std::min(abs(source.second - des.second), 360 - abs(source.second - des.second));
    double s = (source.first - des.first) * (source.first - des.first) + x * x;
    return std::sqrt(s);
}

