#pragma once

template<typename K, typename V>
class Edge {

public:

    Edge(const K& source, const K& dest, V weight = V()) {
        source_ = source;
        dest_ = dest;
        weight_ = weight;
    }

    K source_;
    K dest_;
    V weight_;
};