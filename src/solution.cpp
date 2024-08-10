#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int n;                                  
vector<pair<int, int>> tree[MAX];
bool check[MAX];
int maximum = 0;

void dfs(int node, int cost, int end) {
    if(node == end) {
        if(maximum < cost){
            maximum = cost;
        }
        return;
    }
    check[node] = true;
    for(int i=0; i<tree[node].size(); i++) {
        int next = tree[node][i].first;
        if(!check[next]){
            dfs(next, cost + tree[node][i].second, end);
        }
    }
}

int getMaxCost(int start, int end) {
    dfs(start, 0, end);
    return maximum;
}

int main() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int node, adjacent, cost;
        cin >> node >> adjacent >> cost;
        tree[node].push_back(make_pair(adjacent, cost));
        tree[adjacent].push_back(make_pair(node, cost));
    }
    int start, end;
    cin >> start >> end;
    cout << getMaxCost(start, end);
}