
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
        auto & map = vertices_[v];
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
    // if v1, v2 are identical
    if (v1 == v2)
        return false;

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
        return V();

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

// time complexity is O(n^3), which is too large
// Thus when using, desploy a small sample to indicate the population, 
// rather than apply to the large population directly
template<typename K, typename V>
unsigned Graph<K, V>::BetweenessCentrality(const K& v) const {
    // initialize the res to be 0
    unsigned res=0;
    // traverse all pairs of vertices in the graph, and find shortest path between the two
    for (auto src=vertices_.begin();src!=vertices_.end();++src){
        for (auto dest=vertices_.begin();dest!=vertices_.end();++dest){
            // if the src or the dest is v itself or
            // if these two vertices are the same vertices
            if ((*src).first==v || (*dest).first==v ||
                (*src).first==(*dest).first) continue;
            // compute the shortest path between the src and dest vertices
            vector<K> v_path=shortestPath((*src).first,(*dest).first);
            // check if the target vertice exists in the shortest path, increase the res
            if(std::find(v_path.begin(),v_path.end(),v)!=v_path.end()) res++;
        }
    }
    return res;
}

// Implemented based on shortestDis.
// Starting at the destination, examine all nodes with edges going to it. Pick the node adjacent to the destination with the lowest min(distance + edge.weight) to the destination node. If the adjacent node is not in the min distance map, ignore it. This is the new destination. Repeat until the destination is the source.
template<typename K, typename V>
vector<K> Graph<K, V>::shortestPath(K v1, K v2) const {
    std::set<pair<int, K>> Q;
    Q.insert({0, v1});
    vector<int> shortest_dis(vertices_.size(), INT_MAX);
    shortest_dis[v1] = 0;

    while (!Q.empty()) {
        K idx = Q.begin()->second;
        if (idx == v2) {
            vector<K> shortest_path{idx}; // a vector to store the path
            while (idx != v1) {
                K next = idx;
                for (auto e: vertices_[idx]) {
                    if (shortest_dis[e.dest_] == INT_MAX)
                        continue;
                    if (shortest_dis[idx] != shortest_dis[e.dest_] + e.weight_)
                        continue;
                    next = e.dest_;
                    shortest_path.push_back(next);
                    break;
                }
                if (idx == next)
                    break;
                idx = next;
            }
            std::reverse(shortest_path.begin(), shortest_path.end());
            return shortest_path;
        }
        Q.erase(Q.begin());
        for (auto e: vertices_[idx]) {
            if (shortest_dis[e.dest_] > shortest_dis[idx] + e.weight_) {
                Q.erase({shortest_dis[e.dest_], e.dist_});
                shortest_dis[e.dest_] = shortest_dis[idx] + e.weight_;
                Q.insert({shortest_dis[e.dest_], e.dist_});
            }
        }
    }
    return vector<K> {};
}

// Dijkstra's algorithm using a priority queue
// https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
template<typename K, typename V>
V Graph<K, V>::shortestDis(K v1, K v2) const {
    std::set<pair<int, K>> Q; // a set to store the priority queue
    Q.insert({0, v1});
    vector<V> shortest_dis(vertices_.size(), INT_MAX);
    shortest_dis[v1] = 0;

    while (!Q.empty()) {
        K idx = Q.begin()->second;
        if (idx == v2) {
            return shortest_dis[idx];
        }
        Q.erase(Q.begin());
        for (auto e: vertices_[idx]) {
            if (shortest_dis[e.dest_] > shortest_dis[idx] + e.weight_) {
                Q.erase({shortest_dis[e.dest_], e.dist_});
                shortest_dis[e.dest_] = shortest_dis[idx] + e.weight_;
                Q.insert({shortest_dis[e.dest_], e.dist_});
            }
        }
    }
    return V();
}


template<typename K, typename V>
bool Graph<K, V>::ifConnected(K v1, K v2) const {
    // if two vertices are the same, connected
    if(v1==v2) return true;

    // initiate the visited vector and vertice queue
    unordered_map<K,bool> visited;
    for (auto it=vertices_.begin();it!=vertices_.end();++it){
        visited[(*it).first]=false;
    } 
    queue<K> queue;
    // push the starting vertice into the queue
    queue.push(v1);
    visited[v1]=true;

    while(!queue.empty()){
        // cur node is the front of the queu
        K cur=queue.front();
        queue.pop();

        // for every adjacent vertice in the adjacency list
        for (auto it=vertices_[cur].begin();it!=vertices_[cur].end();++it){
            K neighbor=(*it).first;
            if(neighbor==v2) return true;
            if(!visited[neighbor]){
                queue.push(neighbor);
                visited[neighbor]=true;
            }
        }
    }
    // all vertices on path are visited, not match v2
    // thus not connected
    return false;
}

template<typename K, typename V>
unsigned Graph<K, V>::verticesSize() {
    return vertices_.size();
}


