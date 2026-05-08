#include <iostream>
#include <vector>

std::vector<int>* graph; 
bool* visited;

void DFS(int start) {
	visited[start] = true;
	std::cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int current = graph[start][i];
		if (!visited[current])
			DFS(current);
	}
}

int main(void) {
	// 노드개수, 간선개수, 시작점
	int n, m, start;
	std::cin >> n >> m >> start;

	graph = new std::vector<int>[n + 1];
	visited = new bool[n + 1];

	std::fill(visited, visited + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(start);

	delete[] graph;
	delete[] visited;
 
	return 0;
}