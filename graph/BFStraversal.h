#include "graphIterator.h" 

template<typename K, typename V>
class BFStraversal : GraphTraversal<K> {

public:

    BFStraversal(Graph<K, V> graph);

    typename GraphTraversal<K>::Iterator begin();

    typename GraphTraversal<K>::Iterator end();

    void add(K currentVertex);

    K pop();

    K peek() const;

    bool empty() const;

private:

};