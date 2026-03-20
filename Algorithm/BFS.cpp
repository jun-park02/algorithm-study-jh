#include <iostream>
#include <vector>
#include <queue>

std::vector<int>* graph;
std::queue<int> queue;
bool* visited;

void BFS(int v) {
    queue.push(v);
    visited[v] = true;

    while(!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        std::cout << cur << " ";

        for (int next : graph[cur]) {
            if (!visited[next]) {
                queue.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void) {
    // 정점, 간선, 시작 노드
    int N, M, V;
    std::cin >> N >> M >> V;

    graph = new std::vector<int>[N + 1];
    visited = new bool[N + 1];
    std::fill(visited, visited + N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BFS(V);

    delete[] graph;
    delete[] visited;

    return 0;
}