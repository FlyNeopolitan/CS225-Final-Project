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
    //to do
}


template<typename K, typename V>
void Graph<K, V>::removeEdge(const K& v1, const K& v2) {
    //to do
}


template<typename K, typename V>
void Graph<K, V>::setEdgeWeight(const K& v1, const K& v2, const V& weight) {
    //do to
}


template<typename K, typename V>
void Graph<K, V>::getEdgeWeight(const K& v1, const K& v2) const {
    //to do
}


template<typename K, typename V>
bool Graph<K, V>::edgetExists(const K& v1, const K& v2) const {
    //to do
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


