#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int>* graph;
int* visited;
std::stack<int> stack;
std::vector<int> result;

int main(void) {
    int node;
    std::cout << "노드의 개수 : ";
    std::cin >> node;

    graph = new std::vector<int>[node + 1];
    visited = new int[node + 1];
    std::fill(visited, visited + node + 1, 0);

    int edge;
    std::cout << "간선의 개수 : ";
    std::cin >> edge;

    for (int i = 0; i < edge; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= node; i++) {
        std::sort(graph[i].begin(), graph[i].end());
    }

    int start;
    std::cout << "시작 노드 : ";
    std::cin >> start;

    visited[start] = 1;
    stack.push(start);
    result.push_back(start);

    while(!stack.empty()) {
        int cur = stack.top();
        bool moved = false;

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = 1;
                stack.push(next);
                result.push_back(next);
                moved = true;
                break;
            }
        }

        if (!moved) stack.pop();
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    delete[] graph;
    delete[] visited;

    return 0;
}
