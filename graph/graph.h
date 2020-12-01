/**
 * head file for Graph class
 * @file graph.h
 */
#pragma once

#include "edge.h"
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <initializer_list>
#include <set>

using std::pair;
using std::vector;
using std::unordered_map;

template<class K, class V>
class Graph {

public:
    //Constructors

    /**
     * defualt constructor
    */
    Graph();

    /**
     * Using vertices to initilize a graph with no edge
     * @param VertexList represents vertex list
    */
    Graph(const std::initializer_list<K> VertexList);

    /**
     * Using vertices to initilize a graph with no edge
     * @param VertexVector represents vertex vector
    */
    Graph(const std::vector<K> VertexVector);

    //Vertex related

    /**
     * insert a vertex with no edge
     * @param v represents target vertex
     */
    void insertVertex(const K& v);

    /**
     * remove a vertex and all edges related to it
     * @param v represents target vertex
     * @return whether removing the vertex was successful
     */
    bool removeVertex(const K& v);

    /**
     * Gets all adjacent vertices to the parameter vertex.
     * @param v represents target vertex
     * @return vector of vertices who is neighbour of target vertex
     */
    vector<K> getAdjacent(const K& v) const;

    /**
     * check if a vertex exists
     * @param v represents target vertex
     * @return true if target vertex exists
     */
    bool vertexExists(const K& v) const;

    //edge related

    /**
     * insert an edge from v1 to v2 with weight
     * When the edge exists, it will not change the weight of that edge
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     * @param weight represents weight (set to V() by default)
     * @return whether inserting the edge was successful
     */
    bool insertEdge(const K& v1, const K& v2, const V& weight = V());

    /**
     * remove an edge from v1 to v2
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     * @return whether removing the edge was successful
     */
    bool removeEdge(const K& v1, const K& v2);

    /**
     * initilize or reset the weight of an edge
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     * @param weight represents target weight (set to V() by default)
     * @return whether setting weight of the edge was successful
     */
    bool setEdgeWeight(const K& v1, const K& v2, const V& weight = V());

    /**
     * get weight of an edge
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     * @return whether getting weight of the edge was successful
     */
    V getEdgeWeight(const K& v1, const K& v2) const;

    /**
     * check if an edge exists
     * @param v1 represents source vertex of the edge
     * @param v2 represents desitination vertex of the edge
     * @return whether the edge exists
     */
    bool edgetExists(const K& v1, const K& v2) const;

    //advanced algorithems

    /**
     * @param v represents target vertex
     * @return the time shortest path go through it
     */
    unsigned BetweenessCentrality(const K& v) const;


    /**
     * get the shortest path from source to target
     * @param v1 represents source vertex
     * @param v2 represents target vertex
     * @return a vector with vertex from source to target (including)
     * For example, {v1,v3,v2} indicates that path is v1->v3->v2 for shortestPath(v1,v3)
     * If there is no such a path, return an empty vector
     */
    vector<K> shortestPath(K v1, K v2) const;

    /**
     * get the shortest distance from source to target
     * @param v1 represents source vertex
     * @param v2 represents target vertex
     * @return the distance from source to target
     */
    int shortestDis(K v1, K v2) const;

     /**
     * check if source vertex is connected with target
     * (if we could go from source to target)
     * @param v1 represents source vertex
     * @param v2 represents target vertex
     * @return true if they are connected
     */
    bool ifConnected(K v1, K v2) const;

    /**
     * @return the size of vertices
     */
    unsigned verticesSize();

private:

    class Vertex {

        public:
            Vertex(const K& v) {
                value = v;
            }

        private:
            K value;
    };

    mutable unordered_map<K, unordered_map<K, Edge<K, V>>> vertices_;
};

#include "graph.hpp"

