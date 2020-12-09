/**
 * head and implementation file for DFStraversal class
 * @file graph/DFStraversal.h
 */

#pragma once
#include "graphIterator.h" 

// we don't implement DFS (DFS is not a good idea for large data set)
template<typename K, typename V>
class DFStraversal : GraphTraversal<K> {

public:

    DFStraversal(Graph<K, V> graph);

    typename GraphTraversal<K>::Iterator begin();

    typename GraphTraversal<K>::Iterator end();

    void add(K currentVertex);

    K pop();

    K peek() const;

    bool empty() const;

private:

};
