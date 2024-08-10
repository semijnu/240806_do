#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int n;                                 // 트리의 노드 개수
vector<pair<int, int>> tree[MAX];      // 트리 정보를 담는 벡터
bool check[MAX];                       // 방문 했는지 확인하는 배열

int getMaxCost(int start, int end) {
    // 여기에 코드를 작성하세요.
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