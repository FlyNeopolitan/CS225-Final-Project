
//constructors

template<class K, class V>
Graph<K, V>::Graph() {
    //seems nothing here
}

template<typename K, typename V>
Graph<K, V>::Graph(const std::initializer_list<K> VertexList) {
    //insert the vertecies in the VertexList into the adjacent list
    vector<K> names(VertexList);
    for (const auto& name : names) {
        vertices_[name] = unordered_map<K, Edge<K, V>>();
    }
}

template<typename K, typename V>
Graph<K, V>::Graph(const std::vector<K> VertexVector) {
    for (const auto& name : VertexVector) {
        vertices_[name] = unordered_map<K, Edge<K, V>>();
    }
}

//vertex-related implementation

template<typename K, typename V>
void Graph<K, V>::insertVertex(const K& v) {
    if (vertexExists(v))
        return;

    vertices_[v] = unordered_map<K, Edge<K, V>>();
}


template<typename K, typename V>
bool Graph<K, V>::removeVertex(const K& v) {
    if (vertices_.find(v) != vertices_.end()) {
        vertices_.erase(v);
        for (auto it = vertices_.begin(); it != vertices_.end(); it++) {
            Vertex u = it->first;
            if (it->second.find(v) != it->second.end())
                it->second.erase(v);
        }
        return true;
    }
    return false;
}


template<typename K, typename V>
vector<K> Graph<K, V>::getAdjacent(const K& v) const{
    auto lookup = vertices_.find(v);

    if (lookup == vertices_.end())
        return vector<K>();
    else {
        vector<K> vertex_list;
        //unordered_map<Vertex, Edge<K, V>> & map = vertices_[v];
        auto& map = vertices_[v];
        for (auto it = map.begin(); it != map.end(); it++)
            vertex_list.push_back(it->first);

        return vertex_list;
    }
}


template<typename K, typename V>
bool Graph<K, V>::vertexExists(const K& v) const {
    if (vertices_.find(v) == vertices_.end())
        return false;

    return true;
}

//edge-related implementation

template<typename K, typename V>
bool Graph<K, V>::insertEdge(const K& v1, const K& v2, const V& weight) {
    // if the edge already exists
    if (vertices_.find(v1) != vertices_.end() && vertices_[v1].find(v2) != vertices_[v1].end())
        return false;

    if (vertices_.find(v1) == vertices_.end())
        vertices_[v1] = unordered_map<K, Edge<K, V>>();

    vertices_[v1][v2] = Edge<K, V>(v1, v2, weight);
    return true;
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
    if (!vertexExists(v1))
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
vector<K> Graph<K, V>::shortestPath(K v1, K v2) const {
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

template<typename K, typename V>
unsigned Graph<K, V>::verticesSize() {
    return vertices_.size();
}


