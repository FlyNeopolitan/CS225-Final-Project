#include "graphIterator.h" 

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