#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> distance;

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (int i : graph[current]) {
            if (!visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    // n: number of nodes, m: number of edges
    int n, m, u, v, t1, t2;
    
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);
    distance.resize(n, -1);
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> t1 >> t2; // nodes to find shortest path between
    
    bfs(t1);
    
    cout << distance[t2] << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    
    return 0;
}