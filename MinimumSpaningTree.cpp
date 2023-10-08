#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

void Prim() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});
    int total = 0;
    while (!pq.empty()) {
        std::pair<int, int> current = pq.top();
        pq.pop();
        int u = current.second;
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        total += current.first;
        for (std::pair<int, int> v : graph[u]) {
            if (!visited[v.first]) {
                pq.push({v.second, v.first});
            }
        }
    }
    std::cout << total << std::endl;
}

void Krustal() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, std::pair<int, int>>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    std::sort(edges.begin(), edges.end());
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int total = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if (parent[u] != parent[v]) {
            total += w;
            int old_parent = parent[v];
            for (int j = 0; j < n; ++j) {
                if (parent[j] == old_parent) {
                    parent[j] = parent[u];
                }
            }
        }
    }
    std::cout << total << std::endl;
}

// https://www.youtube.com/watch?v=KbFlZYCpONw
void unionFind() {
    int size;
    std::vector<int> sz;
    std::vector<int> id;
    int numComponents;

}

int main() {
    return 0;
}
