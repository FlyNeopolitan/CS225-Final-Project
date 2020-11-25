#include "graph.h"

//constructors

template<class K, class V>
Graph<K, V>::Graph() {
    //seems nothing here
}

template<typename K, typename V>
Graph<K, V>::Graph(const std::initializer_list<K> VertexList) {
    //insert the vertecies in the VertexList into the adjacent list
    vertices_.insert(vertices_.end(),VertexList.begin(),VertexList.end());
}

//vertex-related implementation

template<typename K, typename V>
void Graph<K, V>::insertVertex(const K& v) {
    //to do
}


template<typename K, typename V>
void Graph<K, V>::removeVertex(const K& v) {
    //to do
}


template<typename K, typename V>
std::vector<K> Graph<K, V>::getAdjacent(const K& v) const{
    //to do
}


template<typename K, typename V>
bool Graph<K, V>::vertextExists(const K& v) const {
    //to do
}

//edge-related implementation

template<typename K, typename V>
void Graph<K, V>::insertEdge(const K& v1, const K& v2, const V& weight) {
    // if the edge already exists
    if (vertices_.find(v1) != vertices_.end() && vertices_[v1].find(v2) != vertices_.end())
        return;

    if (vertices_.find(v1) == vertices_.end())
        vertices_[v1] = unordered_map<K, Edge<K, V>>();

    vertices_[v1][v2] = Edge<K, V>(v1, v2, weight);
}


template<typename K, typename V>
bool Graph<K, V>::removeEdge(const K& v1, const K& v2) {
    if (!edgetExists(v1, v2))
        return false;

    Edge<K, V> e = vertices_[v1][v2];
    vertices_[v1].erase(v2);
    return true;
}


template<typename K, typename V>
bool Graph<K, V>::setEdgeWeight(const K& v1, const K& v2, const V& weight) {
    if (!edgetExists(v1, v2))
        return false;

    Edge<K, V> new_edge(v1, v2, weight);
    vertices_[v1][v2] = new_edge;
    return true;
}


template<typename K, typename V>
V Graph<K, V>::getEdgeWeight(const K& v1, const K& v2) const {
    if (!edgetExists(v1, v2))
        return V(-1);

    return vertices_[v1][v2].getEdgeWeight();
}


template<typename K, typename V>
bool Graph<K, V>::edgetExists(const K& v1, const K& v2) const {
    if (!vertextExists(v1))
        return false;
    if (vertices_[v1].find(v2) == vertices_[v1].end())
        return false;

    return true;
}

//advanced algorithems

template<typename K, typename V>
unsigned Graph<K, V>::BetweenessCentrality(const K& v) const {
    //to do
}


template<typename K, typename V>
std::vector<K> Graph<K, V>::shortestPath(K v1, K v2) const {
    //to do
}


template<typename K, typename V>
V Graph<K, V>::shortestDis(K v1, K v2) const {
    //to do
}


template<typename K, typename V>
bool Graph<K, V>::ifConnected(K v1, K v2) const {
    //to do
}


