#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch2/catch.hpp"
#include "../graph/graph.h"

//help method
void stringNext(std::string& current);
int randomInt(int min, int max);

//test part

TEST_CASE("Constructor") {

    SECTION("default constructor") {
        Graph<std::string, int> test;
        REQUIRE(test.verticesSize() == 0);
    }

    SECTION("initialize list constructor : simple test") {
        Graph<std::string, int> test{"a", "b", "c", "a"};
        //test size
        REQUIRE(test.verticesSize() == 3);
        //test exisitence
        REQUIRE(test.vertexExists("a"));
        REQUIRE(test.vertexExists("b"));
        REQUIRE(test.vertexExists("c"));
        //test non edges
        REQUIRE(test.getAdjacent("a").empty());
        REQUIRE(test.getAdjacent("b").empty());
        REQUIRE(test.getAdjacent("c").empty());
    }

    SECTION("vector constructor : simple test") {
        std::vector<std::string> names{"a", "b", "c"};
        Graph<std::string, int> test(names);
        //test size
        REQUIRE(test.verticesSize() == 3);
        //test exisitence
        REQUIRE(test.vertexExists("a"));
        REQUIRE(test.vertexExists("b"));
        REQUIRE(test.vertexExists("c"));
        //test non edges
        REQUIRE(test.getAdjacent("a").empty());
        REQUIRE(test.getAdjacent("b").empty());
        REQUIRE(test.getAdjacent("c").empty());
    }
}


TEST_CASE("Vertx related") {
    //to do


    //
    SECTION("Vertex exists") {
        std::vector<std::string> names;
        std::string current_name = "no";
        for (int i = 0; i < 100; ++i) {
            names.push_back(current_name);
            stringNext(current_name);
        }
        Graph<std::string, int> test(names);
        std::string expected_name = "no";
        for (int i = 0; i < 100; ++i) {
            REQUIRE(test.vertexExists(expected_name));
            stringNext(expected_name);
        } 
    }
}


TEST_CASE("Edge related") {
    //to do

    //
    SECTION("Edge exists : simple test") {
        Graph<std::string, int> test{"a", "b", "c", "d"};
        //first insertion
        test.insertEdge("a", "b");
        REQUIRE(test.edgetExists("a", "b"));
        REQUIRE(!test.edgetExists("b", "a"));
        //second insertion
        test.insertEdge("a", "c");
        REQUIRE(test.edgetExists("a", "c"));
        REQUIRE(!test.edgetExists("c", "a"));
        //third insertion
        test.insertEdge("b", "c");
        REQUIRE(test.edgetExists("b", "c"));
        REQUIRE(!test.edgetExists("c", "b"));
    }

    SECTION("Get edge weight : simple test") {
        Graph<std::string, int> test{"a", "b", "c", "d"};
        //first insertion
        test.insertEdge("a", "b", 1);
        REQUIRE(test.getEdgeWeight("a", "b") == 1);
        //second insertion
        test.insertEdge("a", "c", 2);
        REQUIRE(test.edgetExists("a", "c"));
        REQUIRE(test.getEdgeWeight("a", "c") == 2);
        //third insertion
        test.insertEdge("b", "c", 3);
        REQUIRE(test.edgetExists("b", "c"));
        REQUIRE(test.getEdgeWeight("b", "c") == 3);
    }

    SECTION("Edge exists and edge weight : random complex test") {
        const int verticsNum = 100;
        const int testNum = 500;
        const int weightBound = 1000;
        std::vector<int> index;
        for (int i = 0; i < verticsNum; ++i) {
            index.push_back(i);
        }
        Graph<int, int> test(index);
        for (int i = 0; i < testNum; ++i) {
            int a = randomInt(0, verticsNum - 1);
            int b = randomInt(0, verticsNum - 1);
            int c = randomInt(0, weightBound - 1);
            if (test.insertEdge(a, b, c)) {
                REQUIRE(test.edgetExists(a, b));
                REQUIRE(test.getEdgeWeight(a, b) == c);
            }
        }
    }
}




//helper method to get next string
void stringNext(std::string& current) {
    current  = current + "a";
}

//helper method to get a random int between min and max
int randomInt(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}