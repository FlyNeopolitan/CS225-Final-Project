#include <string>
#include <vector>

// adapted from CS 225 Final Project AMA

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