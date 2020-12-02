#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch2/catch.hpp"
#include "../graph/graph.h"
#include "../graph/BFStraversal.h"

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
    //
    SECTION("insertVertex: simple test"){
        Graph<std::string, int> test;
        test.insertVertex("a");
        test.insertVertex("b");
        test.insertVertex("c");
        test.insertVertex("a");
        //test size
        REQUIRE(test.verticesSize() == 3);
        //test exisitence
        REQUIRE(test.vertexExists("a"));
        REQUIRE(test.vertexExists("b"));
        REQUIRE(test.vertexExists("c"));
    }
    SECTION("removeVertex: simple test"){
        Graph<std::string, int> test{"a","b","c"};
        test.removeVertex("a");
        REQUIRE(!test.vertexExists("a"));
        test.removeVertex("b");
        REQUIRE(!test.vertexExists("b"));
        test.removeVertex("c");
        REQUIRE(!test.vertexExists("c"));
        REQUIRE(test.verticesSize() == 0);
    }
    SECTION("getAdjacent: simple test"){
        Graph<std::string, int> test{"a", "b", "c"};
        test.insertEdge("a", "b");
        test.insertEdge("a", "c");
        std::vector<std::string> res=test.getAdjacent("a");
        REQUIRE(std::find(res.begin(),res.end(),"b")!=res.end());
        REQUIRE(std::find(res.begin(),res.end(),"c")!=res.end());
    }

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
    SECTION("Edge insert: simple test") {
        Graph<std::string, int> test{"a", "b", "c"};

        test.insertEdge("a", "c");
        test.insertEdge("a", "b", 1);
        REQUIRE(test.edgetExists("b", "c") == false); // a->c and a->b doesn't imply b->c
        REQUIRE(test.insertEdge("a", "a", 1) == false); // vertices are identical
        REQUIRE(test.getEdgeWeight("a", "b") == 1);
        REQUIRE(test.edgetExists("a", "b") == true); // with the direction
        REQUIRE(test.edgetExists("b", "a") == false); // against the direction

        REQUIRE(test.insertEdge("a", "b", 2) == false); // edge already exists
        test.insertEdge("b", "a", 2);
        REQUIRE(test.getEdgeWeight("b", "a") == 2);
        REQUIRE(test.edgetExists("b", "a") == true);
    }

    SECTION("Edge remove: simple test") {
        Graph<std::string, int> test{"a", "b", "c"};

        test.insertEdge("a", "b");
        REQUIRE(test.edgetExists("a", "b") == true);
        REQUIRE(test.removeEdge("a", "a") == false); // vertices are identical

        test.removeEdge("a", "b");
        REQUIRE(test.edgetExists("a", "b") == false);
        REQUIRE(test.removeEdge("a", "b") == false); // edge doesn't exist
        REQUIRE(test.removeEdge("a", "c") == false);
    }

    SECTION("Set edge weight: simple test") {
        Graph<std::string, int> test{"a", "b"};

        test.insertEdge("a", "b", 1);
        REQUIRE(test.setEdgeWeight("a", "a", 2) == false); // vertices are identical
        REQUIRE(test.setEdgeWeight("a", "c", 2) == false); // edge doesn't exist

        test.setEdgeWeight("a", "b", 2);
        REQUIRE(test.getEdgeWeight("a", "b") == 2);
    }

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


TEST_CASE("Traversal") {

    SECTION("BFS Traversal : traversal objects simple test") {
        Graph<int, int> graph{1, 2, 3, 4, 5, 6, 7, 8, 9};
        graph.insertEdge(1, 2);
        graph.insertEdge(1, 3);
        graph.insertEdge(3, 4);
        graph.insertEdge(4, 7);
        graph.insertEdge(7, 5);
        graph.insertEdge(5, 8);
        graph.insertEdge(5, 6);
        graph.insertEdge(5, 7);
        graph.insertEdge(5, 1);
        BFStraversal<int, int> test(graph, 1);
        std::set<int> traversal;
        for (auto i : test) {
            traversal.insert(i);
        }
        REQUIRE(traversal == std::set<int>{1,2,3,4,5,6,7,8});
    }

    SECTION("BFS Traversal : traversal order simple test") {
        Graph<int, int> graph{1, 2, 3, 4, 5, 6, 7, 8, 9};
        graph.insertEdge(1, 4);
        graph.insertEdge(1, 3);
        graph.insertEdge(1, 2);
        graph.insertEdge(4, 7);
        graph.insertEdge(3, 6);
        graph.insertEdge(2, 5);
        graph.insertEdge(7, 8);
        graph.insertEdge(3, 4);
        graph.insertEdge(2, 3);
        BFStraversal<int, int> test(graph, 1);
        std::vector<int> actual;
        for (auto i : test) {
            actual.push_back(i);
        }
        REQUIRE(actual == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
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