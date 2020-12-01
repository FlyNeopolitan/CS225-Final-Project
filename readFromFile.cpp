#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include "readFromFile.hpp"

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
		res.push_back(str.substr(0,pos));
		str=str.substr(pos+1,str.size());
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
