#pragma once

#include "graphIterator.h" 
#include <queue>
#include <set>

template<typename K, typename V>
class BFStraversal : GraphTraversal<K> {

public:
    
    BFStraversal(Graph<K, V> graph, K startingPoint) : start(startingPoint) {
        this->graph = graph;
        if (!graph.vertexExists(start)) {
            throw std::invalid_argument("start point doesn't exist");
        }
        Queue.push(start);
    }

    typename GraphTraversal<K>::Iterator begin() {
        return typename GraphTraversal<K>::Iterator(this, start);
    }

    typename GraphTraversal<K>::Iterator end() {
        return typename GraphTraversal<K>::Iterator(this, K());
    }

    void add(K currentVertex) {
        for (auto neighbour : graph.getAdjacent(currentVertex)) {
            if (visited.find(neighbour) == visited.end()) {
                Queue.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }

    K pop() {
        K current = Queue.front();
        Queue.pop();
        return current;
    }

    K peek() const {
        if (Queue.empty()) {
            return K();
        } else {
            return Queue.front();
        }
    }

    bool empty() const {
        return Queue.empty();
    }

private:
    K start;
    Graph<K, V> graph;
    std::queue<K> Queue;
    std::set<K> visited;
};