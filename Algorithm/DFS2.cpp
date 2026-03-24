#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int>* graph;
std::stack<int> stack;
char* visited;

void dfs(int v) {
    stack.push(v);
    visited[v] = true;
    std::cout << v << " ";

    while(!stack.empty()) {
        int cur = stack.top();
        bool found = false;

        for (int next : graph[cur]) {
            if (!visited[next]) {
                stack.push(next);
                visited[next] = true;
                std::cout << next << " ";
                found = true;
                break;
            }
        }

        if (!found) {
            stack.pop();
        }
    }

    std::cout << std::endl;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 정점, 간선, 시작 노드
    int N, M, V;
    std::cin >> N >> M >> V;

    graph = new std::vector<int>[N + 1];
    visited = new char[N + 1];

    std::fill(visited, visited + N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(V);

    delete[] graph;
    delete[] visited;

    return 0;
}