#include <iostream>
#include <vector>

using namespace std;

#define MAX_VERTICES 100

class Vertex {
public:
    int id;
    int count;
    vector<int> neighbor;

    Vertex() : id(-1), count(0) {}
};

class Graph {
public:
    vector<Vertex> vertices;
    int count;

    Graph() : count(0) {
        vertices.resize(MAX_VERTICES);
    }
};

void addNeighbor(Vertex &v, int idx, int idy) {
    v.id = idx;
    v.neighbor.push_back(idy);
    v.count++;
}

int getIndex(const Graph &g, int id) {
    for (int i = 0; i < g.count; i++) {
        if (g.vertices[i].id == id) return i;
    }
    return -1;
}

void addEdge(Graph &g, int u, int v) {
    int u_index = getIndex(g, u);
    int v_index = getIndex(g, v);
    if (u_index == -1) {
        u_index = g.count++;
        g.vertices[u_index].id = u;
    }
    addNeighbor(g.vertices[u_index], u, v);

    if (v_index == -1) {
        v_index = g.count++;
        g.vertices[v_index].id = v;
    }
    addNeighbor(g.vertices[v_index], v, u);
}

bool contains(const vector<int> &path, int node) {
    for (int elem : path) {
        if (elem == node) {
            return true;
        }
    }
    return false;
}

void findAllPaths(Graph &g, int start, int end, vector<int> &path, vector<vector<int>> &allPaths) {
    path.push_back(start);
    if (start == end) {
        allPaths.push_back(path);
        return;
    }
    int start_index = getIndex(g, start);
    for (int node : g.vertices[start_index].neighbor) {
        if (!contains(path, node)) {
            findAllPaths(g, node, end, path, allPaths);
            path.pop_back();
        }
    }
}

void getMaxPath(const vector<vector<int>> &allPaths, vector<int> &maxPath) {
    int maxLength = 0;
    int maxPoint = 0;
    for (const auto &path : allPaths) {
        int length = path.size();
        int sum = 0;
        for (int node : path) {
            sum += node;
        }
        if (maxLength < length || (maxLength == length && maxPoint < sum)) {
            maxLength = length;
            maxPoint = sum;
            maxPath = path;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph my_graph;
    for (int i = 0; i < m; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        addEdge(my_graph, x1, x2);
    }
    int start_n, end_n;
    cin >> start_n >> end_n;

    vector<int> path;
    vector<vector<int>> allPaths;
    findAllPaths(my_graph, start_n, end_n, path, allPaths);

    vector<int> maxPath;
    getMaxPath(allPaths, maxPath);

    for (size_t i = 0; i < maxPath.size(); i++) {
        if (i > 0) cout << " ";
        cout << maxPath[i];
    }
    cout << endl;

    return 0;
}
