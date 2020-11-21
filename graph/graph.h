/**
 * head file for Graph class
 * @file graph.h
 */
#pragma once

#include <initializer_list>
#include "edge.h"
#include "vector"
#include "list"
#include "unordered_map"

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
    
    //Vertex related

    /**
     * insert a vertex with no edge
     * @param v represents target vertex 
     */
    void insertVertex(const K& v);
    
    /**
     * remove a vertex and all edges related to it
     * @param v represents target vertex
     */
    void removeVertex(const K& v);
    
    /**
     * Gets all adjacent vertices to the parameter vertex.
     * @param v represents target vertex
     * @return vector of vertices who is neighbour of target vertex
     */
    std::vector<K> getAdjacent(const K& v) const;
    
    /**
     * check if a vertex exists
     * @param v represents target vertex
     * @return true if target vertex exists
     */
    bool vertextExists(const K& v) const;
    
    //edge related

    /**
     * insert an edge from v1 to v2 with weight 
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     * @param weight represents weight (set to V() by default)
     */
    void insertEdge(const K& v1, const K& v2, const V& weight = V());
    

    /**
     * remove an edge from v1 to v2
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     */
    void removeEdge(const K& v1, const K& v2);


    /**
     * initilize or reset the weight of an edge
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     * @param weight represents target weight (set to V() by default)
     */
    void setEdgeWeight(const K& v1, const K& v2, const V& weight = V());
    

    /**
     * get weight of an edge
     * @param v1 represents source vertex
     * @param v2 represents destination vertex
     */
    void getEdgeWeight(const K& v1, const K& v2) const;

    /**
     * check if an edge exists
     * @param v1 represents source vertex of the edge
     * @param v2 represents desitination vertex of the edge
     * @return true if the dege exists
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
    std::vector<K> shortestPath(K v1, K v2) const;

    /**
     * get the shortest distance from source to target
     * @param v1 represents source vertex
     * @param v2 represents target vertex
     * @return the distance from source to target
     * If there is no such a path, return V()
     */
    V shortestDis(K v1, K v2) const;
    
     /**
     * check if source vertex is connected with target 
     * (if we could go from source to target)
     * @param v1 represents source vertex
     * @param v2 represents target vertex
     * @return true if they are connected
     */
    bool ifConnected(K v1, K v2) const;

private:

    class Vertex {
        public:
        
        Vertex(const K& v, const std::list<V>& edges = std::list<V>()) {
            value = v;
            this->edges = edges;
        }

        K value;
        std::list<V> edges;
    };
    

    std::unordered_map<K, Vertex> vertices_;
};

