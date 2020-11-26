#pragma once

template<typename K, typename V>
class Edge {

public:
    
    /**
     * default constructor
     */
    Edge() {
        //do nothing
    }

    /**
     * constructor for edge
     */
    Edge(const K& source, const K& dest, const V& weight = V()) {
        source_ = source;
        dest_ = dest;
        weight_ = weight;
    }

    /**
     * Gets edge weight.
     */
    V getEdgeWeight() const {
        return this->weight_;
    }

    K source_;
    K dest_;
    V weight_;
};