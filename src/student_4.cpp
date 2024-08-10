#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    Trie* next[26];
    bool finish;
public:
    Trie();
    ~Trie();
    void insert(string word);
    bool search(string word);
};

void insert(Trie* root, string word);

bool search(Trie* root, string word);

int main() {
    int N;
    cin >> N;
    Trie* root = new Trie();
    for(int i=0; i<N; i++) {
        string word;
        cin >> word;
        insert(root, word);
    }
    string K;
    cin >> K;
    bool result = search(root, K);
    if(result) cout << "있습니다";
    else cout << "없습니다";
    return 0;
}